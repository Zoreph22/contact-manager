#include "interactionmodel.h"

unsigned int InteractionModel::getId() const
{
    return id;
}

const string &InteractionModel::getCommentaire() const
{
    return commentaire;
}

void InteractionModel::setCommentaire(const string &newCommentaire)
{
    commentaire = newCommentaire;
}

const string &InteractionModel::getContenu() const
{
    return contenu;
}

void InteractionModel::setContenu(const string &newContenu)
{
    contenu = newContenu;
}

Date *InteractionModel::getDateInteraction() const
{
    return dateInteraction;
}

void InteractionModel::setDateInteraction(Date *newDateInteraction)
{
    dateInteraction = newDateInteraction;
}

list<TodoModel> *InteractionModel::getTodos() const
{
    return todos;
}

void InteractionModel::setTodos(list<TodoModel> *newTodos)
{
    todos = newTodos;
}

InteractionModel::InteractionModel(unsigned int id)
{
    this->id = id;
    this->dateInteraction = new Date();
    this->todos = new list<TodoModel>();
}
