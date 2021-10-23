#ifndef CONTACTMODEL_H
#define CONTACTMODEL_H

#include <iostream>
#include <regex>
#include "date.h"
#include "interactioncollection.h"

using namespace std;

/// Modèle stockant les informations d'un contact.
class ContactModel
{
private:
    /// Identifiant unique du contact.
    unsigned int id;
    /// Nom.
    string nom;
    /// Prénom.
    string prenom;
    /// Entreprise.
    string entreprise;
    /// Adresse e-mail.
    string email;
    /// Numéro de téléphone.
    string tel;
    /// URI de la photo.
    string photo;
    /// Date de création du contact.
    Date dateCreation;
    /// Date de la dernière modification du contact.
    Date dateModification;
    /// Liste des interactions du contact.
    InteractionCollection interactions;

public:
    /**
     * Correspond au prochain identifiant qui sera utilisé à la création
     * d'un nouveau contact. S'incrémente à chaque nouveau contact.
     * @brief Numéro d'identifiant maximal généré.
     */
    static unsigned int idCount;

    /**
     * @brief Constructeur par défaut.
     * Identifiant généré automatiquement, et date de création initialisée à la date du jour.
     */
    ContactModel();
    /**
     * @brief Créer une instance pré-initialisée.
     * @param id Identifiant unique.
     * @param dateCreation Date de création du contact (ne doit pas être vide).
     * @throw invalid_argument Date de création vide.
     */
    ContactModel(unsigned int id, const Date &dateCreation);
    /**
     * @brief Constructeur par copie.
     * @param contact Contact à copier.
     */
    ContactModel(const ContactModel &contact);

    ContactModel &operator=(const ContactModel &contact);
    bool operator==(const ContactModel &contact) const;
    bool operator!=(const ContactModel &contact) const;
    friend ostream &operator<<(ostream &out, const ContactModel &contact);

    /// Retourner l'identifiant unique.
    unsigned int getId() const;
    /// Retourner le nom.
    const string &getNom() const;
    /// Définir le nom.
    void setNom(const string &newNom);
    /// Retourner le prénom.
    const string &getPrenom() const;
    /// Définir le prénom.
    void setPrenom(const string &newPrenom);
    /// Retourner l'entreprise.
    const string &getEntreprise() const;
    /// Définir l'entreprise.
    void setEntreprise(const string &newEntreprise);
    /// Retourner l'adresse e-mail.
    const string &getEmail() const;
    /**
     * @brief Définir l'adresse e-mail.
     * @param newEmail Nouvelle adresse e-mail.
     * @throw invalid_argument Format adresse e-mail invalide.
     * @see Formats adresse e-mail valides https://en.wikipedia.org/wiki/Email_address
     */
    void setEmail(const string &newEmail);
    /// Retourner le numéro de téléphone.
    const string &getTel() const;
    /**
     * @brief Définir le numéro de téléphone.
     * @param newTel Nouveau numéro de téléphone.
     * @throw invalid_argument Format du numéro invalide.
     * @note Exemples de format valide : +33618961596, 0618961596, 5214 (sans séparateurs).
     */
    void setTel(const string &newTel);
    /// Retourner l'URI de la photo.
    const string &getPhoto() const;
    /// Définir l'URI de la photo.
    void setPhoto(const string &newPhoto);
    /// Retourner la date de création du contact.
    const Date &getDateCreation() const;
    /// Retourner la date de modification du contact (vide si aucune modification).
    const Date &getDateModification() const;
    /**
     * @brief Définir la date de la dernière modification du contact.
     * @param newDateModification Nouvelle date de modification.
     * @throw invalid_argument Nouvelle date de modification < date de création.
     * @throw invalid_argument Nouvelle date de modification < date de modification actuel.
     */
    void setDateModification(const Date &newDateModification);
    /// Retourner la liste des interactions du contact.
    InteractionCollection &getInteractions();
};

#endif // CONTACTMODEL_H
