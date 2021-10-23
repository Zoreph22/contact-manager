#ifndef COLLECTION_IMPL_H
#define COLLECTION_IMPL_H

#include "collection.h"

template<class T>
void Collection<T>::add(const T &instance)
{
    this->liste.push_back(instance);
}

template<class T>
void Collection<T>::remove(const T &instance)
{
    this->liste.remove(instance);
}

template<class T>
void Collection<T>::clear()
{
    this->liste.clear();
}

template<class T>
unsigned int Collection<T>::count() const
{
    return this->liste.size();
}

template<class T>
bool Collection<T>::operator==(const Collection<T> &collection) const
{
    return this->liste == collection.getList();
}

template<class T>
bool Collection<T>::operator!=(const Collection<T> &collection) const
{
    return !this->operator==(collection);
}

template<class T>
const list<T> &Collection<T>::getList() const
{
    return this->liste;
}

#endif // COLLECTION_IMPL_H
