#ifndef TODOMODEL_H
#define TODOMODEL_H
#include "date.h"
#include <iostream>

using namespace std;
class TodoModel
{
private:
    unsigned int id;
    Date *dateTodo;
    string resume;

public:
    TodoModel(unsigned int id);
    unsigned int getId() const;
    const string &getResume() const;
    void setResume(const string &newResume);
    Date *getDateTodo() const;
    void setDateTodo(Date *newDateTodo);
};

#endif // TODOMODEL_H
