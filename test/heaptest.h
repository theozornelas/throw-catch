#ifndef HEAPTEST_H
#define HEAPTEST_H

#include <QObject>
#include <QString>
#include "heap.h"

class HeapTest
{

Q_OBJECT
private slots:
    void init();

    void cleanup();


    void test_insert();
    void test_erase();

    void test_get();    // Tests the get() method
    void test_size();   // Tests the size() method


private:
    Heap<int,QString>*list_;


};


void HeapTest::init() {
    list_ = new skiplist<int, QString>;
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
    skiplist<int, QString>::Iterator itr = list_->begin();
    for(int i = 1; i <= 6; i++){
        QCOMPARE(*itr, QString::number(i));
        itr++;
    }
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
    list_->erase(4);
    QCOMPARE(1, list_->Size());

    // erasing non-existing element should not change the size
    list_->erase(10);
    QCOMPARE(1, list_->Size());

    // erasing the last element should give us a size of zero
    list_->erase(6);
    QCOMPARE(0, list_->Size());

    // erasing non-existing element should not change the size
    list_->erase(10);
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

#endif // HEAPTEST_H

