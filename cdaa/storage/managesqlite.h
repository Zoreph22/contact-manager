#ifndef MANAGESQLITE_H
#define MANAGESQLITE_H

#include "imanagedatabase.h"
#include "storage_global.h"

class STORAGE_EXPORT ManageSQLite : public IManageDatabase
{
public:
    void createTables() const;
    void createTableGeneral() const;
    void createTableContact() const;
    void createTableInteraction() const;
    void createTableTodo() const;
    void insertMockData() const;
};

#endif // MANAGESQLITE_H
