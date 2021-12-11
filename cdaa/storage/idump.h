#ifndef IDUMP_H
#define IDUMP_H

#include "storage_global.h"

#include <QString>
#include <contactcollection.h>

class STORAGE_EXPORT IDump
{
protected:
    QString filePath;

public:
    IDump(QString filePath) : filePath(filePath) {};
    virtual ~IDump() {};
    virtual void dumpAll(const ContactCollection & contacts) const = 0;
};

#endif // IDUMP_H
