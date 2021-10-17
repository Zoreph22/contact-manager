#ifndef INTERACTIONCOLLECTION_H
#define INTERACTIONCOLLECTION_H

#include "interactionmodel.h"
#include <list>

using namespace std;
class InteractionCollection
{
private:
    list<InteractionModel> *liste;
public:
    InteractionCollection();
    void add(const InteractionModel *i) const;
    void remove(const InteractionModel *i) const;
    list<InteractionModel> & getListe() const;
};

#endif // INTERACTIONCOLLECTION_H
