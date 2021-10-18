#include "todomodel.h"

unsigned int TodoModel::getId() const
{
    return id;
}

const string &TodoModel::getResume() const
{
    return resume;
}

void TodoModel::setResume(const string &newResume)
{
    resume = newResume;
}

Date *TodoModel::getDateTodo() const
{
    return dateTodo;
}

void TodoModel::setDateTodo(Date *newDateTodo)
{
    dateTodo = newDateTodo;
}

TodoModel::TodoModel(unsigned int id)
{
    this->id = id;
    this->dateTodo = new Date();
}
