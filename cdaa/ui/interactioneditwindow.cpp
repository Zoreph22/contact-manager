#include "interactioneditwindow.h"
#include "ui_interactioneditwindow.h"

InteractionEditWindow::InteractionEditWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InteractionEditWindow)
{
    ui->setupUi(this);
}

InteractionEditWindow::~InteractionEditWindow()
{
    delete ui;
}

void InteractionEditWindow::on_pushButton_3_clicked()
{

}


void InteractionEditWindow::on_buttonEnregistrer_clicked()
{

}


void InteractionEditWindow::on_buttonAnnuler_clicked()
{

}

