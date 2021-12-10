#include "contacteditwindow.h"
#include "interactioneditwindow.h"
#include "mainwindow.h"
#include "requetewindow.h"

#include <QApplication>
#include <daodatabase.h>
#include <idaocontact.h>
#include <sqlitedaocontact.h>
#include <sqlitedaogeneral.h>
#include <sqlitedaointeraction.h>
#include <sqlitedaotodo.h>
#include <stdqt.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    return a.exec();
}
