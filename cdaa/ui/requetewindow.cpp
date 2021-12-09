#include "requetewindow.h"
#include "ui_requetewindow.h"

RequeteWindow::RequeteWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RequeteWindow)
{
    ui->setupUi(this);
    ui->frameFiltresTodo->setVisible(false);
}

RequeteWindow::~RequeteWindow()
{
    delete ui;
}
