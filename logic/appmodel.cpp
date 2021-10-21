#include "appmodel.h"

AppModel::AppModel() : dateSuppression(nullptr)
{

}

AppModel::~AppModel()
{

}

const Date *AppModel::getDateSuppression() const
{
    return dateSuppression;
}

void AppModel::setDateSuppression(const Date *newDateSuppression)
{
    dateSuppression = new Date(*newDateSuppression);
}
