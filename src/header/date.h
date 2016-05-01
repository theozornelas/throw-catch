#ifndef DATE_H
#define DATE_H

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

/****************************************************************
* CLASS Date
* 	This class represents a date. It manages three attributes:
* 		year, month, day
***************************************************************/
class Date
{
public:
    /*****************************
     * Constructors & Destructor *
     *****************************/
    Date();

    Date(string date);

    Date(unsigned short year,
         unsigned short month,
         unsigned short day);

    ~Date();

    /*************
     * Mutators  *
     *************/
    // Uses private utility methods
    void SetDate(unsigned short year,
                 unsigned short month,
                 unsigned short day);

    /*************
     * Accessors *
     *************/
    unsigned short GetYear()  const { return year; }
    unsigned short GetMonth() const { return month; }
    unsigned short GetDay()   const { return day; }
    void GetDate(unsigned short &year,
                 unsigned short &month,
                 unsigned short &day) const;

    //Gets the number of days passed between the date passed in and the current
    // object's date
    unsigned short GetDaysSince(unsigned short fromYear,
                                unsigned short fromMonth,
                                unsigned short fromDay) const;

    //Gets the number of months between the date passed in and the current
    // object's date
    unsigned short GetMonthsSince(unsigned short fromYear,
                                  unsigned short fromMonth,
                                  unsigned short fromDay) const;
    unsigned short GetMonthsSince(Date currentDate) const;

    //Gets the number of months between the current object's date and the
    // actual current date
    unsigned short GetMonthsPassed() const;

    // Displays in MM/DD/YYYY format
    string Display() const;

    /************************
     * Overloaded Operators *
     ************************/
    inline bool operator==(const Date& rhs){
        return this->year  == rhs.GetYear()
            && this->month == rhs.GetMonth()
            && this->day   == rhs.GetDay();
    }
    bool operator!=(const Date& rhs){return !operator==(rhs);}
    bool operator< (const Date& rhs){return Compare(*this, rhs);}
    bool operator> (const Date& rhs){return Compare(rhs, *this);}
    bool operator<=(const Date& rhs){return !Compare(rhs, *this);}
    bool operator>=(const Date& rhs){return !Compare(*this, rhs);}

    // Comparator - returns true if lhs was longer ago than rhs
    static bool Compare(Date lhs, Date rhs);

private:
    /*************
     * UTILITIES *
     *************/
    unsigned short GetDaysInMonth(unsigned short year,
                                  unsigned short month) const;

    bool IsLeapYear(unsigned short year) const;

    /*************
     * VALIDATES *
     *************/

    // Validates the year is between 1900 and the current year
    bool ValidateYear(unsigned short year) const;

    // Validates the month is between 1 and 12
    bool ValidateMonth(unsigned short month) const;

    // Validates if a day is possible, taking leap year into consideration
    bool ValidateDay(unsigned short year,
                     unsigned short month,
                     unsigned short day) const;

    // Uses methods above to validate a given date
    // (checks against current day)
    bool ValidateDate(unsigned short year,
                      unsigned short month,
                      unsigned short day) const;

    /**************
     * EXCEPTIONS *
     **************/
    class INVALID_DATE{};
    class INVALID_DAY{};
    class INVALID_MONTH{};
    class INVALID_YEAR{};

    /*************
     * ATTRIBUTES *
     *************/
    unsigned short year;
    unsigned short month;
    unsigned short day;
};
#endif /* DATE_H */
