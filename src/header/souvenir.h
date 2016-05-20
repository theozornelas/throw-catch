#ifndef SOUVENIR_H
#define SOUVENIR_H

#include <QString>
using namespace std;
/**
 * @brief The Souvenir class
 * This class represents a souvenir.
 * A souvenir has a name, price, and qty.
 * A souvenir also has a key to link it
 * to a stadium it belongs to.
 */
class Souvenir {
public:
    /*****************************
     * CONSTRUCTORS & DESTRUCTOR *
     *****************************/
    // Default constructor, intializes all needed attributes
    Souvenir();
    // Non-default constructor, filling all needed attributes
    Souvenir(unsigned int id, QString name,
             double price, unsigned int qty);
    ~Souvenir();

    /***************
     *  ACCESSORS
     **************/
    // Retrieves the stadium ID, the id given is based off database.
    unsigned int getStadiumID() const;
    QString      getName() const;
    double       getPrice() const;
    unsigned int getQuantity() const;

    /***************
     *  MUTATORS
     **************/
    void setName(QString newName);
    void setPrice(double newPrice);
    void setStadiumID(int id);
    void setQuantity(unsigned int newQty);
    void addToQuantity(unsigned int addQty);

private:
    unsigned int stadiumID;
    QString souvenirName;
    double souvenirPrice;
    unsigned int quantity;
};

#endif // SOUVENIR_H

