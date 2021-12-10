#include "idaocontact.h"

/*ContactCollection IDaoContact::readAllComplet() const
{
    ContactCollection contacts = this->readAll();

    for (ContactModel & contact : contacts.getList())
    {
        InteractionCollection interactions = daoI.readAll(contact.getId());
        contact.setInteractions(interactions);

        for (InteractionModel & interaction : interactions.getList())
        {
            TodoCollection todos = daoT.readAll(interaction.getId());
            interaction.setTodos(todos);
        }
    }

    return contacts;
}*/

/*ContactCollection IDaoContact::readAllComplet() const
{
    ContactCollection contacts = this->readAll();

    for (ContactModel & contact : contacts.getList())
    {
        InteractionCollection interactions = daoI.readAllComplet(contact.getId());
        contact.setInteractions(interactions);
    }

    return contacts;
}*/

/*ContactCollection IDaoContact::readAllComplet() const
{
    InteractionCollection interactions = this->readAll();

    for (Interaction & interaction : interactions.getList())
    {
        TodoCollection todos = daoI.readAll(contact.getId());
        contact.setInteractions(interactions);
    }

    return contacts;
}*/
