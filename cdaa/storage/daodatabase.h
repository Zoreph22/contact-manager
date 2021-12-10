#ifndef DAODATABASE_H
#define DAODATABASE_H

#include "storage_global.h"

#include <QtSql/QtSql>

class STORAGE_EXPORT DaoDatabase
{
public:
    virtual ~DaoDatabase() = 0;

    static void openSQLite(const QString & path);
    static void close();

    static QSqlDatabase &getDatabase();
    static void setDatabase(const QSqlDatabase &newDatabase);

private:
    static QSqlDatabase database;
};

#endif // DAODATABASE_H
