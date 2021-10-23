#ifndef CONTACTCOLLECTION_H
#define CONTACTCOLLECTION_H

#include <iostream>
#include "collection.h"
#include "contactmodel.h"

using namespace std;

/// Classe collection de @link ContactModel @endlink.
class ContactCollection : public Collection<ContactModel>
{
};

#endif // CONTACTCOLLECTION_H
