#include "contactcollection.h"

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

bool ContactCollection::operator==(const ContactCollection &collection) const
{
    return this->contacts == collection.contacts;
}

bool ContactCollection::operator!=(const ContactCollection &collection) const
{
    return !this->operator==(collection);
}

const list<ContactModel> &ContactCollection::getContacts() const
{
    return this->contacts;
}