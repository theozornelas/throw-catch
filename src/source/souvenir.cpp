#include "souvenir.h"

Souvenir::Souvenir() {
    stadiumID = 0;
    souvenirName = "";
    souvenirPrice = 0;
    quantity = 0;
}

Souvenir::Souvenir(unsigned int id, QString name,
             double price, unsigned int qty) {
    stadiumID = id;
    souvenirName = name;
    souvenirPrice = price;
    quantity = qty;
}
Souvenir::~Souvenir() {
    stadiumID = 0;
    souvenirName = "";
    souvenirPrice = 0;
    quantity = 0;

}
    /***************
     *  ACCESSORS
     **************/
unsigned int Souvenir::getStadiumID() const {
    return stadiumID;
}

QString Souvenir::getName() const {
    return souvenirName;
}

double Souvenir::getPrice() const {
    return souvenirPrice;
}

unsigned int Souvenir::getQuantity() const {
    return quantity;
}

    /***************
     *  MUTATORS
     **************/
void Souvenir::setName(QString newName) {
    souvenirName = newName;
}

void Souvenir::setPrice(double newPrice) {
    souvenirPrice = newPrice;
}

void Souvenir::setQuantity(unsigned int newQty) {
    quantity = newQty;
}
void Souvenir::addToQuantity(unsigned int addQty) {
    quantity += addQty;
}



