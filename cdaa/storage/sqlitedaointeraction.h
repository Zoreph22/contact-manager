#ifndef SQLITEDAOINTERACTION_H
#define SQLITEDAOINTERACTION_H

#include "storage_global.h"
#include "idaointeraction.h"

#include <QtSql/QtSql>

class STORAGE_EXPORT SQLiteDaoInteraction : public IDaoInteraction
{
public:
    ~SQLiteDaoInteraction();

    void create(unsigned int contactId, const InteractionModel &interaction) const;
    InteractionCollection readAll(unsigned int contactId) const;
    void update(const InteractionModel &interaction) const;
    void destroy(unsigned int id) const;
};

#endif // SQLITEDAOINTERACTION_H
