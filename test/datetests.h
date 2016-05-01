#ifndef DATETESTS_H
#define DATETESTS_H

#include "testrunner.h"
#include <QObject>
#include <QString>
#include "date.h"
#include "entry.h"
#include "stadium.h"

class DateTests : public QObject
{
 Q_OBJECT
private slots:
    void init();
    void cleanup();

    /*** TESTS FOR THE CLASS ***/
    void test_stringConstructor();
    void test_compare();

private:
//    Date *testDate; //The date for testing
};

/********************************************************************************************
 *                         IMPLEMENTATION OF SETUP / TEARDOWN METHODS
 ********************************************************************************************/

void DateTests::init()
{
//    testDate = new Date(2015, 3, 14);
}

void DateTests::cleanup()
{
//    delete testDate;
}

void DateTests::test_stringConstructor()
{
    //Tests a date from every month
    Date date1("January 1, 2015");
    QVERIFY(date1.GetMonth() == 1);
    QVERIFY(date1.GetDay() == 1);
    QVERIFY(date1.GetYear() == 2015);

    Date date2("February 2, 2015");
    QVERIFY(date2.GetMonth() == 2);
    QVERIFY(date2.GetDay() == 2);
    QVERIFY(date2.GetYear() == 2015);

    Date date3("March 14, 2015");
    QVERIFY(date3.GetMonth() == 3);
    QVERIFY(date3.GetDay() == 14);
    QVERIFY(date3.GetYear() == 2015);

    Date date4("April 4, 2015");
    QVERIFY(date4.GetMonth() == 4);
    QVERIFY(date4.GetDay() == 4);
    QVERIFY(date4.GetYear() == 2015);

    Date date5("May 5, 2015");
    QVERIFY(date5.GetMonth() == 5);
    QVERIFY(date5.GetDay() == 5);
    QVERIFY(date5.GetYear() == 2015);

    Date date6("June 6, 2015");
    QVERIFY(date6.GetMonth() == 6);
    QVERIFY(date6.GetDay() == 6);
    QVERIFY(date6.GetYear() == 2015);

    Date date7("July 7, 2015");
    QVERIFY(date7.GetMonth() == 7);
    QVERIFY(date7.GetDay() == 7);
    QVERIFY(date7.GetYear() == 2015);

    Date date8("August 8, 2015");
    QVERIFY(date8.GetMonth() == 8);
    QVERIFY(date8.GetDay() == 8);
    QVERIFY(date8.GetYear() == 2015);

    Date date9("September 9, 2015");
    QVERIFY(date9.GetMonth() == 9);
    QVERIFY(date9.GetDay() == 9);
    QVERIFY(date9.GetYear() == 2015);

    Date date10("October 10, 2015");
    QVERIFY(date10.GetMonth() == 10);
    QVERIFY(date10.GetDay() == 10);
    QVERIFY(date10.GetYear() == 2015);

    Date date11("November 11, 2015");
    QVERIFY(date11.GetMonth() == 11);
    QVERIFY(date11.GetDay() == 11);
    QVERIFY(date11.GetYear() == 2015);

    Date date12("December 12, 2015");
    QVERIFY(date12.GetMonth() == 12);
    QVERIFY(date12.GetDay() == 12);
    QVERIFY(date12.GetYear() == 2015);
}

//This tests all of the combinations of possible dates to compare.
// They are compared for both their true and false conditions
// The compare() function should return true if the first date is
// earlier than the second date
void DateTests::test_compare()
{
    //Different year, month, and day
    Date *olderDate = new Date("January 1, 2010");
    Date *newerDate = new Date("March 13, 2015");
    QCOMPARE(Date::Compare(*newerDate, *olderDate), true);
    QCOMPARE(Date::Compare(*olderDate, *newerDate), false);
    delete olderDate;
    delete newerDate;

    //Different year and month, same day
    olderDate = new Date("January 13, 2010");
    newerDate = new Date("March 13, 2015");
    QCOMPARE(Date::Compare(*newerDate, *olderDate), true);
    QCOMPARE(Date::Compare(*olderDate, *newerDate), false);
    delete olderDate;
    delete newerDate;

    //Different year and day, same month
    olderDate = new Date("March 1, 2010");
    newerDate = new Date("March 13, 2015");
    QCOMPARE(Date::Compare(*newerDate, *olderDate), true);
    QCOMPARE(Date::Compare(*olderDate, *newerDate), false);
    delete olderDate;
    delete newerDate;

    //Different month and day, same year
    olderDate = new Date("January 11, 2015");
    newerDate = new Date("March 13, 2015");
    QCOMPARE(Date::Compare(*newerDate, *olderDate), true);
    QCOMPARE(Date::Compare(*olderDate, *newerDate), false);
    delete olderDate;
    delete newerDate;

    //Different year, same day and month
    olderDate = new Date("March 13, 2010");
    newerDate = new Date("March 13, 2015");
    QCOMPARE(Date::Compare(*newerDate, *olderDate), true);
    QCOMPARE(Date::Compare(*olderDate, *newerDate), false);
    delete olderDate;
    delete newerDate;

    //Different month, same day and year
    olderDate = new Date("March 13, 2010");
    newerDate = new Date("March 13, 2015");
    QCOMPARE(Date::Compare(*newerDate, *olderDate), true);
    QCOMPARE(Date::Compare(*olderDate, *newerDate), false);
    delete olderDate;
    delete newerDate;

    //Different day, month and year
    olderDate = new Date("January 1, 2015");
    newerDate = new Date("March 13, 2015");
    QCOMPARE(Date::Compare(*newerDate, *olderDate), true);
    QCOMPARE(Date::Compare(*olderDate, *newerDate), false);
    delete olderDate;
    delete newerDate;

    //Same year, month, and day - Should be false
    olderDate = new Date("March 13, 2015");
    newerDate = new Date("March 13, 2015");
    QCOMPARE(Date::Compare(*newerDate, *olderDate), false);
    QCOMPARE(Date::Compare(*olderDate, *newerDate), true);
    delete olderDate;
    delete newerDate;
}


/*** THIS ADDS THE TEST TO THE LIST OF CLASSES TO RUN ***/
DECLARE_TEST(DateTests)

#endif // DATETESTS_H
