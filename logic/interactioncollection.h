#ifndef INTERACTIONCOLLECTION_H
#define INTERACTIONCOLLECTION_H

#include "interactionmodel.h"
#include <list>

using namespace std;
class InteractionCollection
{
public:
    list<InteractionModel> interactions;

public:
    InteractionCollection();
    ~InteractionCollection();
    void add(const InteractionModel & interaction);
    void remove(const InteractionModel & interaction);
    void clear();
    unsigned int count() const;

    const list<InteractionModel> &getInteractions() const;
    void setInteractions(const list<InteractionModel> &newInteractions);
};

#endif // INTERACTIONCOLLECTION_H
