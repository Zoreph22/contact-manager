#ifndef TODOCOLLECTION_H
#define TODOCOLLECTION_H

#include <iostream>
#include <list>
#include "todomodel.h"

using namespace std;

/// Classe collection de @link TodoModel @endlink.
class TodoCollection
{
private:
    /// Liste des todos.
    list<TodoModel> todos;

public:
    /// Ajouter un todo à la liste.
    void add(const TodoModel &todo);
    /// Supprimer un todo de la liste.
    void remove(const TodoModel &todo);
    /// Vider la liste.
    void clear();

    /// Retourner le nombre de todos dans la liste.
    unsigned int count() const;

    bool operator==(const TodoCollection &collection) const;
    bool operator!=(const TodoCollection &collection) const;

    /// Retourner la liste.
    const list<TodoModel> &getTodos() const;
};

#endif // TODOCOLLECTION_H
