#include "souvenir.h"

/**
 * @brief Souvenir constructor
 */
Souvenir::Souvenir() {
    stadiumID = 0;
    souvenirName = "";
    souvenirPrice = 0;
    quantity = 0;
}

/**
 * @brief Souvenir::Souvenir
 * @param id [IN] id of the stadium this Souvenir belongs to
 * @param name [IN] name of the Souvenir
 * @param price [IN] price of the Souvenir
 * @param qty [IN] quantity of the Souvenir
 */
Souvenir::Souvenir(unsigned int id, QString name,
             double price, unsigned int qty) {
    stadiumID = id;
    souvenirName = name;
    souvenirPrice = price;
    quantity = qty;
}

/**
 * @brief Souvenir destructor
 */
Souvenir::~Souvenir() {
    stadiumID = 0;
    souvenirName = "";
    souvenirPrice = 0;
    quantity = 0;

}

    /***************
     *  ACCESSORS
     **************/

/**
 * @brief gets the stadium ID of the owner stadium
 * @return the stadium ID of owning stadium
 */
unsigned int Souvenir::getStadiumID() const {
    return stadiumID;
}

/**
 * @brief gets the name of the Souvenir
 * @return the Souvenirs name
 */
QString Souvenir::getName() const {
    return souvenirName;
}

/**
 * @brief Souvenir::getPrice
 * @return the price of the Souvenir
 */
double Souvenir::getPrice() const {
    return souvenirPrice;
}

/**
 * @brief Souvenir::getQuantity
 * @return the quantity of the Souvenir
 */
unsigned int Souvenir::getQuantity() const {
    return quantity;
}

    /***************
     *  MUTATORS
     **************/

/**
 * @brief Souvenir::setName
 * @param newName [IN] the new name
 */
void Souvenir::setName(QString newName) {
    souvenirName = newName;
}

/**
 * @brief Souvenir::setPrice
 * @param newPrice [IN] the new price
 */
void Souvenir::setPrice(double newPrice) {
    souvenirPrice = newPrice;
}

/**
 * @brief Souvenir::setQuantity
 * @param newQty [IN] the new quantity
 */
void Souvenir::setQuantity(unsigned int newQty) {
    quantity = newQty;
}

/**
 * @brief Souvenir::addToQuantity
 * @param addQty [IN] the quantity to add to the current qty
 */
void Souvenir::addToQuantity(unsigned int addQty) {
    quantity += addQty;
}

/**
 * @brief Souvenir::setStadiumID
 * @param id [IN] the ID of the owning stadium to change to
 */
void Souvenir::setStadiumID(int id) {
    stadiumID = id;
}


