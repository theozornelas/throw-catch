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
    /**
     * @brief DBManager
     */
    DBManager();

    ~DBManager();

    /****************
     *   ACCESSORS
     ****************/
    /**
     * @brief getStadiums
     * @return
     */
    skiplist<int, Stadium*> getStadiums();
    // ---- getSouvenirs(Stadium *s);

    /****************
     *   MUTATORS
     ****************/

    // Adding or updating information of a stadium.
    /**
      * @brief AddNewStadium
      * @param s
      * @return
      */
     bool AddNewStadium(Stadium *s);
     /**
      * @brief UpdateStadium
      * @param s
      * @return
      */
     bool UpdateStadium(Stadium *s);

    // Adding, removing or changing information for souvenir.
     /**
     * @brief AddNewSouvenir
     * @param stadiumKey
     * @param name
     * @param price
     * @param quantity
     * @return
     */
    bool AddNewSouvenir(int stadiumKey, QString name, double price, int quantity);
    /**
     * @brief RemoveSouvenir
     * @param stadiumKey
     * @param name
     * @return
     */
    bool RemoveSouvenir(int stadiumKey, QString name);
    /**
     * @brief updateSouvenirName
     * @param stadiumKey
     * @param oldName
     * @param newName
     * @return
     */
    bool updateSouvenirName(int stadiumKey, QString oldName, QString newName);
    /**
     * @brief updateSouvenirPrice
     * @param stadiumKey
     * @param souvenirName
     * @param newPrice
     * @return
     */
    bool updateSouvenirPrice(int stadiumKey, QString souvenirName, double newPrice);
    /**
     * @brief updateSouvenirQuantity
     * @param stadiumKey
     * @param souvenirName
     * @param newQuantity
     * @return
     */
    bool updateSouvenirQuantity(int stadiumKey, QString souvenirName, int newQuantity);
    /**
     * @brief updateTotalRevenue
     * @param stadiumKey
     * @param newRevenue
     * @return
     */
    bool updateTotalRevenue(int stadiumKey, double newRevenue);


    // ACCESSORS - Retrieves needed information for the GUI (keys for stadiums)
    /**
     * @brief getStadiumID
     * @param stadiumName
     * @return
     */
    int getStadiumID(QString stadiumName);
    /**
     * @brief getAllStadiumsKeys
     * @return
     */
    QVector<int> getAllStadiumsKeys();

    // Graph related methods 
    /**
     * @brief addEdges
     * @param origin
     * @param destination
     * @param weight
     * @return
     */
    bool addEdges(Stadium *origin, Stadium *destination, int weight);
    /**
     * @brief createGraph
     * @param stadiumList
     * @return
     */
    Graph<Stadium>* createGraph(skiplist<int, Stadium*> stadiumList);


private:
    /**
     * @brief _db
     */
    QSqlDatabase _db;//data base
    /**
     * @brief _qry
     */
    QSqlQuery _qry;
};

#endif // DBMANAGER_H
