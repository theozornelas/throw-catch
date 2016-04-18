#ifndef STADIUM
#define STADIUM

#include <QString>
#include "souvenir.h"
using namespace std;

struct Address {
    QString streetAddress;
    QString city;
    QString state;
    QString zipCode;
};

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

