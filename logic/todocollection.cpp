#include "todocollection.h"

void TodoCollection::add(const TodoModel &todo)
{
    this->todos.push_back(todo);
}

void TodoCollection::remove(const TodoModel &todo)
{
    this->todos.remove(todo);
}

void TodoCollection::clear()
{
    this->todos.clear();
}

unsigned int TodoCollection::count() const
{
    return this->todos.size();
}

bool TodoCollection::operator==(const TodoCollection &collection) const
{
    return this->todos == collection.todos;
}

bool TodoCollection::operator!=(const TodoCollection &collection) const
{
    return !this->operator==(collection);
}

const list<TodoModel> &TodoCollection::getTodos() const
{
    return this->todos;
}