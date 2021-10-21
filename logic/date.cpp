#include "date.h"
#include <ctime>

double Date::getDiff(const Date &date) const
{
    struct tm d1 = this->d;
    struct tm d2 = date.d;
    return difftime(mktime(&d1), mktime(&d2));
}

Date::Date()
{
    time_t n = time(0);
    this->d = *localtime(&n);
}

Date::~Date()
{

}

unsigned int Date::getJour() const
{
    return this->d.tm_mday;
}

unsigned int Date::getMois() const
{
    return this->d.tm_mon+1;
}

unsigned int Date::getAnnee() const
{
    return this->d.tm_year+1900;
}

string Date::toString() const
{
    return to_string(this->getJour()) + "/" + to_string(this->getMois()) + "/" + to_string(this->getAnnee());
}

void Date::fromDate(const int j, const int m, const int a)
{
    time_t mt;
    time(&mt);
    struct tm * md = localtime(&mt);
    md->tm_mday = j;
    md->tm_mon = m - 1;
    md->tm_year = a - 1900;
    mt = mktime(md);
    this->d = *localtime(&mt);
}

Date &Date::operator=(const Date &date)
{
    this->d = date.d;
    return *this;
}

bool Date::operator==(const Date &date) const
{
    return this->getDiff(date) == 0;
}

bool Date::operator<(const Date &date) const
{
    return this->getDiff(date) < 0;
}

bool Date::operator<=(const Date &date) const
{
    return this->getDiff(date) <= 0;
}

bool Date::operator>(const Date &date) const
{
    return this->getDiff(date) > 0;
}

bool Date::operator>=(const Date &date) const
{
    return this->getDiff(date) >= 0;
}

ostream &operator<<(ostream &out, const Date &date)
{
    return out << date.toString();
}
