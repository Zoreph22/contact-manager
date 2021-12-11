#ifndef TODOCOLLECTION_H
#define TODOCOLLECTION_H

#include <list>
#include "collection.h"
#include "todomodel.h"

using namespace std;

/// Classe collection de @link TodoModel @endlink.
class TodoCollection : public Collection<TodoModel>
{
    TodoModel &getById(unsigned int id) const;
    TodoCollection &filterId(unsigned int id);
    TodoCollection &filterDateRealisation(const Date & date);
    TodoCollection &filterDateRealisation(const Date & dateMin, const Date & dateMax);
};

#endif // TODOCOLLECTION_H
