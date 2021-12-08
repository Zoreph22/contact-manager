#ifndef REQUETEWINDOW_H
#define REQUETEWINDOW_H

#include <QWidget>

namespace Ui {
class RequeteWindow;
}

class RequeteWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RequeteWindow(QWidget *parent = nullptr);
    ~RequeteWindow();

private:
    Ui::RequeteWindow *ui;
};

#endif // REQUETEWINDOW_H
