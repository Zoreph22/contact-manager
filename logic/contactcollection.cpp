#include "contactcollection.h"

ContactCollection::ContactCollection()
{

}

ContactCollection::~ContactCollection()
{

}

void ContactCollection::add(const ContactModel &contact)
{
    this->contacts.push_back(contact);
}

void ContactCollection::remove(const ContactModel &contact)
{
    this->contacts.remove(contact);
}

void ContactCollection::clear()
{
    this->contacts.clear();
}

unsigned int ContactCollection::count() const
{
    return this->contacts.size();
}


const list<ContactModel> &ContactCollection::getContacts() const
{
    return contacts;
}

void ContactCollection::setContacts(const list<ContactModel> &newContacts)
{
    contacts = newContacts;
}

