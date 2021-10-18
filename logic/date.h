#ifndef DATE_H
#define DATE_H
#include <iostream>

using namespace std;
class Date
{
private:
    struct tm d;
public:
    Date();
    unsigned int getJour() const;
    unsigned int getMois() const;
    unsigned int getAnnee() const;
    string toString() const;
    void fromDate(const int j, const int m, const int a);
};

#endif // DATE_H
