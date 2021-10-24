#include "appmodel.h"

Date AppModel::dateSuppression;

const Date &AppModel::getDateSuppression()
{
    return AppModel::dateSuppression;
}

void AppModel::setDateSuppression(const Date &newDateSuppression)
{
    if (newDateSuppression < AppModel::dateSuppression)
    {
        throw invalid_argument("La nouvelle date de suppression doit être supérieure ou égale à la date de suppression actuelle");
    }

    AppModel::dateSuppression = newDateSuppression;
}
