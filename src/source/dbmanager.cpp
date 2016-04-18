#include "dbmanager.h"

/*
 * C O N S T R U C T O R
 */

/**
 * @brief DBManager::DBManager Connects to the database and turns on foreign keys.
 */
DBManager::DBManager()
{
    _db = QSqlDatabase::addDatabase("QSQLITE");

    // Remember to change path, will find a more generic way soon.
    QString path = "/Users/sarahsingletary/Documents/throw-catch/sqlite/throw-catch.db";
    _db.setDatabaseName(path);
    _qry = QSqlQuery(_db);

    if(!_db.open()) {
        qDebug() << "Error: connection with database failed.";
    }
    else {
        qDebug() << "Database: connection ok.";
        _db.exec("PRAGMA foreign_keys = ON;");
    }
}

/*
 * D E S T R U C T O R
 */

/**
 * @brief DBManager::~DBManager Disconnects the database.
 */
DBManager::~DBManager() {
    _db.close();
    qDebug() << "Database: disconnected ok";
}

/*
 * M U T A T O R S
 */

/**
 * @brief DBManager::AddNewSouvenir Add a souvenir item to the souvenir table.
 * @param stadiumKey key links to an stadium key/id.
 * @param name name of the souvenir item.
 * @param price price of the souvenir item.
 * @param quantity quanity of how much is purchased of the specified item.
 * @return true if the new souvenir is successfully added to
 *         the souvenir table, otherwise false.
 */
bool DBManager::AddNewSouvenir(int stadiumKey, QString name, double price, int quantity) {
    QSqlQuery query;

    query.prepare("INSERT into Souvenirs (stadium_id, souvenir_name, price, quantity) "
                  "VALUES (:stadium_id, :souvenir_name, :price, :quantity)");

    query.bindValue(":stadium_id", stadiumKey);
    query.bindValue(":souvenir_name", name);
    query.bindValue(":price", price);
    query.bindValue(":quantity", quantity);

    return query.exec();

}

/**
 * @brief DBManager::RemoveSouvenir Removes a souvenir from the souvenir's menu.
 * @param stadiumKey key links to an stadium key/id.
 * @param name name of the souvenir to removed
 * @return true if the new souvenir is successfully removed
 *         to the souvenir table, otherwise false.
 */
bool DBManager::RemoveSouvenir(int stadiumKey, QString name) {
    QSqlQuery query;

    query.prepare("DELETE FROM Souvenirs WHERE stadium_id = :stadium_id "
                  "and souvenir_name = :souvenir_name");

    query.bindValue(":stadium_id", stadiumKey);
    query.bindValue(":souvenir_name", name);

    return query.exec();
}


//bool DBManager::ChangeSouvenirName(int stadiumKey, QString oldName, QString newName) {

//}

//bool DBManager::ChangeSouvenirPrice(int stadiumKey, QString souvenirName, double newPrice) {

//}

//bool DBManager::ChangeSouvenirQuantity(int stadiumKey, QString souvenirName, int newQuantity) {

//}

/**
 * A C C E S S O R S
 */

//skiplist<int, Stadium> DBManager::getStadiums() {
//    skiplist<int, Stadium> listOfStadiums;

//}
