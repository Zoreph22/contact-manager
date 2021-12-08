#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QString>

#include "date.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Date d(22, 7, 2000);
    qDebug() << QString::fromStdString(d.toString());

    MainWindow w;
    w.show();
    return a.exec();
}
