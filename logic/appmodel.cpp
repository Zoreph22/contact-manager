#include "appmodel.h"

const Date &AppModel::getDateSuppression() const
{
    return this->dateSuppression;
}

void AppModel::setDateSuppression(const Date &newDateSuppression)
{
    this->dateSuppression = newDateSuppression;
}
