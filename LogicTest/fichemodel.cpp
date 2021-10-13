#include "fichemodel.h"

unsigned int FicheModel::getId() const
{
    return id;
}

const string &FicheModel::getNom() const
{
    return nom;
}

void FicheModel::setNom(const string &newNom)
{
    nom = newNom;
}

const string &FicheModel::getPrenom() const
{
    return prenom;
}

void FicheModel::setPrenom(const string &newPrenom)
{
    prenom = newPrenom;
}

const string &FicheModel::getEntreprise() const
{
    return entreprise;
}

void FicheModel::setEntreprise(const string &newEntreprise)
{
    entreprise = newEntreprise;
}

const string &FicheModel::getEmail() const
{
    return email;
}

void FicheModel::setEmail(const string &newEmail)
{
    email = newEmail;
}

const string &FicheModel::getTel() const
{
    return tel;
}

void FicheModel::setTel(const string &newTel)
{
    tel = newTel;
}

const string &FicheModel::getPhoto() const
{
    return photo;
}

void FicheModel::setPhoto(const string &newPhoto)
{
    photo = newPhoto;
}

Date *FicheModel::getDateCreation() const
{
    return dateCreation;
}

Date *FicheModel::getDateModification() const
{
    return dateModification;
}

void FicheModel::setDateModification(Date *newDateModification)
{
    dateModification = newDateModification;
}

list<InteractionModel> *FicheModel::getInteractions() const
{
    return interactions;
}

void FicheModel::setInteractions(list<InteractionModel> *newInteractions)
{
    interactions = newInteractions;
}

FicheModel::FicheModel(unsigned int id)
{
    this->id = id;
    this->dateModification = new Date();
    this->dateCreation = new Date();
    this->interactions = new list<InteractionModel>();
}
