#ifndef CONTACTCOLLECTION_H
#define CONTACTCOLLECTION_H

#include "collection.h"
#include "contactmodel.h"

using namespace std;

/// Classe collection de @link ContactModel @endlink.
class ContactCollection : public Collection<ContactModel>
{
public:
    ContactCollection &filterId(unsigned int id);
    ContactCollection &filterPrenom(const string & prenom);
    ContactCollection &filterNom(const string & nom);
    ContactCollection &filterEntreprise(const string & entreprise);
    ContactCollection &filterDateCreation(const Date & date);
    ContactCollection &filterDateCreation(const Date & dateMin, const Date & dateMax);
    InteractionCollection &getInteractions() const;
    TodoCollection &getTodos() const;
};

#endif // CONTACTCOLLECTION_H
