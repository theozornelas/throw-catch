#include "dbmanager.h"
#include <QDebug>
#include <QFileInfo>
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
    QString path = "/Users/sarahsingletary/Documents/throw-catch/sqlite/throw-catch.db";    // Sarah MacbookPro
//    QString path = "D:/Ethan/Desktop/Working/2_Projects/!saddleback_CS/CS1D_Projects/throw-catch/sqlite/throw-catch.db";    // Ethan Win10 Workstation
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


bool DBManager::updateSouvenirName(int stadiumKey, QString oldName, QString newName) {
    QSqlQuery query;

    query.prepare("UPDATE Souvenirs SET souvenir_name = :new_name WHERE stadium_id = :key AND souvenir_name = :old_name");

    query.bindValue(":new_name", newName);
    query.bindValue(":key", stadiumKey);
    query.bindValue(":old_name", oldName);

    return query.exec();
}

bool DBManager::updateSouvenirPrice(int stadiumKey, QString souvenirName, double newPrice) {
    QSqlQuery query;

    query.prepare("UPDATE Souvenirs SET price = :new_price WHERE stadium_id = :key AND souvenir_name = :souvenir_name");

    query.bindValue(":new_price", newPrice);
    query.bindValue(":key", stadiumKey);
    query.bindValue(":souvenir_name", souvenirName);

    return query.exec();
}

bool DBManager::updateSouvenirQuantity(int stadiumKey, QString souvenirName, int newQuantity) {
    QSqlQuery query;

    query.prepare("UPDATE Souvenirs SET quantity = :new_quantity WHERE stadium_id = :key AND souvenir_name = :souvenir_name");

    query.bindValue(":new_quantity", newQuantity);
    query.bindValue(":key", stadiumKey);
    query.bindValue(":souvenir_name", souvenirName);

    return query.exec();
}

/**
 * A C C E S S O R S
 */

skiplist<int, Stadium*> DBManager::getStadiums() {
    skiplist<int, Stadium*> listOfStadiums;

    QSqlQuery query;
    QSqlQuery souvenirQuery;

    query.prepare("SELECT * FROM Stadiums");
    
    if(query.exec()) {
        while(query.next()) {


            Stadium *s = new Stadium(query.value("id").toInt(),
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
                                      query.value("typology").toString(),
                                      query.value("total_revenue").toDouble());

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

Graph<Stadium>* DBManager::createGraph(skiplist<int, Stadium*> stadiumList) {
    QSqlQuery query;
    Graph<Stadium>* graph = new Graph<Stadium>;

    query.prepare("SELECT * FROM Graph");

    QVector<int> stadiumKeys = getAllStadiumsKeys();
    for(int i = 0; i < stadiumKeys.size(); i++) {
        graph->insertVertex(**stadiumList.get(stadiumKeys[i]));
    }

    if(query.exec()) {
        while(query.next()) {
            Stadium origin = **stadiumList.get(query.value("origin_id").toInt());
            Stadium destination = **stadiumList.get(query.value("destination_id").toInt());
            int weight = query.value("weight").toInt();

           graph->insertEdge(origin, destination, weight);

        }
    }

  return graph;
}

bool DBManager::updateTotalRevenue(int stadiumKey, double newRevenue) {
    QSqlQuery query;

    query.prepare("UPDATE Stadiums SET total_revenue = :new_revenue WHERE id = :key");

    query.bindValue(":new_revenue", newRevenue);
    query.bindValue(":key", stadiumKey);

    return query.exec();
}

bool DBManager::AddNewStadium(Stadium *s) {
    QSqlQuery query;

    query.prepare("INSERT into Stadiums (id, stadium_name, team_name, "
                  "street_address, city, state, zipcode, box_office_number, "
                  "date_opened, seating_capacity, surface, league_type, "
                  "typology, total_revenue) "
                  "VALUES (:id, :stadium_name, :team_name, "
                  ":street_address, :city, :state, :zipcode, :box_office_number, "
                  ":date_opened, :seating_capacity, :surface, :league_type, :typology, :total_revenue)");

    query.bindValue(":id", s->getStadiumID());
    query.bindValue(":stadium_name", s->getStadiumName());
    query.bindValue(":team_name", s->getTeamName());
    query.bindValue(":street_address", s->getAddress().streetAddress);
    query.bindValue(":city", s->getAddress().city);
    query.bindValue(":state", s->getAddress().state);
    query.bindValue(":zipcode", s->getAddress().zipCode);
    query.bindValue(":box_office_number", s->getBoxOfficeNumber());
    query.bindValue(":date_opened", s->getDateOpened());
    query.bindValue(":seating_capacity", s->getSeatingCapacity());
    query.bindValue(":surface", s->getSurface());
    query.bindValue(":league_type", s->getLeagueType());
    query.bindValue(":typology", s->getTypology());
    // All new stadiums should have the starting revenue of 0.
    query.bindValue(":total_revenue", s->getTotalRevenue());


    return query.exec();

}

bool DBManager::UpdateStadium(Stadium *s) {
    QSqlQuery query;

    query.prepare("UPDATE Stadiums SET "
                  "stadium_name = :stadium_name, "
                  "team_name = :team_name, "
                  "street_address = :street_address, "
                  "city = :city, state = :state, zipcode = :zipcode, "
                  "box_office_number = :box_office_number, "
                  "date_opened = :date_opened, "
                  "seating_capacity = :seating_capacity, "
                  "surface = :surface, "
                  "league_type = :league_type, "
                  "typology = :typology "
                  "WHERE id = :id");
    
    query.bindValue(":id", s->getStadiumID());
    query.bindValue(":stadium_name", s->getStadiumName());
    query.bindValue(":team_name", s->getTeamName());
    query.bindValue(":street_address", s->getAddress().streetAddress);
    query.bindValue(":city", s->getAddress().city);
    query.bindValue(":state", s->getAddress().state);
    query.bindValue(":zipcode", s->getAddress().zipCode);
    query.bindValue(":box_office_number", s->getBoxOfficeNumber());
    query.bindValue(":date_opened", s->getDateOpened());
    query.bindValue(":seating_capacity", s->getSeatingCapacity());
    query.bindValue(":surface", s->getSurface());
    query.bindValue(":league_type", s->getLeagueType());
    query.bindValue(":typology", s->getTypology());
    
    return query.exec();
    
}

bool DBManager::addEdges(Stadium *origin, Stadium *destination, int weight) {
    QSqlQuery query;

    query.prepare("INSERT into Graph (origin_id, origin, destination_id, destination, weight) "
                  "VALUES (:origin_id, :origin, :destination_id, :destination, :weight)");

    query.bindValue(":origin_id", origin->getStadiumID());
    query.bindValue(":origin", origin->getStadiumName());
    query.bindValue(":destination_id", destination->getStadiumID());
    query.bindValue(":destination", destination->getStadiumName());
    query.bindValue(":weight", weight);

    return query.exec();
}

