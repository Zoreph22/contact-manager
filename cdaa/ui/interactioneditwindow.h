#ifndef INTERACTIONEDITWINDOW_H
#define INTERACTIONEDITWINDOW_H

#include <QDialog>
#include <QWidget>
#include <interactionmodel.h>

namespace Ui {
class InteractionEditWindow;
}

class InteractionEditWindow : public QDialog
{
    Q_OBJECT

public:
    explicit InteractionEditWindow(InteractionModel &im, bool isEdit, QWidget *parent = nullptr);
    ~InteractionEditWindow();

private slots:
    void on_buttonEnregistrer_clicked();

    void on_buttonAnnuler_clicked();

    void on_buttonSupprimer_clicked();

private:
    Ui::InteractionEditWindow *ui;
    InteractionModel &im;
    bool isEdit = true;
};

#endif // INTERACTIONEDITWINDOW_H
