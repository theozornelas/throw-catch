#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dbmanager.h"
#include "stadium.h"
#include "skiplist.h"
#include "graph.h"
#include "shoppingcart.h"

#include <QTableWidgetItem>
#include <QTreeWidgetItem>
#include <QMessageBox>
#include <QRegExp>
#include <QDebug>
#include <QSpinBox>
#include <QCompleter>
#include <QCheckBox>
#include <QFile>
#include <QFileDialog>



#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

enum display {
    HOME,
    VIEW_STADIUMS,
    VIEW_SINGLE_STADIUM,
    PLAN_A_TRIP,
    QUICK_TRIP,
    CUSTOM_TRIP,
    MST_TRIP,
    TRIP_PROCESS,
    CONFIRM_SHOPPING_CART,
    ADMIN_LOGIN,
    ADMIN_HOME,
    ADMIN_STADIUMS,
    MODIFY_INFO,
    MODIFY_SOUVENIRS,
    MODIFY_STADIUMS,
    UPDATE_STADIUM,
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
    void addToCart(Souvenir *s);
    void tripProcess(QVector<Stadium*> trip);

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

    void on_confirmCustomTripButton_clicked();

    void on_shoppingCartButton_clicked();

    void on_secretAdminLoginButton_clicked();

    void on_addSouvenirToShoppingCart_clicked();

    void on_currentTripNextStadium_clicked();

    void on_searchButton_clicked();

    void on_stadiumsToSelectFromList_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_selectedStadiumsList_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_confirmPurchasesButton_clicked();

    void on_viewAdminStadiumsButton_clicked();

    void on_startingStadiumComboBox_currentIndexChanged(const QString &arg1);

    void on_adminHomeButton_clicked();
    
    void on_viewMoreInfoAboutStadiumButton_clicked();

    void viewSingleStadium(QString stadiumName);

    void viewStadiumBy(QString sortByType);

    void on_viewStadiumByComboBox_currentIndexChanged(const QString &arg1);

    void on_quickTripTakeTripButton_clicked();

    void on_adminModifyStadiumsButton_clicked();

    void on_updateAStadiumButton_clicked();
    void on_viewAdminStadiumsButton_2_clicked();

    void on_removeSelectedSouvenir_2_clicked();

private:
    Ui::MainWindow *ui;
    DBManager db;

    QVector<int> keys;
    QVector<Souvenir*> shoppingCart;

    Graph<Stadium>* stadiumsGraph;
    skiplist<int, Stadium*> stadiums;
    Stadium *currentStadium = NULL;
    bool adminPrivilege = false;

    // Allows user to search stadium at any given moment
    QCompleter *stadiumSearch;
    QStringList searchNames;


};

#endif // MAINWINDOW_H
