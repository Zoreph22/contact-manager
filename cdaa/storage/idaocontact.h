#ifndef IDAOCONTACT_H
#define IDAOCONTACT_H

#include "storage_global.h"

#include <contactcollection.h>
#include <contactmodel.h>

class STORAGE_EXPORT IDaoContact
{
public:
    virtual ~IDaoContact() {};

    virtual void create(const ContactModel & contact) const = 0;
    virtual ContactCollection readAll() const = 0;
    virtual void update(const ContactModel & contact) const = 0;
    virtual void destroy(unsigned int id) const = 0;
    virtual void destroyAll() const = 0;
};

#endif // IDAOCONTACT_H
