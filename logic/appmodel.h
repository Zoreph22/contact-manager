#ifndef APPMODEL_H
#define APPMODEL_H

#include "date.h"

class AppModel
{
private:
    Date *dateSuppression = nullptr;
public:
    AppModel();
    Date *getDateSuppression() const;
    void setDateSuppression(Date *newDateSuppression);
};

#endif // APPMODEL_H
