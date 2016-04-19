#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/**************************************************************************
 * This is the Team class. This class represents a Team object, which has
 * as attributes a key and a name. It also overloads the < operator for
 * comparisons in the heap.
 *************************************************************************/

template<class K, class V>
class Team
{
public:

    //constructor
    Team();

    //non-default constructor
    Team(K newKey, V newName);

    //destructor
    ~Team();

    //returns the key of the team object
    K getKey();

    //returns the name of the object
    V getValue();

    //bool operator<(const Team& t1, const Team& t2) const;


private:
    K key_;       //team key
    V value_;   //team name
};

template<class K, class V>
Team<K,V>::Team()
{
//	name.clear();
//	key_  = 0;
}
template<class K, class V>
Team<K,V>::Team(K newKey, V newName)
{
    key_ = newKey;
    value_ = newName;
}

template<class K, class V>
Team<K,V>::~Team(){}

template<class K, class V>
K Team<K,V>::getKey()
{
    return key_;
}

template<class K, class V>
V Team<K,V>::getValue()
{
    return value_;
}

#endif // TEAM_H

