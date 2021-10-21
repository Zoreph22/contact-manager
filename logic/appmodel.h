#ifndef APPMODEL_H
#define APPMODEL_H

#include "date.h"

class AppModel
{
private:
    Date *dateSuppression;

public:
    AppModel();
    ~AppModel();

    const Date *getDateSuppression() const;
    void setDateSuppression(const Date *newDateSuppression);
};

#endif // APPMODEL_H
