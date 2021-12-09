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

private:
    Ui::ContactEditWindow *ui;
};

#endif // CONTACTEDITWINDOW_H
