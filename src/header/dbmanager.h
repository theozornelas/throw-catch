#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include <QDebug>

#include "skiplist.h"
#include "graph.h"
#include "stadium.h"

class DBManager
{
public:
    /*****************************
     *  CONSTRUCTOR & DESTRUCTOR
     *****************************/
    DBManager();
    ~DBManager();

    /****************
     *   ACCESSORS
     ****************/
    skiplist<int, Stadium*> getStadiums();
    // ---- getSouvenirs(Stadium *s);

    /****************
     *   MUTATORS
     ****************/
    // Adding or updating information of a stadium.
     bool AddNewStadium(Stadium *s);
     bool UpdateStadium(Stadium *s);

    // Adding, removing or changing information for souvenir.
    bool AddNewSouvenir(int stadiumKey, QString name, double price, int quantity);
    bool RemoveSouvenir(int stadiumKey, QString name);
    bool updateSouvenirName(int stadiumKey, QString oldName, QString newName);
    bool updateSouvenirPrice(int stadiumKey, QString souvenirName, double newPrice);
    bool updateSouvenirQuantity(int stadiumKey, QString souvenirName, int newQuantity);
    bool updateTotalRevenue(int stadiumKey, double newRevenue);


    // ACCESSORS - Retrieves needed information for the GUI (keys for stadiums)
    int getStadiumID(QString stadiumName);
    QVector<int> getAllStadiumsKeys();

    // Graph related methods 
    bool addEdges(Stadium *origin, Stadium *destination, int weight);
    Graph<Stadium>* createGraph(skiplist<int, Stadium*> stadiumList);


private:
    QSqlDatabase _db;
    QSqlQuery _qry;
};

#endif // DBMANAGER_H
