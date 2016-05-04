#include "stadium.h"
#include <iostream>
#include <QDebug>
/**
 * C O N S T R U C T O R & D E S T R U C T O R
 */

/**
 * @brief Stadium::Stadium Non-default constructor
 * @param id
 * @param name
 * @param team
 * @param address
 * @param number
 * @param capacity
 * @param surf
 * @param league
 */

Stadium::Stadium() {

}

Stadium::Stadium(int id, QString name,
                     QString team, QString street, QString city,
                     QString state, QString zipCode,
                     QString number, QString date, unsigned int capacity,
                     QString surf, QString league,  QString typo)
{

    stadiumID                    = id;
    stadiumName                  = name;
    teamName                     = team;

    // Sets up address
    stadiumAddress.streetAddress = street + '\n';
    stadiumAddress.city          = city;
    stadiumAddress.state         = state;
    stadiumAddress.zipCode       = zipCode;

    boxOfficeNumber              = number;
    dateOpened                   = date;
    seatingCapacity              = capacity;
    surface                      = surf;
    leagueType                   = league;
    typology                     = typo;
}

/**
 * @brief Stadium::~Stadium Destructor
 */
Stadium::~Stadium() {
    seatingCapacity = 0;
    boxOfficeNumber.clear();
    leagueType.clear();
    stadiumName.clear();
    teamName.clear();
    surface.clear();
}

/**
 * A C C E S S O R S
 */

/**
 * @brief getStadiumID id is based off it's id in database table.
 * @return an unsigned int stadium id
 */
unsigned int Stadium::getStadiumID() const {
    return stadiumID;
}

/**
 * @brief Stadium::getStadiumName
 * @return a QString stadium name
 */
QString Stadium::getStadiumName() const {
    return stadiumName;
}

/**
 * @brief Stadium::getTeamName
 * @return a QString team name
 */
QString Stadium::getTeamName() const {
    return teamName;
}

/**
 * @brief Stadium::getAddress returns address in qstring form
 *                 ex: 12345 streetName,
 *                     cityName, ST zipCode
 * @return a QString address
 */
QString Stadium::getAddress() const {


    QString str = stadiumAddress.streetAddress + "\n" +stadiumAddress.city + ", " +
    stadiumAddress.state + " " + stadiumAddress.zipCode;

    return str;
}

/**
 * @brief getBoxOfficeNumber returns box office number in qstring form
 * @return a QString box office number
 */
QString Stadium::getBoxOfficeNumber() const {
    return boxOfficeNumber;
}

/**
 * @brief Stadium::getDateOpened returns date opened in qstring form
 * @return a QString date openeed
 */
QString Stadium::getDateOpened() const {
    return dateOpened;
}

/**
 * @brief Stadium::getSeatingCapacity
 * @return an unsigned int seating capacity
 */
unsigned int Stadium::getSeatingCapacity() const {
    return seatingCapacity;
}

/**
 * @brief Stadium::getSurface
 * @return a QString surface
 */
QString Stadium::getSurface() const {
    return surface;
}

/**
 * @brief Stadium::getLeagueType
 * @return a QString league type
 */
QString Stadium::getLeagueType() const {
    return leagueType;
}

/**
 * @brief Stadium::getTypology
 * @return a QString typology
 */
QString Stadium::getTypology() const {
    return typology;
}

/**
 * M U T A T O R S
 */

/**
 * @brief Stadium::setStadiumName Changes the stadium name to newName
 * @param newName
 */
void Stadium::setStadiumName(QString newName) {
    stadiumName = newName;
}

/**
 * @brief setTeamName Changes the team name to newTeam
 * @param newTeam
 */
void Stadium::setTeamName(QString newTeam) {
    teamName = newTeam;
}

/**
 * @brief Stadium::setAddress Changes the address to new address
 * @param address
 * @param city
 * @param state
 * @param zipCode
 */
void Stadium::setAddress(QString streetAddress, QString city,
                         QString state, QString zipCode) {
    stadiumAddress.streetAddress = streetAddress;
    stadiumAddress.city          = city;
    stadiumAddress.state         = state;
    stadiumAddress.zipCode       = zipCode;
}

/**
 * @brief Stadium::setBoxOfficeNumber Changes the box office number to newNumber.
 * @param newNumber
 */
void Stadium::setBoxOfficeNumber(QString newNumber) {
    boxOfficeNumber = newNumber;
}

/**
 * @brief Stadium::setDateOpened Changes the date opened to newDate.
 * @param newDate
 */
void Stadium::setDateOpened(QString newDate) {
    dateOpened = newDate;
}

/**
 * @brief Stadium::setSeatingCapacity Changes seating capacity to newCapacity
 * @param newCapacity
 */
void Stadium::setSeatingCapacity(unsigned int newCapacity) {
    seatingCapacity = newCapacity;
}

/**
 * @brief Stadium::setSurface Changes surface to newSurface
 * @param newSurface
 */
void Stadium::setSurface(QString newSurface) {
    surface = newSurface;
}

/**
 * @brief Stadium::setLeagueType Changes league type to newLeagueType
 * @param newLeagueType
 */
void Stadium::setLeagueType(QString newLeagueType) {
    leagueType = newLeagueType;
}

/**
 * @brief Stadium::setTypology Changes typology to typo
 * @param typo
 */
void Stadium::setTypology(QString typo) {
    typology = typo;
}

// Mutators for Stadium's souvenir list.
/**
 * @brief Stadium::addSouvenir Adds a souvenir to the current stadium's list of souvenirs.
 * @param name
 * @param price
 * @param quantity
 */
void Stadium::addSouvenir(Souvenir *newSouvenir) {
    souvenirs.push_back(*newSouvenir);
}

/**
 * @brief Stadium::removeSouvenir Removes a souvenir from the current stadium's list of souvenirs.
 * @param name
 */
void Stadium::removeSouvenir(QString name) {

    bool found = false;
    int i = 0;

    while(!found && i < souvenirs.size()) {

        if(name == souvenirs[i].getName()) {
            souvenirs.remove(i);
            found = true;
        }
        else {
            i++;
        }
    }

    if(i >= souvenirs.size()) {
        qDebug() << "Souvenir item was not found.";
    }
}

QVector<Souvenir> Stadium::getSouvenirs() const {
    return souvenirs;
}

void createGraph() {

}
