#include "contactmodel.h"

ContactModel::ContactModel(const unsigned int id)
    : id(id), dateModification(nullptr)
{
}

ContactModel::ContactModel(const unsigned int id, const Date dateCreation)
    : id(id), dateCreation(dateCreation), dateModification(nullptr)
{
}

ContactModel::ContactModel(const ContactModel &contact)
    : id(contact.id) // TODO : ...
{
}

ContactModel::~ContactModel()
{
}

ContactModel &ContactModel::operator=(const ContactModel &contact)
{
}

bool ContactModel::operator==(const ContactModel &contact) const
{
}

ostream &operator<<(ostream &out, const ContactModel &contact)
{
}

unsigned int ContactModel::getId() const
{
    return id;
}

const string &ContactModel::getNom() const
{
    return nom;
}

void ContactModel::setNom(const string &newNom)
{
    nom = newNom;
}

const string &ContactModel::getPrenom() const
{
    return prenom;
}

void ContactModel::setPrenom(const string &newPrenom)
{
    prenom = newPrenom;
}

const string &ContactModel::getEntreprise() const
{
    return entreprise;
}

void ContactModel::setEntreprise(const string &newEntreprise)
{
    entreprise = newEntreprise;
}

const string &ContactModel::getEmail() const
{
    return email;
}

void ContactModel::setEmail(const string &newEmail)
{
    email = newEmail;
}

const string &ContactModel::getTel() const
{
    return tel;
}

void ContactModel::setTel(const string &newTel)
{
    tel = newTel;
}

const string &ContactModel::getPhoto() const
{
    return photo;
}

void ContactModel::setPhoto(const string &newPhoto)
{
    photo = newPhoto;
}

const Date &ContactModel::getDateCreation() const
{
    return dateCreation;
}

const Date *ContactModel::getDateModification() const
{
    return dateModification;
}

void ContactModel::setDateModification(const Date &newDateModification)
{
    dateModification = new Date(newDateModification);
}

InteractionCollection &ContactModel::getInteractions()
{
    return interactions;
}
