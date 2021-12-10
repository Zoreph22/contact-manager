#ifndef SQLITEDAOTODO_H
#define SQLITEDAOTODO_H

#include "idaotodo.h"
#include "storage_global.h"

#include <QtSql/QtSql>

class STORAGE_EXPORT SQLiteDaoTodo : public IDaoTodo
{
public:
    ~SQLiteDaoTodo();

    void create(unsigned int interactionId, const TodoModel &todo) const;
    TodoCollection readAll(unsigned int interactionId) const;
    void update(const TodoModel &todo) const;
    void destroy(unsigned int id) const;
};

#endif // SQLITEDAOTODO_H
