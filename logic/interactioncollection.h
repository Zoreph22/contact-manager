#ifndef INTERACTIONCOLLECTION_H
#define INTERACTIONCOLLECTION_H

#include <list>
#include "interactionmodel.h"

using namespace std;

/// Classe collection de @link InteractionModel @endlink.
class InteractionCollection
{
public:
    /// Liste des interactions.
    list<InteractionModel> interactions;

public:
    /// Ajouter une interaction à la liste.
    void add(const InteractionModel &interaction);
    /// Supprimer une interaction de la liste.
    void remove(const InteractionModel &interaction);
    /// Vider la liste.
    void clear();

    /// Retourner le nombre d'interactions dans la liste.
    unsigned int count() const;

    bool operator==(const InteractionCollection &collection) const;
    bool operator!=(const InteractionCollection &collection) const;

    /// Retourner la liste.
    const list<InteractionModel> &getInteractions() const;
};

#endif // INTERACTIONCOLLECTION_H
