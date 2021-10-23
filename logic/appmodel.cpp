#include "appmodel.h"

const Date &AppModel::getDateSuppression() const
{
    return this->dateSuppression;
}

void AppModel::setDateSuppression(const Date &newDateSuppression)
{
    if (newDateSuppression < this->dateSuppression)
    {
        throw invalid_argument("La nouvelle date de suppression doit être supérieure ou égale à la date de suppression actuelle");
    }

    this->dateSuppression = newDateSuppression;
}
