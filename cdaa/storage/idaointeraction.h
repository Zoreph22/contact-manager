#ifndef IDAOINTERACTION_H
#define IDAOINTERACTION_H

#include "storage_global.h"

#include <interactioncollection.h>
#include <interactionmodel.h>

class STORAGE_EXPORT IDaoInteraction
{
public:
    virtual ~IDaoInteraction() {};

    virtual unsigned int readMaxId() const = 0;

    virtual void create(unsigned int contactId, const InteractionModel & interaction) const = 0;
    virtual InteractionCollection readAll(unsigned int contactId) const = 0;
    virtual void update(const InteractionModel & interaction) const = 0;
    virtual void destroy(unsigned int id) const = 0;
};

#endif // IDAOINTERACTION_H
