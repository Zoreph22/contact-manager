#ifndef INTERACTIONMODEL_H
#define INTERACTIONMODEL_H

#include "todomodel.h"
#include <list>

using namespace std;
class InteractionModel
{
private:
    unsigned int id;
    string commentaire;
    string contenu;
    Date *dateInteraction;
    list<TodoModel> *todos;

public:
    InteractionModel(unsigned int id);
    unsigned int getId() const;
    const string &getCommentaire() const;
    void setCommentaire(const string &newCommentaire);
    const string &getContenu() const;
    void setContenu(const string &newContenu);
    Date *getDateInteraction() const;
    void setDateInteraction(Date *newDateInteraction);
    list<TodoModel> *getTodos() const;
    void setTodos(list<TodoModel> *newTodos);
};

#endif // INTERACTIONMODEL_H
