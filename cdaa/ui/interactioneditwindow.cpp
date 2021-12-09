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
