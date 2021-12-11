#ifndef REQUETEWINDOW_H
#define REQUETEWINDOW_H

#include <QDialog>
#include <contactcollection.h>

namespace Ui {
class RequeteWindow;
}

class RequeteWindow : public QDialog
{
    Q_OBJECT

enum class Sujet {
    Interactions,
    Todos,
    DatesTodo
};

public:
    explicit RequeteWindow(const ContactCollection & contacts, QWidget *parent = nullptr);
    ~RequeteWindow();

private:
    void refreshComboBox();
    void refreshResults();
    void queryInteractions();
    void queryTodos();

private slots:
    void on_buttonRechercher_clicked();
    void on_buttonFermer_clicked();
    void on_radioInteractions_clicked();

    void on_radioTodos_clicked();

    void on_radioInteractions_toggled(bool checked);

    void on_radioTodos_toggled(bool checked);

    void on_radioDatesTodo_toggled(bool checked);

private:
    Ui::RequeteWindow *ui;

    const ContactCollection & contacts;
    ContactCollection filteredContacts;
    InteractionCollection filteredInteractions;
    TodoCollection filteredTodos;

    enum Sujet sujet = Sujet::Interactions;

};

#endif // REQUETEWINDOW_H
