#include "contactcollection.h"

ContactCollection &ContactCollection::filterId(unsigned int id)
{
    this->liste.remove_if([id](ContactModel & c) {
        return !(c.getId() == id);
    });

    return *this;
}

ContactCollection &ContactCollection::filterPrenom(const string &prenom)
{
    this->liste.remove_if([prenom](ContactModel & c) {
        return !ContactCollection::findStrings(c.getPrenom(), prenom);
    });

    return *this;
}

ContactCollection &ContactCollection::filterNom(const string &nom)
{
    this->liste.remove_if([&nom](ContactModel & c) {
        return !ContactCollection::findStrings(c.getNom(), nom);
    });

    return *this;
}

ContactCollection &ContactCollection::filterEntreprise(const string &entreprise)
{
    this->liste.remove_if([&entreprise](ContactModel & c) {
        return !ContactCollection::findStrings(c.getEntreprise(), entreprise);
    });

    return *this;
}

ContactCollection &ContactCollection::filterDateCreation(const Date &date)
{
    this->liste.remove_if([&date](ContactModel & c) {
        return !(c.getDateCreation() == date);
    });

    return *this;
}

ContactCollection &ContactCollection::filterDateCreation(const Date &dateMin, const Date &dateMax)
{
    this->liste.remove_if([&dateMin, &dateMax](ContactModel & c) {
        if (dateMax.isNull()) return !(c.getDateCreation() >= dateMin);
        if (dateMin.isNull()) return !(c.getDateCreation() <= dateMax);
        return !(c.getDateCreation() >= dateMin && c.getDateCreation() <= dateMax);
    });

    return *this;
}

