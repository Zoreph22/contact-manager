#include "interactioncollection.h"

InteractionCollection::InteractionCollection()
{
    this->liste = new list<InteractionModel>();
}

void InteractionCollection::add(const InteractionModel *i) const
{
    //this->liste->push_back(*i);
}

void InteractionCollection::remove(const InteractionModel *i) const
{
    //this->liste->remove(*i);
}

list<InteractionModel> &InteractionCollection::getListe() const
{
    return *this->liste;
}
