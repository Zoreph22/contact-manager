#ifndef DAODATABASE_H
#define DAODATABASE_H

#include "imanagedatabase.h"
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

    static IManageDatabase const*getManager();

private:
    static QSqlDatabase database;
    static IManageDatabase * manager;
};

#endif // DAODATABASE_H
