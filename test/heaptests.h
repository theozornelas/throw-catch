#ifndef HEAPTESTS
#define HEAPTESTS

#include "testrunner.h"
#include <QObject>
#include <QString>
#include <QList>
#include "heap.h"
#include ""


class HeapTests : public QObject
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
    void test_HeapSortIntegers();

private:

};

/********************************************************************************************
 *                         IMPLEMENTATION OF SETUP / TEARDOWN METHODS
 ********************************************************************************************/

void HeapTests::init() {

}

void HeapTests::cleanup() {

}

void HeapTests::test_HeapSortIntegers() {

    //Initializes the QVectors
    srand(time(NULL));
    QVector<int> originalVector;
    QVector<int> sortedVector;
    int temp;
    for(int i = 0; i < 100; ++i) {
        temp = rand();
        originalVector.push_back(temp);
        sortedVector.push_back(temp);
    }

    //Sorts the vector

    //Checks to see if it sorted properly
    QVERIFY(originalVector == sortedVector);
}


#endif // HEAPTESTS

