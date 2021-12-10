#ifndef STDQT_H
#define STDQT_H

#include "storage_global.h"

#include <QDate>
#include <QVariant>
#include <date.h>

class STORAGE_EXPORT StdQt
{
public:
    virtual ~StdQt() = 0;

    static QString string(const std::string & stdString);
    static std::string string(const QVariant & qVariant);
    static std::string string(const QString & qString);
    static QDate date(const Date & stdDate);
    static Date date(const QVariant & qVariant);
    static Date date(const QDate & qDate);
};

#endif // STDQT_H
