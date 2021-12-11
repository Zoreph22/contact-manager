#include "contacteditwindow.h"
#include "ui_contacteditwindow.h"
#include "stdqt.h"
#include "interactioneditwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <sqlitedaointeraction.h>
#include <QFileDialog>

ContactEditWindow::ContactEditWindow(ContactModel &cm, bool isEdit, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactEditWindow),
    cm(cm),
    isEdit(isEdit)
{
    this->setWindowFlags(Qt::Window);
    this->ui->setupUi(this);
    this->init();
    this->refreshInteractionAndTodosTable();

    ui->pushButton_5->setDisabled(cm.getNom().empty() || cm.getPrenom().empty());

    if(!isEdit){
        this->ui->pushButton_6->setVisible(false);
    }

    this->ui->lineEditPrenom->setText(StdQt::string(cm.getPrenom()));
    this->ui->lineEditNom->setText(StdQt::string(cm.getNom()));
    this->ui->lineEditEntreprise->setText(StdQt::string(cm.getEntreprise()));
    this->ui->lineEditTel->setText(StdQt::string(cm.getTel()));
    this->ui->lineEditEmail->setText(StdQt::string(cm.getEmail()));

    QString str = cm.getPhoto().empty() ? "../../database/profil.png" : StdQt::string(cm.getPhoto());
    this->ui->ButtonPhoto->setIcon(QIcon(str));
    this->ui->ButtonPhoto->setIconSize(QSize(64,64));

    this->ui->labelDateCreation->setText("Date de création : " + StdQt::string(cm.getDateCreation().toString()));

    Date dateModif = cm.getDateModification();
    QLabel * labelDM =  this->ui->labelDerniereModification;
    dateModif.isNull() ? labelDM->setVisible(false) : labelDM->setText("Dernière date de modification : " +StdQt::string(dateModif.toString()));

    connect(this->ui->tableWidgetInteraction, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(on_itemDoubleClicked(QTableWidgetItem*)));
}

ContactEditWindow::~ContactEditWindow()
{
    delete this->ui;
    delete this->daoInteraction;
}

void ContactEditWindow::on_pushButton_6_clicked()
{
    QMessageBox::StandardButton button = QMessageBox::question(this, "Question", "Voulez-vous vraiment supprimer ce contact ?");
    if(QMessageBox::Yes == button)
        this->done(2);
}


void ContactEditWindow::on_pushButton_5_clicked()
{
    try {
        if(isEdit){
            Date d;
            d.setNow();
            cm.setDateModification(d);
        }
        cm.setPrenom(StdQt::string(this->ui->lineEditPrenom->text()));
        cm.setNom(StdQt::string(this->ui->lineEditNom->text()));
        cm.setEntreprise(StdQt::string(this->ui->lineEditEntreprise->text()));
        cm.setEmail(StdQt::string(this->ui->lineEditEmail->text()));
        cm.setTel(StdQt::string(this->ui->lineEditTel->text()));
        this->done(1);
    }  catch (std::invalid_argument & e) {
        QMessageBox::warning(this, "Avertissement", e.what());
    }
}


void ContactEditWindow::on_buttonAnnuler_clicked()
{
    this->done(0);
}


void ContactEditWindow::on_buttonCreateInteraction_clicked()
{
    InteractionModel i("vide");
    InteractionEditWindow editI(i, false);
    int ret = editI.exec();
    if(ret == 1){
        try {
            daoInteraction->create(cm.getId(), i);
            i.parseTodos();
            cm.getInteractions().add(i);
            refreshInteractionAndTodosTable();
        }  catch (std::exception & e) {
            QMessageBox::critical(this, "Erreur", e.what());
        }
    }
}


void ContactEditWindow::on_lineEditPrenom_textChanged(const QString &arg1)
{
     ui->pushButton_5->setDisabled(this->ui->lineEditPrenom->text().isEmpty() || this->ui->lineEditNom->text().isEmpty());
}


void ContactEditWindow::on_lineEditNom_textChanged(const QString &arg1)
{
    ui->pushButton_5->setDisabled(this->ui->lineEditNom->text().isEmpty() || this->ui->lineEditPrenom->text().isEmpty());
}

