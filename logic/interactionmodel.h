#ifndef INTERACTIONMODEL_H
#define INTERACTIONMODEL_H

#include "todomodel.h"
#include <list>

using namespace std;
class InteractionModel
{
private:
    const unsigned int id;
    const Date dateInteraction;
    string commentaire;
    string contenu;
    list<TodoModel> todos;

public:
    InteractionModel(const unsigned int id);
    InteractionModel(const unsigned int id, const Date dateInteraction);
    InteractionModel(const InteractionModel & interaction);
    ~InteractionModel();
    void parseTodos();

    InteractionModel &operator=(const InteractionModel &interaction);
    bool operator==(const InteractionModel &interaction) const;
    friend ostream &operator<<(ostream &out, const InteractionModel &interaction);

    unsigned int getId() const;
    const Date &getDateInteraction() const;
    const string &getCommentaire() const;
    void setCommentaire(const string &newCommentaire);
    const string &getContenu() const;
    void setContenu(const string &newContenu);
    const list<TodoModel> &getTodos() const;
    void setTodos(const list<TodoModel> &newTodos);
};

#endif // INTERACTIONMODEL_H
