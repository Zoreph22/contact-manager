#include "daodatabase.h"

QSqlDatabase DaoDatabase::database;

void DaoDatabase::openSQLite(const QString &path)
{
    DaoDatabase::close();

    DaoDatabase::database = QSqlDatabase::addDatabase("QSQLITE");
    DaoDatabase::database.setDatabaseName(path); // TODO : changer ceci.

    if (!DaoDatabase::database.open())
    {
        throw std::runtime_error("Impossible d'ouvrir la base de données SQLite : " + DaoDatabase::database.lastError().text().toStdString());
    }

    DaoDatabase::database.exec("PRAGMA foreign_keys = ON");
}

void DaoDatabase::close()
{
    DaoDatabase::database.close();
}

QSqlDatabase &DaoDatabase::getDatabase()
{
    return DaoDatabase::database;
}

void DaoDatabase::setDatabase(const QSqlDatabase &newDatabase)
{
    DaoDatabase::close();
    DaoDatabase::database = newDatabase;
}
