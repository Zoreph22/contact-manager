#include "todomodel.h"


TodoModel::TodoModel(const unsigned int id)
    : id(id)
{

}

TodoModel::TodoModel(const unsigned int id, const Date dateTodo)
    : id(id)
    , dateTodo(dateTodo)
{

}

TodoModel::TodoModel(const TodoModel &todo)
    : id(todo.id)
    , dateTodo(todo.dateTodo)
{

}

TodoModel::~TodoModel()
{

}

TodoModel &TodoModel::operator=(const TodoModel &todo)
{

}

bool TodoModel::operator==(const TodoModel &todo) const
{

}

unsigned int TodoModel::getId() const
{
    return id;
}

const Date &TodoModel::getDateTodo() const
{
    return dateTodo;
}

const string &TodoModel::getResume() const
{
    return resume;
}

void TodoModel::setResume(const string &newResume)
{
    resume = newResume;
}
