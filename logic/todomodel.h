#ifndef TODOMODEL_H
#define TODOMODEL_H
#include "date.h"
#include <iostream>

using namespace std;
class TodoModel
{
private:
    const unsigned int id;
    const Date dateTodo;
    string resume;

public:
    TodoModel(const unsigned int id);
    TodoModel(const unsigned int id, const Date dateTodo);
    TodoModel(const TodoModel & todo);
    ~TodoModel();

    TodoModel &operator=(const TodoModel &todo);
    bool operator==(const TodoModel &todo) const;
    friend ostream &operator<<(ostream &out, const TodoModel &todo);


    unsigned int getId() const;
    const Date &getDateTodo() const;
    const string &getResume() const;
    void setResume(const string &newResume);
};

#endif // TODOMODEL_H
