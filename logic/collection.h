#ifndef COLLECTION_H
#define COLLECTION_H

#include <list>

using namespace std;

template<class T>
/**
 * @brief Classe collection pour gérer une liste d'instances d'une classe T.
 * @tparam T Classe à lister.
 */
class Collection
{
private:
    /// Liste des instances.
    list<T> liste;

public:
    /// Ajouter une instance à la liste.
    void add(const T &instance);
    /// Supprimer une instance de la liste.
    void remove(const T &instance);
    /// Vider la liste.
    void clear();

    /// Retourner le nombre d'instances dans la liste.
    unsigned int count() const;

    bool operator==(const Collection<T> &collection) const;
    bool operator!=(const Collection<T> &collection) const;

    /// Retourner la liste.
    const list<T> &getList() const;
};

#include "collection_impl.h"



#endif // COLLECTION_H
