#include "stadium.h"

Stadium::Stadium(int id, QString name,
                QString team, Address address,
                QString number, unsigned int capacity,
                QString surf, QString league) {

    stadiumID       = id;
    stadiumName     = name;
    teamName        = team;
    stadiumAddress  = address;
    boxOfficeNumber = number;
    seatingCapacity = capacity;
    surface         = surf;
    leagueType      = league;
}

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
    return stadiumAddress.streetAddress + "\n"
           + stadiumAddress.city + ", "
           + stadiumAddress.state + " "
           + stadiumAddress.zipCode;
}

/**
 * @brief getBoxOfficeNumber
 * @return
 */
QString Stadium::getBoxOfficeNumber() const {
    return boxOfficeNumber;
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


/***************
 *  MUTATORS
 **************/

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


// Mutators for Stadium's souvenir list.
/**
 * @brief Stadium::addSouvenir Adds a souvenir to the current stadium's list of souvenirs.
 * @param name
 * @param price
 * @param quantity
 */
void Stadium::addSouvenir(QString name, double price, int quantity) {

}

/**
 * @brief Stadium::removeSouvenir Removes a souvenir from the current stadium's list of souvenirs.
 * @param name
 */
void Stadium::removeSouvenir(QString name) {

}

