#ifndef INTERACTIONEDITWINDOW_H
#define INTERACTIONEDITWINDOW_H

#include <QWidget>

namespace Ui {
class InteractionEditWindow;
}

class InteractionEditWindow : public QWidget
{
    Q_OBJECT

public:
    explicit InteractionEditWindow(QWidget *parent = nullptr);
    ~InteractionEditWindow();

private slots:
    void on_pushButton_3_clicked();

    void on_buttonEnregistrer_clicked();

    void on_buttonAnnuler_clicked();

private:
    Ui::InteractionEditWindow *ui;
};

#endif // INTERACTIONEDITWINDOW_H
