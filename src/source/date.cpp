#include "Date.h"

                /******************************
                ** CONSTRUCTOR & DESTRUCTOR **
                ******************************/
/**************************************************************
* Date ();
* 	Constructor; Initialize class attributes to current date
* 	Parameters: none
* 	Return: none
***************************************************************/
Date::Date()
{
    time_t now;
    tm *currentTime;

    now = time(NULL);
    currentTime = localtime(&now);

    this->year = 1900 + currentTime -> tm_year;
    this->month = 1 + currentTime -> tm_mon;
    this->day = currentTime -> tm_mday;
}

/**************************************************************
* Date(unsigned short year,
       unsigned short month,
       unsigned short day);
* 	Constructor; Initialize class attributes to current date
* 	Parameters: year, month, day
* 	Return: none
***************************************************************/
Date::Date(unsigned short year,
           unsigned short month,
           unsigned short day)
{
    if (ValidateDate(year, month, day))
    {
        this->year = year;
        this->month = month;
        this->day = day;
    }
    else
    {
        throw(INVALID_DATE());
    }

}

//Takes a date in the format: MONTH DD, YYYY
Date::Date(string date)
{
    string sMonth;
    string sDay;
    string sYear;

    //Gets the month
    int i = 0;
    while(i < date.size() && date[i] != ' ')
    {
        ++i;
    }
    sMonth = date.substr(0, i);
    ++i;

    //Gets the day
    int j = i;
    while(j < date.size() && date[j] != ',')
    {
        ++j;
    }
    sDay = date.substr(i, j);
    j += 2;

    //Gets the year
    int k = j;
    while(k < date.size())
    {
        ++k;
    }
    sYear = date.substr(j, k);

    //Converts the strings to ints
    unsigned short month;
    unsigned short day;
    unsigned short year;

    if      (sMonth == "January")   month = 1;
    else if (sMonth == "February")  month = 2;
    else if (sMonth == "March")     month = 3;
    else if (sMonth == "April")     month = 4;
    else if (sMonth == "May")       month = 5;
    else if (sMonth == "June")      month = 6;
    else if (sMonth == "July")      month = 7;
    else if (sMonth == "August")    month = 8;
    else if (sMonth == "September") month = 9;
    else if (sMonth == "October")   month = 10;
    else if (sMonth == "November")  month = 11;
    else if (sMonth == "December")  month = 12;

    day = atoi(sDay.c_str());
    year = atoi(sYear.c_str());

    //Stores it in the object
    this->month = month;
    this->day   = day;
    this->year  = year;
}



/**************************************************************
* ~Date ();
*	Destructor; does not perform any specific function
* 	Parameters: none
* 	Return: none
***************************************************************/
Date::~Date()
{

}

                    /*************
                     * Mutators  *
                     *************/
/**************************************************************
* void SetDate(unsigned short year,
*			   unsigned short month,
*			   unsigned short day);
*	Mutators; Sets animals name
* 	Parameters: year, month, day
* 	Return: None
***************************************************************/
void Date::SetDate(unsigned short year,
                   unsigned short month,
                   unsigned short day)
{
    if (ValidateDate(year, month, day))
    {
        this->year = year;
        this->month = month;
        this->day = day;
    }
    else
    {
        throw(INVALID_DATE());
    }
}

                    /*************
                     * Accessors *
                     *************/
/**************************************************************
* void GetDate(unsigned short &year,
*			   unsigned short &month,
*			   unsigned short &day) const;
*	Accessor; gets year, month, day
* 	Parameters: year, month, day
* 	Return: year, month, day
***************************************************************/
void Date::GetDate(unsigned short &year,
                   unsigned short &month,
                   unsigned short &day) const
{
    year  = this->year;
    month = this->month;
    day   = this->day;
}

/**************************************************************
* string DisplayDate() const;
*	Accessor; displays date in MM/DD/YYYY format
* 	Parameters: none
* 	Return: date as string
***************************************************************/
string Date::Display() const
{
    ostringstream out;

    out << right;

    //Outputs the month
    if(month < 10)
    {
        out << "0";
    }
    out << month << "/";

    //Outputs the day
    if(day < 10)
    {
        out << "0";
    }
    out << day << "/";

    //Outputs the year
    out << year;

    return out.str();
}

                        /*************
                         * UTILITIES *
                         *************/
