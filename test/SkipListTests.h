#ifndef TEST2CLASS_H
#define TEST2CLASS_H

#include "TestRunner.h"
#include <QObject>
#include <QString>
#include "skiplist.h"

class SkipListTests : public QObject
{
 Q_OBJECT
private slots:
    /*** SPECIAL TEST SETUP AND TEARDOWN METHODS ***/
    // Called before the first test function is executed. If this fails no tests are run
    //void initTestCase();
    // Called after the last test function was executed.
    //void cleanupTestCase();
    // Called before every test, if it fails then the NEXT test does not run
    //void init();
    // Called after every test function
    //void cleanup();

    /*** TESTS FOR THE CLASS ***/
    void testAdd();

private:
    skiplist<int, QString> list_;   //< The skip list for testing

};

/********************************************************************************************
 *                                  IMPLEMENTATION OF TESTS
 ********************************************************************************************/

// Tests adding to the list by ensuring that everything is added in the proper order
void SkipListTests::testAdd() {
    list_.insert(3, "3");
    list_.insert(6, "6");
    list_.insert(4, "4");
    list_.insert(1, "1");
    list_.insert(5, "5");
    list_.insert(2, "2");

    skiplist<int, QString>::Iterator itr = list_.begin();
    for(int i = 1; i <= 6; i++){
        QCOMPARE(*itr, QString::number(i));
        itr++;
    }
}

/********************************************************************************************
 *                         IMPLEMENTATION OF SETUP / TEARDOWN METHODS
 ********************************************************************************************/


/*** THIS ADDS THE TEST TO THE LIST OF CLASSES TO RUN ***/
DECLARE_TEST(SkipListTests)
#endif // TEST2CLASS_H
