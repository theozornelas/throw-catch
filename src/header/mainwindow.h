#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "dbmanager.h"
#include "stadium.h"
#include "skiplist.h"


enum display {
    HOME,
    VIEW_STADIUMS,
    PLAN_A_TRIP,
    SHORTEST_TO_ALL,
    CUSTOM_TRIP,
    MST_TRIP,
    ADMIN_LOGIN,
    ADMIN_HOME,
    ADMIN_STADIUMS,
    MODIFY_INFO,
    MODIFY_SOUVENIRS
};

enum options {
    CUSTOMER,
    ADMIN
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool isBlank(QString text);

private slots:
    void on_homePageButton_clicked();

    void on_viewStadiumsPageButton_clicked();

    void on_planATripButton_clicked();

    void on_customTripButton_clicked();

    void on_minimumSpanningTreeButton_clicked();

    void on_shortestTripToAllButton_clicked();

    void on_adminLoginButton_clicked();

    void on_loginButton_clicked();

    void on_adminModifyButton_clicked();

    void on_modifyInformationNextButton_clicked();

    void on_removeSelectedSouvenir_clicked();

    void on_addSelectedSouvenir_clicked();

private:
    Ui::MainWindow *ui;
    DBManager db;

    skiplist<int, Stadium>* _stadiums;
    Stadium *currentStadium = NULL;
    QVector<Stadium> stadiums;
    bool adminPrivilege = false;

};

#endif // MAINWINDOW_H
