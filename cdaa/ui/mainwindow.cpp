#include "contacteditwindow.h"
#include "mainwindow.h"
#include "requetewindow.h"
#include "ui_mainwindow.h"

#include <daodatabase.h>
#include <stdqt.h>
#include <sqlitedaocontact.h>
#include <sqlitedaogeneral.h>
#include <sqlitedaointeraction.h>
#include <sqlitedaotodo.h>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->ui->setupUi(this);
    this->ui->frameFilter->setVisible(false);
    this->ui->dateEditMin->setDate(QDate::currentDate());
    this->ui->dateEditMax->setDate(QDate::currentDate());

    this->init();
    this->statutBar();
    this->refreshFilteredContact();
    this->refreshTable();

    connect(this->ui->tableWidget, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(on_itemDoubleClicked(QTableWidgetItem*)));
}

MainWindow::~MainWindow()
{
    delete this->ui;

    delete this->daoContact;
    delete this->daoGeneral;
    delete this->daoInteraction;
    delete this->daoTodo;
}

void MainWindow::init()
{
    DaoDatabase::openSQLite("../../database/database.db"); // TODO : changer ceci.

    this->daoContact = new SQLiteDaoContact();
    this->daoInteraction = new SQLiteDaoInteraction();
    this->daoTodo = new SQLiteDaoTodo();
    this->daoGeneral = new SQLiteDaoGeneral();

    this->loadData();
}

void MainWindow::loadData()
{
    ContactModel::idCount = this->daoContact->readMaxId();
    InteractionModel::idCount = this->daoInteraction->readMaxId();
    TodoModel::idCount = this->daoTodo->readMaxId();
    ContactModel::setDateSuppression(StdQt::date(this->daoGeneral->read("dateSuppression")));

    this->contacts.replace(daoContact->readAll());

    for (ContactModel & contact : this->contacts.getList())
    {
        contact.getInteractions().replace(daoInteraction->readAll(contact.getId()));

        for (InteractionModel & interaction : contact.getInteractions().getList())
        {
            interaction.getTodos().replace(daoTodo->readAll(interaction.getId()));
        }
    }

    // TODO : enlever les logs ci-dessous.
    for (ContactModel & contact : this->contacts.getList())
    {
        std::cout << contact << std::endl;

        for (InteractionModel & interaction : contact.getInteractions().getList())
        {
            std::cout << interaction << std::endl;

            for (TodoModel & todo : interaction.getTodos().getList())
            {
                std::cout << todo << std::endl;
            }
        }
    }
}

void MainWindow::refreshTable()
{
    this->refreshFilteredContact();
    this->ui->tableWidget->setRowCount(0);
    unsigned int nbC = this->contactsFiltered.count();

    QString nbLabelContactCount;
    nbLabelContactCount.setNum(this->contacts.count());
    this->nbContact->setText("Nombre de contact : " + nbLabelContactCount);

    Date dLastSuppr = ContactModel::getDateSuppression();
    QString sLastModif = !dLastSuppr.isNull() ? StdQt::string(dLastSuppr.toString()) : "Pas de suppression récente";
    this->lastModif->setText("Dernière suppression : " + sLastModif + "\t");

    QString s;
    s.setNum(nbC);
    this->ui->labelResult->setText("Résultat(s) : " + s);

    for(unsigned int i=0;i<nbC;i++){
        ContactModel & c = this->contactsFiltered.getIndex(i);

        QTableWidgetItem * prenom = new QTableWidgetItem(StdQt::string(c.getPrenom()));
        prenom->setData(Qt::UserRole, QVariant(c.getId()));

        QTableWidgetItem * nom = new QTableWidgetItem(StdQt::string(c.getNom()));
        nom->setData(Qt::UserRole, QVariant(c.getId()));

        QTableWidgetItem * entreprise = new QTableWidgetItem(StdQt::string(c.getEntreprise()));
        entreprise->setData(Qt::UserRole, QVariant(c.getId()));

        QTableWidgetItem * datecreation = new QTableWidgetItem();
        datecreation->setData(Qt::DisplayRole, StdQt::string(c.getDateCreation().toString()));
        datecreation->setData(Qt::UserRole, QVariant(c.getId()));

        this->ui->tableWidget->insertRow(i);

        this->ui->tableWidget->setItem(i, 0, prenom);
        this->ui->tableWidget->setItem(i, 1, nom);
        this->ui->tableWidget->setItem(i, 2, entreprise);
        this->ui->tableWidget->setItem(i, 3, datecreation);
    }
}

void MainWindow::statutBar()
{
    lastModif = new QLabel();
    nbContact = new QLabel();
    this->ui->statusbar->addWidget(lastModif, 0);
    this->ui->statusbar->addWidget(nbContact, 0);
    lastModif->setText("Dernière suppression : XX/XX/XXXX");
    nbContact->setText("Nombre de contact :");
}

