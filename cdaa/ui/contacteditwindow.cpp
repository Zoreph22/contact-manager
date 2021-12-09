#include "contacteditwindow.h"
#include "ui_contacteditwindow.h"

ContactEditWindow::ContactEditWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContactEditWindow)
{
    ui->setupUi(this);
}

ContactEditWindow::~ContactEditWindow()
{
    delete ui;
}

void ContactEditWindow::on_pushButton_6_clicked()
{

}


void ContactEditWindow::on_pushButton_5_clicked()
{

}


void ContactEditWindow::on_buttonAnnuler_clicked()
{

}


void ContactEditWindow::on_buttonCreateInteraction_clicked()
{

}

