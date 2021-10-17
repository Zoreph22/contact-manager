#include "appmodel.h"

Date *AppModel::getDateSuppression() const
{
    return dateSuppression;
}

void AppModel::setDateSuppression(Date *newDateSuppression)
{
    dateSuppression = newDateSuppression;
}

AppModel::AppModel()
{
}
