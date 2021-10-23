#ifndef APPMODEL_H
#define APPMODEL_H

#include "date.h"

/// Classe de l'application stockant les états globaux.
class AppModel
{
private:
    /// Date de la dernière suppression d'un contact. Date vide si aucune dernière suppression.
    Date dateSuppression;

public:
    /// Retourner la date de la dernière suppression d'un contact, ou date vide si aucune suppression.
    const Date &getDateSuppression() const;
    /**
     * @brief Définir la date de la dernière suppression d'un contact.
     * @param newDateSuppression Nouvelle date de suppression.
     * @throw invalid_argument Nouvelle date de suppression < date de suppression actuel.
     */
    void setDateSuppression(const Date &newDateSuppression);
};

#endif // APPMODEL_H