void MainWindow::refreshFilteredContact()
{
    this->contactsFiltered = contacts;
    Date dateMin;
    Date dateMax;
    string filterEntreprise;
    string filterNom;
    string filterPrenom;

    // Date Filter
    if (this->ui->checkBoxDateMin->isChecked()) dateMin = StdQt::date(this->ui->dateEditMin->date());
    if (this->ui->checkBoxDateMax->isChecked()) dateMax = StdQt::date(this->ui->dateEditMax->date());

    this->contactsFiltered.filterDateCreation(dateMin, dateMax);

    //Filter Entreprise
    if (!this->ui->lineEditFilterEntreprise->text().isEmpty()) filterEntreprise = StdQt::string(this->ui->lineEditFilterEntreprise->text());
    this->contactsFiltered.filterEntreprise(filterEntreprise);

    //Filter Nom
    if (!this->ui->lineEditFilterNom->text().isEmpty()) filterNom = StdQt::string(this->ui->lineEditFilterNom->text());
    this->contactsFiltered.filterNom(filterNom);

    //Filter Prenom
    if (!this->ui->lineEditFilterPrenom->text().isEmpty()) filterPrenom = StdQt::string(this->ui->lineEditFilterPrenom->text());
    this->contactsFiltered.filterPrenom(filterPrenom);
}

void MainWindow::on_itemDoubleClicked(QTableWidgetItem *item)
{
    unsigned int idContact = item->data(Qt::UserRole).toUInt();
    ContactModel & original = this->contacts.getById(idContact);
    ContactModel nouveau = original;
    ContactEditWindow editC(nouveau, true);
    int ret = editC.exec();
    if(ret == 2)
    {
        try {
            daoContact->destroy(original.getId());
            contacts.remove(original);
            //Set la date de dernière suppression
            Date dateSuppr;
            dateSuppr.setNow();
            daoGeneral->update("dateSuppression", QVariant(StdQt::date(dateSuppr)));
            ContactModel::setDateSuppression(dateSuppr);
            refreshTable();
        }  catch (std::runtime_error & e) {
            QMessageBox::critical(this, "Erreur", e.what());
        }

    }

    if(ret == 1)
    {
        try {
            daoContact->update(nouveau);
            original = nouveau;
            refreshTable();
        }  catch (std::runtime_error & e) {
            QMessageBox::critical(this, "Erreur", e.what());
        }
    }
}


void MainWindow::on_buttonOpenFilter_clicked()
{
    if(isFilterOpen){
        isFilterOpen = false;
        ui->frameFilter->setVisible(isFilterOpen);
    }
    else {
        isFilterOpen = true;
        ui->frameFilter->setVisible(isFilterOpen);
    }
}


void MainWindow::on_actionQuit_triggered()
{
    this->close();
}


void MainWindow::on_actionExportJson_triggered()
{
    QString chemin = QFileDialog::getSaveFileName(this, QString(), QString(), "JSON (*.json)");
    qDebug() << chemin;
}


void MainWindow::on_actionResetAll_triggered()
{
    QMessageBox::StandardButton button = QMessageBox::question(this, "Question", "Voulez-vous vraiment réinitialiser toutes les données ?");
    if(QMessageBox::Yes == button){
        try{
            daoContact->destroyAll();
            contacts.clear();
            Date d;
            daoGeneral->update("dateSuppression", QVariant(StdQt::date(d)));
            ContactModel::setDateSuppression(d);
            refreshTable();
        }  catch (std::exception & e) {
            QMessageBox::critical(this, "Erreur", e.what());
        }
    }
}


void MainWindow::on_buttonReset_clicked()
{
    this->ui->lineEditFilterEntreprise->setText("");
    this->ui->lineEditFilterNom->setText("");
    this->ui->lineEditFilterPrenom->setText("");
    this->ui->dateEditMin->setEnabled(false);
    this->ui->dateEditMax->setEnabled(false);
    this->ui->checkBoxDateMin->setChecked(false);
    this->ui->checkBoxDateMax->setChecked(false);
    this->refreshTable();
}


void MainWindow::on_buttonFiltrer_clicked()
{
    this->refreshFilteredContact();
    this->refreshTable();
}


void MainWindow::on_buttonRequest_clicked()
{
    RequeteWindow win(this->contacts);
    win.exec();
}


void MainWindow::on_ButtonCreateContact_clicked()
{
    ContactModel c;
    ContactEditWindow editC(c, false);
    int ret = editC.exec();
    if(ret == 1){
        try {
            daoContact->create(c);
            contacts.add(c);
            refreshTable();
        }  catch (std::runtime_error & e) {
            QMessageBox::critical(this, "Erreur", e.what());
        }
    }
}


void MainWindow::on_dateEditMin_userDateChanged(const QDate &date)
{

}


