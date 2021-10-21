#include "todocollection.h"

const list<TodoModel> &TodoCollection::getTodos() const
{
    return todos;
}

void TodoCollection::setTodos(const list<TodoModel> &newTodos)
{
    todos = newTodos;
}

TodoCollection::TodoCollection()
{

}

TodoCollection::~TodoCollection()
{

}

void TodoCollection::add(const TodoModel &todo)
{

}

void TodoCollection::remove(const TodoModel &todo)
{

}

void TodoCollection::clear()
{

}

unsigned int TodoCollection::count() const
{

}
