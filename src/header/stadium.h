#ifndef STADIUM
#define STADIUM

#include <QString>
#include "souvenir.h"
using namespace std;

/**
 * @brief The Address struct
 * The struct has four QString to
 * manage the street address, city, state, and
 * zipcode. An easier way to keep track
 * of each segment of the address.
 */
struct Address {
    QString streetAddress;
    QString city;
    QString state;
    QString zipCode;
};

/**
 * @brief The Stadium class
 * This class represents a stadium
 * with the attributes of the stadium name,
 * the team name, stadium address, box office
 * number, seating capacity, type of surface,
 * and type of league type (National or American)
 * Stadium also keeps track of its ID, to enable
 * changing in the database. This class also
 * allows souvenir items to be added and
 * removed. If souvenir item's name or price
 * needs to be changed, must first search for
 * souvenir item, then change it's attributes
 * using souvenir's set methods.
 *
 * @author Sarah Singletary
 * @date April-14-2016
 */
class Stadium {

    /*****************************
     *  CONSTRUCTOR & DESTRUCTOR
     *****************************/
    Stadium(int id, QString name,
            QString team, Address address,
            QString number, unsigned int capacity,
            QString surf, QString league);

    ~Stadium();

    /****************
     *   ACCESSORS
     ****************/
    unsigned int getStadiumID() const;
    QString      getStadiumName() const;
    QString      getTeamName() const;
    QString      getAddress() const;
    QString      getBoxOfficeNumber() const;
    unsigned int getSeatingCapacity() const;
    QString      getSurface() const;
    QString      getLeagueType() const;


    /***************
     *  MUTATORS
     **************/
    void setStadiumName(QString newName);
    void setTeamName(QString newTeam);
    void setAddress(QString streetAddress, QString city,
                    QString state, QString zipCode);
    void setBoxOfficeNumber(QString newNumber);
    void setSeatingCapacity(unsigned int newCapacity);
    void setSurface(QString newSurface);
    void setLeagueType(QString newLeagueType);


    // Mutators for Stadium's souvenir list.
    void addSouvenir(QString name, double price, int quantity);
    void removeSouvenir(QString name);

private:
    Souvenir* findSouvenir(QString name);

    unsigned int stadiumID;
    QString stadiumName;
    QString teamName;
    Address stadiumAddress;
    QString boxOfficeNumber;
    unsigned int seatingCapacity;
    QString surface;
    QString leagueType;
};

#endif // STADIUM