void ContactEditWindow::on_itemDoubleClicked(QTableWidgetItem *item)
{
    unsigned int idInteraction = item->data(Qt::UserRole).toUInt();
    InteractionModel & original = this->cm.getInteractions().getIndex(idInteraction);
    InteractionModel nouveau = original;
    InteractionEditWindow editI(nouveau, true);
    int ret = editI.exec();
    if(ret == 2)
    {
        try {
            daoInteraction->destroy(original.getId());
            cm.getInteractions().remove(original);
            refreshInteractionAndTodosTable();
        }  catch (std::exception & e) {
            QMessageBox::critical(this, "Erreur", e.what());
        }

    }

    if(ret == 1)
    {
        try {
            daoInteraction->update(nouveau);
            original = nouveau;
            original.parseTodos();
            refreshInteractionAndTodosTable();
        }  catch (std::exception & e) {
            QMessageBox::critical(this, "Erreur", e.what());
        }
    }
}

void ContactEditWindow::refreshInteractionAndTodosTable()
{
    this->ui->tableWidgetInteraction->setRowCount(0);
    this->ui->tableWidgetTodos->setRowCount(0);

    unsigned nbI = this->cm.getInteractions().count();
    int curTodosIndexTable = 0;

    //INTERACTIONS TABLE
    for(unsigned int i=0;i<nbI;i++){
        InteractionModel & inte = this->cm.getInteractions().getIndex(i);

        QTableWidgetItem * dateInter = new QTableWidgetItem(StdQt::string(inte.getDateInteraction().toString()));
        dateInter->setData(Qt::UserRole, QVariant(i));

        QTableWidgetItem * contenu = new QTableWidgetItem(StdQt::string(inte.getContenu()));
        contenu->setData(Qt::UserRole, QVariant(i));

        this->ui->tableWidgetInteraction->insertRow(i);

        this->ui->tableWidgetInteraction->setItem(i, 0, dateInter);
        this->ui->tableWidgetInteraction->setItem(i, 1, contenu);

        //TODOS TABLE
        for(unsigned int j=0;j<inte.getTodos().count();j++){
            TodoModel & todo = inte.getTodos().getIndex(j);

            QTableWidgetItem * dateRea = new QTableWidgetItem(StdQt::string(todo.getDateTodo().toString()));
            dateRea->setData(Qt::UserRole, QVariant(curTodosIndexTable));

            QTableWidgetItem * tache = new QTableWidgetItem(StdQt::string(todo.getResume()));
            tache->setData(Qt::UserRole, QVariant(curTodosIndexTable));

            this->ui->tableWidgetTodos->insertRow(curTodosIndexTable);

            this->ui->tableWidgetTodos->setItem(curTodosIndexTable, 0, dateRea);
            this->ui->tableWidgetTodos->setItem(curTodosIndexTable, 1, tache);

            curTodosIndexTable++;
        }
    }
}

void ContactEditWindow::init()
{
    this->daoInteraction = new SQLiteDaoInteraction();
}


void ContactEditWindow::on_ButtonPhoto_clicked()
{
    //Load image
    QString chemin = QFileDialog::getOpenFileName(this, QString(), QString(), "Image (*.png *.jpg *.jpeg)");
    QImage img(chemin);
    QImage img2 = img.scaled(64,64, Qt::KeepAspectRatio);
    QPixmap pixmap =  QPixmap::fromImage(img2);
    this->ui->ButtonPhoto->setIcon(QIcon(pixmap));
    this->ui->ButtonPhoto->setIconSize(QSize(64,64));

    //Copy and save image
    QString destinationDir = "../../database";
    QFileInfo fileInfo(chemin);
    QString id;
    id.setNum(cm.getId());
    QString destinationFile = destinationDir + "/" +id + "." + fileInfo.suffix();
    QFile::remove(destinationFile);
    QFile::copy(chemin, destinationFile);

    qDebug() << destinationFile;

    cm.setPhoto(StdQt::string(destinationFile));
}
