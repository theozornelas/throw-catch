#include "dbmanager.h"
#include <QDebug>
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

skiplist<int, Stadium*> DBManager::getStadiums() {
    skiplist<int, Stadium*> listOfStadiums;
    QVector<Stadium> stadiums;

    QSqlQuery query;
    QSqlQuery souvenirQuery;

    query.prepare("SELECT * FROM Stadiums");
    
    if(query.exec()) {
        while(query.next()) {

            Stadium *s = (new Stadium(query.value("id").toInt(),
                                      query.value("stadium_name").toString(),
                                      query.value("team_name").toString(),
                                      query.value("street_address").toString(),
                                      query.value("city").toString(),
                                      query.value("state").toString(),
                                      query.value("zipcode").toString(),
                                      query.value("box_office_number").toString(),
                                      query.value("date_opened").toString(),
                                      query.value("seating_capacity").toInt(),
                                      query.value("surface").toString(),
                                      query.value("league_type").toString(),
                                      query.value("typology").toString()));

            souvenirQuery.prepare("SELECT * FROM Souvenirs");

            if(souvenirQuery.exec()) {
                while(souvenirQuery.next()) {
                    if(souvenirQuery.value("stadium_id").toInt() == s->getStadiumID()) {
                    s->addSouvenir(new Souvenir(souvenirQuery.value("stadium_id").toInt(),
                                                souvenirQuery.value("souvenir_name").toString(),
                                                souvenirQuery.value("price").toDouble(),
                                                souvenirQuery.value("quantity").toInt()));
                    }
                }
            }

            stadiums.push_back(*s);
            listOfStadiums.insert(query.value("id").toInt(), s);


        }
    }
    
    return listOfStadiums;

}


int DBManager::getStadiumID(QString stadiumName) {

    QSqlQuery query;

    query.prepare("SELECT id FROM Stadiums WHERE stadium_name = '" + stadiumName + "'");

    int id = -1;

    if(query.exec()) {
        if(query.first()) {
            id = query.value("id").toInt();
        }
    }

    return id;

}

QVector<int> DBManager::getAllStadiumsKeys() {
    QVector<int> keys;
    QSqlQuery query;

    query.prepare("SELECT id FROM Stadiums");

    if(query.exec()) {
        while(query.next()) {
            keys.push_back(query.value("id").toInt());
        }
    }

    return keys;
}

Graph<Stadium*>* DBManager::createGraph(skiplist<int, Stadium*> stadiumList) {
    QSqlQuery query;
    Graph<Stadium*>* graph = new Graph<Stadium*>;

    query.prepare("SELECT * FROM Graph");

    QVector<int> stadiumKeys = getAllStadiumsKeys();
    for(int i = 0; i < stadiumKeys.size(); i++) {
        graph->insertVertex(*stadiumList.get(stadiumKeys[i]));
    }

    if(query.exec()) {
        while(query.next()) {
            Stadium *origin = *stadiumList.get(query.value("origin_id").toInt());
            Stadium *destination = *stadiumList.get(query.value("destination_id").toInt());

           graph->insertEdge(origin, destination, query.value("weight").toInt());

        }
    }

  return graph;
}
