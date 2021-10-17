#ifndef REQUETE_H
#define REQUETE_H

#include <list>

using namespace std;

template <class T>
class Requete // TODO ABSTRACT
{
protected:
    list<T> * results;
public:
    Requete();
    unsigned int count() const;
    list<T> *getResults() const;
};

#include "requete_impl.h"

#endif // REQUETE_H
