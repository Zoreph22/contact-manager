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
