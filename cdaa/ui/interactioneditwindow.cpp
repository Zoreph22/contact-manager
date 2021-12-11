#include "interactioneditwindow.h"
#include "ui_interactioneditwindow.h"
#include "stdqt.h"
#include <QMessageBox>
#include <QDebug>

#include <interactionmodel.h>

InteractionEditWindow::InteractionEditWindow(InteractionModel &im, bool isEdit,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InteractionEditWindow),
    im(im),
    isEdit(isEdit)
{
    this->setWindowFlags(Qt::Window);
    this->ui->setupUi(this);

    if(!isEdit){
        this->ui->buttonSupprimer->setVisible(false);
    }

    this->ui->textEdit->setText(StdQt::string(isEdit ? im.getContenu() : ""));

    this->ui->labelDateCreation->setText("Date de création : " + StdQt::string(im.getDateInteraction().toString()));
}

InteractionEditWindow::~InteractionEditWindow()
{
    delete ui;
}

void InteractionEditWindow::on_buttonEnregistrer_clicked()
{
    try {
        im.setContenu(StdQt::string(this->ui->textEdit->toPlainText()));
        im.parseTodos();
        this->done(1);
    }  catch (std::exception & e) {
        QMessageBox::warning(this, "Avertissement", e.what());
    }
}


void InteractionEditWindow::on_buttonAnnuler_clicked()
{
    this->done(0);
}


void InteractionEditWindow::on_buttonSupprimer_clicked()
{
    QMessageBox::StandardButton button = QMessageBox::question(this, "Question", "Voulez-vous vraiment supprimer cette interaction ?");
    if(QMessageBox::Yes == button)
        this->done(2);
}

