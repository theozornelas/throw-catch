#ifndef SORTINGTESTS
#define SORTINGTESTS

#include "testrunner.h"
#include <QObject>
#include <QString>
#include <QList>
#include "mainwindow.h"
#include "quicksort.h"


class SortingTests : public QObject
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
//    void test_SortEmptyVector();
    void test_SortIntegers();
    void test_SortDates();
//    void test_SortStadiums();



private:

};

/********************************************************************************************
 *                         IMPLEMENTATION OF SETUP / TEARDOWN METHODS
 ********************************************************************************************/

void SortingTests::init() {

}

void SortingTests::cleanup() {

}

/********************************************************************************************
 *                                  IMPLEMENTATION OF TESTS
 ********************************************************************************************/

/*********************************************************************
 * Tests sorting a QVector of integers using the QuickSort function.
 *
 * FAILS IF: - The QVector is not sorted from least to greatest
 *********************************************************************/
void SortingTests::test_SortIntegers() {

    //Initializes the QVector
    srand(time(NULL));
    QVector<int> originalVector;
    QVector<int> testVector;
    int temp;
    for(int i = 0; i < 100; ++i) {
        temp = rand() % 100;
        originalVector.push_back(temp);
        testVector.push_back(temp);
    }

    //Sorts the vector
    QuickSort(testVector, 0, testVector.size()-1);

    //Checks to see if it sorted properly
    for(int i = 0; i < testVector.size()-1; ++i) {
        QVERIFY(testVector[i] <= testVector[i+1]);
    }
}

/*********************************************************************
 * Tests sorting a QVector of QDates using the QuickSort function.
 *
 * FAILS IF: - The QVector is not sorted from least to greatest
 *********************************************************************/
void SortingTests::test_SortDates() {

    //Initializes the QVector
    QVector<QDate> testVector;

    testVector.push_back(QDate(2015, 10, 5));
    testVector.push_back(QDate(2008, 10, 5));
    testVector.push_back(QDate(2009, 10, 5));
    testVector.push_back(QDate(2007, 1, 15));
    testVector.push_back(QDate(2007, 2, 5));
    testVector.push_back(QDate(2007, 6, 20));
    testVector.push_back(QDate(2007, 1, 1));

    //Sorts the vector
    QuickSort(testVector, 0, testVector.size()-1);

    //Checks to see if it sorted properly
    for(int i = 0; i < testVector.size()-1; ++i) {
        QVERIFY(testVector[i] <= testVector[i+1]);
    }
}

/*** THIS ADDS THE TEST TO THE LIST OF CLASSES TO RUN ***/
DECLARE_TEST(SortingTests)

#endif // SORTINGTESTS

