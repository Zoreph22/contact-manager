#ifndef REQUETE_IMPL_H
#define REQUETE_IMPL_H

#include "requete.h"

template <class T> list<T> *Requete<T>::getResults() const
{
    return results;
}

template <class T> unsigned int Requete<T>::count() const {
    return this->results->size();
}

template <class T> Requete<T>::Requete()
{
}

#endif // REQUETE_IMPL_H
