#ifndef CONTACTEDITWINDOW_H
#define CONTACTEDITWINDOW_H

#include <QWidget>

namespace Ui {
class ContactEditWindow;
}

class ContactEditWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ContactEditWindow(QWidget *parent = nullptr);
    ~ContactEditWindow();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_buttonAnnuler_clicked();

    void on_buttonCreateInteraction_clicked();

private:
    Ui::ContactEditWindow *ui;
};

#endif // CONTACTEDITWINDOW_H
