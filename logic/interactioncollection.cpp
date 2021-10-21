#include "interactioncollection.h"

const list<InteractionModel> &InteractionCollection::getInteractions() const
{
    return interactions;
}

void InteractionCollection::setInteractions(const list<InteractionModel> &newInteractions)
{
    interactions = newInteractions;
}

InteractionCollection::InteractionCollection()
{

}

InteractionCollection::~InteractionCollection()
{

}

void InteractionCollection::add(const InteractionModel &interaction)
{

}

void InteractionCollection::remove(const InteractionModel &interaction)
{

}

void InteractionCollection::clear()
{

}

unsigned int InteractionCollection::count() const
{

}
