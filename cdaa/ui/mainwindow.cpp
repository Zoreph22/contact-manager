#include "mainwindow.h"
#include "requetewindow.h"
#include "ui_mainwindow.h"

#include <daodatabase.h>
#include <stdqt.h>
#include <sqlitedaocontact.h>
#include <sqlitedaogeneral.h>
#include <sqlitedaointeraction.h>
#include <sqlitedaotodo.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->frameFilter->setVisible(false);

    this->init();
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

}


void MainWindow::on_actionResetAll_triggered()
{

}


void MainWindow::on_buttonReset_clicked()
{

}


void MainWindow::on_buttonFiltrer_clicked()
{

}


void MainWindow::on_buttonRequest_clicked()
{
    RequeteWindow win(this->contacts);
    win.exec();
}


void MainWindow::on_ButtonCreateContact_clicked()
{

}


void MainWindow::on_dateEditMin_userDateChanged(const QDate &date)
{

}

