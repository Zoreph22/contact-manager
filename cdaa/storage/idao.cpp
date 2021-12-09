#include "idao.h"

#include <QDebug>

IDao::IDao()
{
}

void IDao::test()
{
    qDebug() << QString("ok");
}
