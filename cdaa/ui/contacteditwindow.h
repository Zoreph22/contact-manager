#ifndef CONTACTEDITWINDOW_H
#define CONTACTEDITWINDOW_H

#include <QDialog>
#include <QWidget>
#include <contactmodel.h>
#include <idaointeraction.h>
#include <qtablewidget.h>

namespace Ui {
class ContactEditWindow;
}

class ContactEditWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ContactEditWindow(ContactModel &cm, bool isEdit,QWidget *parent = nullptr);
    ~ContactEditWindow();

private slots:
    void on_pushButton_6_clicked();
    void on_pushButton_5_clicked();
    void on_buttonAnnuler_clicked();
    void on_buttonCreateInteraction_clicked();

    void on_lineEditPrenom_textChanged(const QString &arg1);
    void on_lineEditNom_textChanged(const QString &arg1);
    void on_itemDoubleClicked(QTableWidgetItem*item);

    void on_ButtonPhoto_clicked();

private:
    Ui::ContactEditWindow *ui;
    ContactModel &cm;
    IDaoInteraction * daoInteraction;
    bool isEdit = true;

    void refreshInteractionAndTodosTable();
    void init();

};

#endif // CONTACTEDITWINDOW_H
