#include "mainwindow.h"
#include "requetewindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RequeteWindow w;
    w.show();
    return a.exec();
}
