#ifndef TODOCOLLECTION_H
#define TODOCOLLECTION_H

#include <iostream>
#include <list>
#include "collection.h"
#include "todomodel.h"

using namespace std;

/// Classe collection de @link TodoModel @endlink.
class TodoCollection : public Collection<TodoModel>
{
};

#endif // TODOCOLLECTION_H
