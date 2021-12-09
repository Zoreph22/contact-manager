#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->frameFilter->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
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

}


void MainWindow::on_ButtonCreateContact_clicked()
{

}


void MainWindow::on_dateEditMin_userDateChanged(const QDate &date)
{

}

