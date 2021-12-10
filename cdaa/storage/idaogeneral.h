#ifndef IDAOGENERAL_H
#define IDAOGENERAL_H

#include "storage_global.h"

#include <QVariant>

class STORAGE_EXPORT IDaoGeneral
{
public:
    virtual ~IDaoGeneral() {};

    virtual void create(const QString & attribut, const QVariant & valeur) const = 0;
    virtual QVariant read(const QString & attribut) const = 0;
    virtual void update(const QString & attribut, const QVariant & valeur) const = 0;
    virtual void destroy(const QString & attribut) const = 0;
};

#endif // IDAOGENERAL_H
