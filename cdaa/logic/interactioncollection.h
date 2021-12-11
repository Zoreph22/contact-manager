#ifndef INTERACTIONCOLLECTION_H
#define INTERACTIONCOLLECTION_H

#include "collection.h"
#include "interactionmodel.h"

using namespace std;

/// Classe collection de @link InteractionModel @endlink.
class InteractionCollection : public Collection<InteractionModel>
{
public:
    InteractionModel &getById(unsigned int id) const;
    InteractionCollection &filterId(unsigned int id);
    InteractionCollection &filterDateCreation(const Date & date);
    InteractionCollection &filterDateCreation(const Date & dateMin, const Date & dateMax);
    TodoCollection getTodos() const;
};

#endif // INTERACTIONCOLLECTION_H
