#ifndef IMANAGEDATABASE_H
#define IMANAGEDATABASE_H

#include "storage_global.h"

#include <QtSql/QtSql>

class STORAGE_EXPORT IManageDatabase
{
public:
    virtual ~IManageDatabase() {};
    virtual void createTables() const = 0;
    virtual void createTableGeneral() const = 0;
    virtual void createTableContact() const = 0;
    virtual void createTableInteraction() const = 0;
    virtual void createTableTodo() const = 0;
    virtual void insertMockData() const = 0;
};

#endif // IMANAGEDATABASE_H
