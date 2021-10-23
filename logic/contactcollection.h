#ifndef CONTACTCOLLECTION_H
#define CONTACTCOLLECTION_H

#include <iostream>
#include "contactmodel.h"

using namespace std;

/// Classe collection de @link ContactModel @endlink.
class ContactCollection
{
private:
    /// Liste des contacts.
    list<ContactModel> contacts;

public:
    /// Ajouter un contact à la liste.
    void add(const ContactModel &contact);
    /// Supprimer un contact de la liste.
    void remove(const ContactModel &contact);
    /// Vider la liste.
    void clear();

    /// Retourner le nombre de contacts dans la liste.
    unsigned int count() const;

    bool operator==(const ContactCollection &collection) const;
    bool operator!=(const ContactCollection &collection) const;

    /// Retourner la liste.
    const list<ContactModel> &getContacts() const;
};

#endif // CONTACTCOLLECTION_H
