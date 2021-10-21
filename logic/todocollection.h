#ifndef TODOCOLLECTION_H
#define TODOCOLLECTION_H

#include <iostream>
#include <list>
#include "todomodel.h"

using namespace std;

class TodoCollection
{
private:
    list<TodoModel> todos;

public:
    TodoCollection();
    ~TodoCollection();
    void add(const TodoModel & todo);
    void remove(const TodoModel & todo);
    void clear();
    unsigned int count() const;
    const list<TodoModel> &getTodos() const;
    void setTodos(const list<TodoModel> &newTodos);
};

#endif // TODOCOLLECTION_H
