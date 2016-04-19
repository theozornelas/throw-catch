#ifndef HEAPTEST_H
#define HEAPTEST_H

#include "testrunner.h"
#include <QObject>
#include <QString>
#include "heap.h"

class HeapTest : public QObject
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


    void test_insert();
    void test_erase();

    void test_get();    // Tests the get() method
    void test_size();   // Tests the size() method


private:
    Heap<int,QString>*list_;


};


void HeapTest::init() {
    list_ = new Heap<int, QString>;
    list_->Insert(3, "3");
    list_->Insert(6, "6");
    list_->Insert(4, "4");
    list_->Insert(1, "1");
    list_->Insert(5, "5");
    list_->Insert(2, "2");
}

// empties the list for the next test
void HeapTest::cleanup() {
    delete list_;
}

/********************************************************************************************
 *                                  IMPLEMENTATION OF TESTS
 ********************************************************************************************/

// Tests adding to the list by ensuring that everything is added in the proper order
void HeapTest::test_insert() {
   // Heap<int, QString>::iterator itr = list_->begin();
//    for(int i = 1; i <= 6; i++){
//        QCOMPARE(list_[i], QString::number(i));
//        //itr++;
//    }
}

// Tests the erase method by inserting a variety of values and then erasing one
void HeapTest::test_erase() {
    // erase two elemetns and size should be 4
    list_->removeMin();
    list_->removeMin();
    QCOMPARE(4, list_->Size());

    // erase three more elements and size should be 1
    list_->removeMin();
    list_->removeMin();
    list_->removeMin();
    QCOMPARE(1, list_->Size());

    // erasing non-existing element should not change the size
    list_->removeMin();
    QCOMPARE(0, list_->Size());

    // erasing the last element should give us a size of zero
    list_->removeMin();
    QCOMPARE(0, list_->Size());

    // erasing non-existing element should not change the size
    list_->removeMin();
    QCOMPARE(0, list_->Size());
}

// Test the get method by getting multiple key and checking the values
void HeapTest::test_get(){
//    QCOMPARE(QString("5"), list_->get(5));
//    QCOMPARE(QString("4"), list_->get(4));
//    QCOMPARE(QString("6"), list_->get(6));
//    QCOMPARE(QString("1"), list_->get(1));
//    QCOMPARE(QString("2"), list_->get(2));
//    QCOMPARE(QString("3"), list_->get(3));
}

// Tests the size mehtod by checking the size of the list
void HeapTest::test_size() {
    QVERIFY2(list_->Size() == 6, "Size of the list is not right!");
}

/*** THIS ADDS THE TEST TO THE LIST OF CLASSES TO RUN ***/
DECLARE_TEST(HeapTest)
#endif // HEAPTEST_H

