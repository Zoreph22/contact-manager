#ifndef CONTACTCOLLECTION_H
#define CONTACTCOLLECTION_H

#include "contactmodel.h"

#include <iostream>

using namespace std;

class ContactCollection
{
private:
    list<ContactModel> contacts;

public:
    ContactCollection();
    ~ContactCollection();
    void add(const ContactModel & contact);
    void remove(const ContactModel & contact);
    void clear();
    unsigned int count() const;

    const list<ContactModel> &getContacts() const;
    void setContacts(const list<ContactModel> &newContacts);
};

#endif // CONTACTCOLLECTION_H
