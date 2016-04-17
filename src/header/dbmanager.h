#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include <QDebug>

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
    // SkipList<int, Stadium> getStadiums();
    // ---- getSouvenirs();

    /****************
     *   MUTATORS
     ****************/
    // Adding or updating information of a stadium.
    // void AddNewStadium(int stadiumKey, QString name...);
    // void UpdateStadium(int stadiumKey, QString name...);

    // Adding, removing or changing information for souvenir.
    bool AddNewSouvenir(int stadiumKey, QString name, double price, int quantity);
    bool RemoveSouvenir(int stadiumKey, QString name);
    bool ChangeSouvenirName(int stadiumKey, QString oldName, QString newName);
    bool ChangeSouvenirPrice(int stadiumKey, QString souvenirName, double newPrice);
    bool ChangeSouvenirQuantity(int stadiumKey, QString souvenirName, int newQuantity);


private:
    QSqlDatabase _db;
    QSqlQuery _qry;
};

#endif // DBMANAGER_H
