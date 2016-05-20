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
#include <QDate>



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
    typedef Graph<Stadium>::VertexItr VertexItr;

public:
    /********************************
     *  CONSTURCTOR AND DESTRUCTOR
     *******************************/
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /********************
     *  HELPER METHODS
     *******************/

    /** T/F if a string is empty/blank. **/
    bool isBlank(QString text);
    /** Adds a desired souvenir to the global shopping cart **/
    void addToCart(Souvenir *s);
    /** Trip process for only quick trip request **/
    void tripProcess(QVector<Stadium*> trip);
    /** Trip process for custom trip request only **/
    void tripProcess2(QVector<VertexItr> trip);

    /** Private slots are signals that respond to any triggers when
     *  a user is using the program. (ex. clicking a button) **/

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

    void viewStadiumBy(QString sortByType, QVector<Stadium*> stadiumList);

    void on_viewStadiumByComboBox_currentIndexChanged(const QString &arg1);

    void on_quickTripTakeTripButton_clicked();

    void on_adminModifyStadiumsButton_clicked();

    void on_updateAStadiumButton_clicked();

    void on_addStadiumFromFileButton_clicked();

    void on_cancelStadiumUpdatesButton_clicked();

    void on_confirmStadiumUpdateButton_clicked();
    
    void on_listOfModifyStadiumsSouvenirs_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_password_returnPressed();

    void on_searchBar_returnPressed();

    void on_listOfModifyStadiumsSouvenirs_itemChanged(QTreeWidgetItem *item, int column);

private:
    Ui::MainWindow *ui;
    DBManager db; // Database that allows program to access, modify, & delete data.

    QVector<int> keys;   // List of keys that corresond to stadium's id within database.
    QVector<Souvenir*> shoppingCart; // Shopping cart of souvenirs

    Graph<Stadium>* stadiumsGraph;  // Global graph, that allows user to take a trip.
    skiplist<int, Stadium*> stadiums; // Skiplist of stadiums (stadium_id --> stadium object)
    Stadium *currentStadium = NULL;   // Allows the program to keep track of what current stadium is being requested.
    Souvenir *currentSouvenir = NULL;  // Allows program to keep track of what current souvenir is being requested.
    bool adminPrivilege = false; // Allows program to verify if user has admin privilege to do what is requested.

    // Allows user to search stadium at any given moment
    QCompleter *stadiumSearch;
    QStringList searchNames;


};

#endif // MAINWINDOW_H
