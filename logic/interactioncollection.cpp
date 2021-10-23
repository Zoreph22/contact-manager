#include "interactioncollection.h"

void InteractionCollection::add(const InteractionModel &interaction)
{
    this->interactions.push_back(interaction);
}

void InteractionCollection::remove(const InteractionModel &interaction)
{
    this->interactions.remove(interaction);
}

void InteractionCollection::clear()
{
    this->interactions.clear();
}

unsigned int InteractionCollection::count() const
{
    return this->interactions.size();
}

bool InteractionCollection::operator==(const InteractionCollection &collection) const
{
    return this->interactions == collection.getInteractions();
}

bool InteractionCollection::operator!=(const InteractionCollection &collection) const
{
    return !this->operator==(collection);
}

const list<InteractionModel> &InteractionCollection::getInteractions() const
{
    return this->interactions;
}