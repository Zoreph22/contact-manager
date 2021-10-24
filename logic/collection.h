#ifndef COLLECTION_H
#define COLLECTION_H

#include <list>
#include <ostream>

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
    mutable list<T> liste;

public:
    /// Ajouter une instance à la liste.
    void add(const T &instance);
    /// Supprimer une instance de la liste.
    void remove(const T &instance);
    /// Vider la liste.
    void clear();

    /**
     * @brief Retourner un élément par son index dans la liste.
     * @param index Index dans la liste.
     * @throw out_of_range Index en dehors de la liste.
     */
    T getIndex(unsigned int index) const;
    /// Retourner le nombre d'instances dans la liste.
    unsigned int count() const;

    /// Retourne @a true si les deux collections contiennent des instances égales.
    bool operator==(const Collection<T> &collection) const;
    /// Retourne @a true si les deux collections ne contiennent pas des instances égales.
    bool operator!=(const Collection<T> &collection) const;
    /// Retourne un flux sortant avec toutes les informations de chaque instance de la liste.
    friend ostream &operator<<(ostream &out, const Collection<T> &collection) {
        for (auto & it : collection.getList()) {
            out << it << endl
                << "------------------" << endl;
        }

        return out;
    }

    /// Retourner la liste.
    const list<T> &getList() const;
};

#include "collection_impl.h"



#endif // COLLECTION_H
