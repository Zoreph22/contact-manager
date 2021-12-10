#ifndef IDAOTODO_H
#define IDAOTODO_H

#include "storage_global.h"

#include <todocollection.h>
#include <todomodel.h>

class STORAGE_EXPORT IDaoTodo
{
public:
    virtual ~IDaoTodo() {};

    virtual void create(unsigned int interactionId, const TodoModel & todo) const = 0;
    virtual TodoCollection readAll(unsigned int interactionId) const = 0;
    virtual void update(const TodoModel & todo) const = 0;
    virtual void destroy(unsigned int id) const = 0;
};

#endif // IDAOTODO_H