/**************************************************************
* unsigned short GetDaysInMonth(unsigned short year,
                                unsigned short month) const;
*	Accessor; gets days in indicated month
* 	Parameters: year, month
* 	Return: days in the month
***************************************************************/
unsigned short Date::GetDaysInMonth(unsigned short year,
                                    unsigned short month) const
{
    unsigned short daysInMonth;

    daysInMonth = 0;

    if (month == 1  || month == 3  || month == 5  || month == 7  ||
        month == 8  || month == 10 || month == 12)
    {
        daysInMonth = 31;
    }
    else if (month == 4  || month == 6  ||
             month == 9  || month == 11)
    {
        daysInMonth = 30;
    }
    else if(month == 2)
    {
        if(IsLeapYear(year))
        {
            daysInMonth = 29;
        }
        else
        {
            daysInMonth = 28;
        }
    }

    return daysInMonth;
}

/**************************************************************
* IsLeapYear(unsigned short year) const
*	Accessor; check whether or not indicated year is a leap year
* 	Parameters: year
* 	Return: bool indiating leap year or not
***************************************************************/
bool Date::IsLeapYear(unsigned short year) const
{
    return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

                        /*************
                         * VALIDATES *
                         *************/
/**************************************************************
* bool ValidateYear(unsigned short year) const;
*	Accessor; validates the year
* 	Parameters: year
* 	Return: bool indicating valid year or not
***************************************************************/
bool Date::ValidateYear(unsigned short year) const
{
    unsigned short currentYear;
    time_t now;
    tm *currentTime;

    now = time(NULL);
    currentTime = localtime(&now);

    currentYear  = 1900 + currentTime -> tm_year;

    return (year >= 1900 && year <= currentYear);
}

/**************************************************************
* bool ValidateMonth(unsigned short month) const;
*	Accessor; validates the month
* 	Parameters: month
* 	Return: bool indicating valid month or not
***************************************************************/
bool Date::ValidateMonth(unsigned short month) const
{
    return (month >= 1 && month <= 12);
}

/**************************************************************
* bool ValidateDay(unsigned short year,
                   unsigned short month,
                   unsigned short day) const;
*	Accessor; validates the day
* 	Parameters: year, month, day
* 	Return: bool indicating valid day or not
***************************************************************/
bool Date::ValidateDay(unsigned short year,
                       unsigned short month,
                       unsigned short day) const
{
    return (day >= 1 && day <= GetDaysInMonth(year, month));
}

/**************************************************************
* bool ValidateDate(unsigned short year,
                   unsigned short month,
                   unsigned short day) const;
*	Accessor; validates the passed in date against current day
* 	Parameters: year, month, day
* 	Return: bool indicating valid date or not
***************************************************************/
bool Date::ValidateDate(unsigned short year,
                        unsigned short month,
                        unsigned short day) const
{
    bool valid;
    unsigned short currentYear;
    unsigned short currentMonth;
    unsigned short currentDay;

    time_t now;
    tm *currentTime;

    valid = false;
    now = time(NULL);
    currentTime = localtime(&now);

    currentYear  = 1900 + currentTime -> tm_year;
    currentMonth = 1 + currentTime -> tm_mon;
    currentDay   = currentTime -> tm_mday;

    if (ValidateYear (year)  &&
        ValidateMonth(month) &&
        ValidateDay  (year, month, day))
    {
        if (year == currentYear)
        {
            if (month == currentMonth)
            {
                if (day <= currentDay)
                {
                    valid = true;
                }
            }
            else if (month < currentMonth)
            {
                valid = true;
            }
        }
        else if (year < currentYear)
        {
            valid = true;
        }
    }

    return valid;
}

/**************************************************************
* unsigned short GetDaysSince(unsigned short year,
*				    		  unsigned short month,
*				    		  unsigned short day) const;
*	Accessor; determines the amount of days that have passsed
*			  since the date passed in
* 	Parameters: fromYear, fromMonth, fromDay
* 	Return: the number of days that have passed
***************************************************************/
unsigned short Date::GetDaysSince(unsigned short fromYear,
                                  unsigned short fromMonth,
                                  unsigned short fromDay) const
{
    unsigned short daysSince;
    unsigned short loopMonth;
    unsigned short loopYear;
    daysSince = 0;

    if(ValidateDate(fromYear, fromMonth, fromDay))
    {
        if (fromYear == year)
        {
            if (fromMonth == month)
            {
                if (fromDay <= day)
                {
                    daysSince = day - fromDay;
                }
            }
            else if (fromMonth < month)
            {
                //Adds the days left in the fromMonth to daysSince
                daysSince += (GetDaysInMonth(fromYear, fromMonth) - fromDay);

                //Adds the days in all the in-between months
                for(loopMonth = fromMonth + 1; loopMonth < month; loopMonth++)
                {
                    daysSince += GetDaysInMonth(fromYear, loopMonth);
                }

                //Adds the days in the current month
                daysSince += day;
            }
        }
        else if (fromYear < year)
        {
            //Adds the days left in the fromMonth to daysSince
            daysSince += (GetDaysInMonth(fromYear, fromMonth) - fromDay);

            //Adds the days left in the year
            for(loopMonth = fromMonth + 1; loopMonth <= 12; loopMonth++)
            {
                daysSince += GetDaysInMonth(fromYear, loopMonth);
            }

            //Adds the days from all the in-between years
            for(loopYear = fromYear + 1; loopYear < year; loopYear++)
            {
                for(loopMonth = 1; loopMonth <= 12; loopMonth++)
                {
                    daysSince += GetDaysInMonth(fromYear, loopMonth);
                }
            }

            //Adds the days from the current year
            for(loopMonth = 1; loopMonth < month; loopMonth++)
            {
                daysSince += GetDaysInMonth(fromYear, loopMonth);
            }
        }
    }

    return daysSince;
}

/**************************************************************
* unsigned short GetMonthsSince(unsigned short year,
*				    		    unsigned short month,
*				    		    unsigned short day) const;
*	Accessor; determines the amount of months that have passsed
*			  since the date passed in
* 	Parameters: fromYear, fromMonth, fromDay
* 	Return: the number of months that have passed
***************************************************************/
unsigned short Date::GetMonthsSince(unsigned short currentYear,
                                    unsigned short currentMonth,
                                    unsigned short currentDay) const
{
    unsigned short monthsSince;
    monthsSince = 0;

    //If it's a valid date
    if(ValidateDate(currentYear, currentMonth, currentDay))
    {
        monthsSince = (currentMonth + ((currentYear - year) * 12) - month);

        if(day > currentDay)
        {
            monthsSince--;
        }
    }

    return monthsSince;
}

/**************************************************************
* unsigned short GetMonthsSince(unsigned short year,
*				    		    unsigned short month,
*				    		    unsigned short day) const;
*	Accessor; determines the amount of months that have passsed
*			  since the date passed in
* 	Parameters: currentDate
* 	Return: the number of months that have passed
***************************************************************/
unsigned short Date::GetMonthsSince(Date currentDate) const
{
    unsigned short monthsSince;
    unsigned short currentYear;
    unsigned short currentMonth;
    unsigned short currentDay;

    currentDate.GetDate(currentYear, currentMonth, currentDay);
    monthsSince = 0;

    //If it's a valid date
    if(ValidateDate(currentYear, currentMonth, currentDay))
    {
        monthsSince = (currentMonth + ((currentYear - year) * 12) - month);

        if(day > currentDay)
        {
            monthsSince--;
        }
    }
    else
    {
        throw(INVALID_DATE());
    }

    return monthsSince;
}

/**************************************************************
* unsigned short GetMonthsSince() const;
*	Accessor; determines the amount of months that have passsed
*			  since the date passed in
* 	Parameters: none
* 	Return: the number of months that have passed
***************************************************************/
unsigned short Date::GetMonthsPassed() const
{
    time_t now;
    tm *currentTime;
    unsigned short monthsSince;

    now = time(NULL);
    currentTime = localtime(&now);
    monthsSince = 0;

    monthsSince = (currentTime->tm_mon + ((currentTime->tm_year - year) * 12) -
                   month);

    if(day > currentTime->tm_mday)
    {
        monthsSince--;
    }

    return monthsSince;
}

/**************************************************************
* bool Compare(Date lhs,
*              Date rhs) const;
*	Accessor; compares the two elements passed in
* 	Parameters: lhs, rhs
* 	Return: true if lhs happened longer ago than rhs
***************************************************************/
bool Date::Compare(Date lhs,
                   Date rhs)
{
    bool result = false;

    unsigned short lhsDay;
    unsigned short lhsMonth;
    unsigned short lhsYear;

    unsigned short rhsDay;
    unsigned short rhsMonth;
    unsigned short rhsYear;

    lhs.GetDate(lhsYear, lhsMonth, lhsDay);
    rhs.GetDate(rhsYear, rhsMonth, rhsDay);

    if(lhsYear < rhsYear)
    {
        result = true;
    }
    else if(lhsYear == rhsYear)
    {
        if(lhsMonth < rhsMonth)
        {
            result = true;
        }
        else if(lhsMonth == rhsMonth)
        {
            if(lhsDay < rhsDay)
            {
                result = true;
            }
        }
    }

    return result;
}
