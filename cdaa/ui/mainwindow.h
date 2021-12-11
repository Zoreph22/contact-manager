#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "requetewindow.h"

#include <QMainWindow>
#include <contactcollection.h>
#include <idaocontact.h>
#include <idaogeneral.h>
#include <idaointeraction.h>
#include <idaotodo.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void init();
    void loadData();

private:
    Ui::MainWindow *ui;

    IDaoContact * daoContact;
    IDaoInteraction * daoInteraction;
    IDaoTodo * daoTodo;
    IDaoGeneral * daoGeneral;

    ContactCollection contacts;

    bool isFilterOpen = false;

private slots:
    void on_actionQuit_triggered();
    void on_actionExportJson_triggered();
    void on_actionResetAll_triggered();
    void on_buttonReset_clicked();
    void on_buttonFiltrer_clicked();
    void on_buttonRequest_clicked();
    void on_ButtonCreateContact_clicked();
    void on_buttonOpenFilter_clicked();
    void on_dateEditMin_userDateChanged(const QDate &date);
};
#endif // MAINWINDOW_H
