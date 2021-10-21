#ifndef DATE_H
#define DATE_H
#include <iostream>

using namespace std;
class Date
{
private:
    struct tm d;
    double getDiff(const Date &date) const;

public:
    Date();
    ~Date();
    unsigned int getJour() const;
    unsigned int getMois() const;
    unsigned int getAnnee() const;
    string toString() const;
    void fromDate(const int j, const int m, const int a);

    Date &operator=(const Date &date);
    bool operator==(const Date &date) const;
    bool operator<(const Date &date) const;
    bool operator<=(const Date &date) const;
    bool operator>(const Date &date) const;
    bool operator>=(const Date &date) const;
    friend ostream &operator<<(ostream &out, const Date &date);
};

#endif // DATE_H
