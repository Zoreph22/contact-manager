#ifndef INTERACTIONEDITWINDOW_H
#define INTERACTIONEDITWINDOW_H

#include <interactionmodel.h>

#include <QDialog>
#include <QWidget>

namespace Ui {
class InteractionEditWindow;
}

/**
 * @brief Fenêtre permettant de créer ou modifier une interaction.
 * 
 * La fenêtre possède deux modes :
 * - Mode de création : permet de créer une interaction, mais pas de la supprimer.
 * - Mode de modification : permet de modifier le contenu de l'interaction, et de la supprimer.
 * 
 * @note La fenêtre est modale.
 */
class InteractionEditWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur par défaut.
     * @param im Référence de l'interaction à remplir ou à modifier.
     * @param isEdit Créer la fenêtre pour le mode de modification ?
     */
    explicit InteractionEditWindow(InteractionModel &im, bool isEdit, QWidget *parent = nullptr);
    ~InteractionEditWindow();

private slots:
    /// Slot lors du clique sur bouton @a Enregister.
    void on_buttonEnregistrer_clicked();
    /// Slot lors du clique sur bouton @a Annuler.
    void on_buttonAnnuler_clicked();
    /// Slot lors du clique sur bouton @a Supprimer.
    void on_buttonSupprimer_clicked();

private:
    Ui::InteractionEditWindow *ui;
    /// Référence vers l'instance de l'interaction à remplir ou modifier.
    InteractionModel &im;
    /// En mode de modification ?
    bool isEdit = true;
};

#endif // INTERACTIONEDITWINDOW_H
