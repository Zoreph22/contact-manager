#ifndef CONTACTMODEL_H
#define CONTACTMODEL_H

#include <iostream>
#include "date.h"
#include "interactioncollection.h"

using namespace std;

// TODO : exceptions vérification format "email", "tel".

class ContactModel
{
private:
    const unsigned int id;
    const Date dateCreation;
    string nom;
    string prenom;
    string entreprise;
    string email;
    string tel;
    string photo;
    Date *dateModification;
    InteractionCollection interactions;

public:
    ContactModel(const unsigned int id);
    ContactModel(const unsigned int id, const Date dateCreation);
    ContactModel(const ContactModel &contact);
    ~ContactModel();

    ContactModel &operator=(const ContactModel &contact);
    bool operator==(const ContactModel &contact) const;
    friend ostream &operator<<(ostream &out, const ContactModel &contact);

    unsigned int getId() const;

    const string &getNom() const;
    void setNom(const string &newNom);
    const string &getPrenom() const;
    void setPrenom(const string &newPrenom);
    const string &getEntreprise() const;
    void setEntreprise(const string &newEntreprise);
    const string &getEmail() const;
    void setEmail(const string &newEmail);
    const string &getTel() const;
    void setTel(const string &newTel);
    const string &getPhoto() const;
    void setPhoto(const string &newPhoto);
    const Date &getDateCreation() const;
    const Date *getDateModification() const;
    void setDateModification(const Date &newDateModification);
    InteractionCollection &getInteractions();
};

#endif // CONTACTMODEL_H
