#include "interactionmodel.h"


InteractionModel::InteractionModel(const unsigned int id)
    : id(id)
{

}

InteractionModel::InteractionModel(const unsigned int id, const Date dateInteraction)
    : id(id)
    , dateInteraction(dateInteraction)
{

}

InteractionModel::InteractionModel(const InteractionModel &interaction)
    : id(interaction.id)
    , dateInteraction(interaction.dateInteraction)
{

}

InteractionModel::~InteractionModel()
{

}

void InteractionModel::parseTodos()
{

}

InteractionModel &InteractionModel::operator=(const InteractionModel &interaction)
{

}

bool InteractionModel::operator==(const InteractionModel &interaction) const
{

}

unsigned int InteractionModel::getId() const
{
    return id;
}

const Date &InteractionModel::getDateInteraction() const
{
    return dateInteraction;
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

const list<TodoModel> &InteractionModel::getTodos() const
{
    return todos;
}

void InteractionModel::setTodos(const list<TodoModel> &newTodos)
{
    todos = newTodos;
}
