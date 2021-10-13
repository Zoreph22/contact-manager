#ifndef FICHEMODEL_H
#define FICHEMODEL_H
#include <interactionmodel.h>
#include <date.h>
#include <iostream>

using namespace std;

class FicheModel
{

private:
    unsigned int id;
    string nom;
    string prenom;
    string entreprise;
    string email;
    string tel;
    string photo;
    Date *dateCreation;
    Date *dateModification;
    list<InteractionModel> *interactions;

public:
    FicheModel(unsigned int id);
    friend ostream &operator<< (ostream &, const FicheModel &);
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
    Date *getDateCreation() const;
    Date *getDateModification() const;
    void setDateModification(Date *newDateModification);
    list<InteractionModel> *getInteractions() const;
    void setInteractions(list<InteractionModel> *newInteractions);
};

#endif // FICHEMODEL_H
