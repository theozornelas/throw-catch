#ifndef TEST2CLASS_H
#define TEST2CLASS_H

#include "testrunner.h"
#include <QObject>
#include <QString>
#include "skiplist.h"
#include "entry.h"
#include "stadium.h"

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
    void init();
    // Called after every test function
    void cleanup();

    /*** TESTS FOR THE CLASS ***/
    void test_insert(); // tests to make sure all numbers are added and are sorted.
    void test_erase();  // tests the erase() method
    void test_get();    // Tests the get() method
    void test_size();   // Tests the size() method
    void test_constructObjList();   // Tests making a list of souvenier objects

private:
    skiplist<int, QString>* list_;      //< The skip list for testing
    skiplist<int, Stadium>* StadList_; //< THe list of objects to test
};

/********************************************************************************************
 *                         IMPLEMENTATION OF SETUP / TEARDOWN METHODS
 ********************************************************************************************/

void SkipListTests::init() {
    list_ = new skiplist<int, QString>;
    list_->insert(3, "3");
    list_->insert(6, "6");
    list_->insert(4, "4");
    list_->insert(1, "1");
    list_->insert(5, "5");
    list_->insert(2, "2");
}

// empties the list for the next test
void SkipListTests::cleanup() {
    delete list_;
}

/********************************************************************************************
 *                                  IMPLEMENTATION OF TESTS
 ********************************************************************************************/

// Tests making a list of objects
void SkipListTests::test_constructObjList() {
    StadList_ = new skiplist<int, Stadium>;
    Stadium dodgers(5, "Dodgers Stadium", "Dodgers", "1st Ave", "Los Angeles","CA",
                       "92671", "Number", "24-AUG-1980", 501234,
                       "Astroturf", "American", "Retro", 0);

    StadList_->insert(1, dodgers);
}

// Tests adding to the list by ensuring that everything is added in the proper order
void SkipListTests::test_insert() {
    skiplist<int, QString>::Iterator itr = list_->begin();
    for(int i = 1; i <= 6; i++){
        QCOMPARE(*itr, QString::number(i));
        itr++;
    }
}

// Tests the erase method by inserting a variety of values and then erasing one
void SkipListTests::test_erase() {
    // erase two elemetns and size should be 4
    list_->erase(3);
    list_->erase(5);
    QCOMPARE(4, list_->size());

    // erase three more elements and size should be 1
    list_->erase(1);
    list_->erase(2);
    list_->erase(4);
    QCOMPARE(1, list_->size());

    // erasing non-existing element should not change the size
    list_->erase(10);
    QCOMPARE(1, list_->size());

    // erasing the last element should give us a size of zero
    list_->erase(6);
    QCOMPARE(0, list_->size());

    // erasing non-existing element should not change the size
    list_->erase(10);
    QCOMPARE(0, list_->size());
}

// Test the get method by getting multiple key and checking the values
void SkipListTests::test_get(){
    QCOMPARE(QString("5"), *(list_->get(5)) );
    QCOMPARE(QString("4"), *(list_->get(4)) );
    QCOMPARE(QString("6"), *(list_->get(6)) );
    QCOMPARE(QString("1"), *(list_->get(1)) );
    QCOMPARE(QString("2"), *(list_->get(2)) );
    QCOMPARE(QString("3"), *(list_->get(3)) );
}

// Tests the size mehtod by checking the size of the list
void SkipListTests::test_size() {
    QVERIFY2(list_->size() == 6, "Size of the list is not right!");
}

/*** THIS ADDS THE TEST TO THE LIST OF CLASSES TO RUN ***/
DECLARE_TEST(SkipListTests)
#endif // TEST2CLASS_H
