#ifndef CONTACTEDITWINDOW_H
#define CONTACTEDITWINDOW_H

#include <contactmodel.h>
#include <idaointeraction.h>
#include <idaotodo.h>

#include <QDialog>
#include <QWidget>
#include <QTableWidget>

namespace Ui {
class ContactEditWindow;
}

/**
 * @brief Fenêtre permettant de créer ou modifier un contact.
 * Elle affiche également la liste des interactions et todo du contact.
 * 
 * La fenêtre possède deux modes :
 * - Mode de création : permet de créer un contact, mais ne peut pas ajouter d'interactions, ni de le supprimer.
 * - Mode de modification : permet de modifier les informations du contact, de lui ajouter des interactions, et de le supprimer.
 * 
 * @note La fenêtre est modale.
 */
class ContactEditWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur par défaut.
     * @param cm Référence du contact à remplir ou à modifier.
     * @param isEdit Créer la fenêtre pour le mode de modification ?
     */
    explicit ContactEditWindow(ContactModel &cm, bool isEdit,QWidget *parent = nullptr);
    ~ContactEditWindow();

private slots:
    /// Slot lors du clique sur bouton @a Supprimer.
    void on_buttonSupprimer_clicked();
    /// Slot lors du clique sur bouton @a Enregister.
    void on_buttonEnregister_clicked();
    /// Slot lors du clique sur bouton @a Annuler.
    void on_buttonAnnuler_clicked();
    /// Slot lors du clique sur bouton @a Créer @a interaction.
    void on_buttonCreateInteraction_clicked();

    /// Slot lors du changement de texte dans le champ de texte @a Prénom
    void on_lineEditPrenom_textChanged(const QString &arg1);
    /// Slot lors du changement de texte dans le champ de texte @a Nom
    void on_lineEditNom_textChanged(const QString &arg1);
    /// Slot lors du double clique sur une interaction de la table.
    void on_itemDoubleClicked(QTableWidgetItem*item);

    /// Slot lors du clique sur l'image.
    void on_ButtonPhoto_clicked();

private:
    /// Actualiser la table des interactions et des todos.
    void refreshInteractionsAndTodosTable();

private:
    Ui::ContactEditWindow *ui;

    /// Référence vers l'instance du contact à remplir ou modifier.
    ContactModel &cm;
    /// En mode de modification ?
    bool isEdit = true;

    /// DAO des interactions.
    IDaoInteraction * daoInteraction;
    /// DAO des todos.
    IDaoTodo * daoTodo;
};

#endif // CONTACTEDITWINDOW_H
