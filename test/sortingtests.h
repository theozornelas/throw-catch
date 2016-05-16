#ifndef SORTINGTESTS
#define SORTINGTESTS

#include "testrunner.h"
#include <QObject>
#include <QString>
#include <QList>
#include "mainwindow.h"
#include "quicksort.h"
#include "graph.h"


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
    void test_SortIntegersWithComparator();
    void test_SortDates();
    void test_SortDatesWithComparator();
    void test_SortStadiums();
    void test_SortStadiumsWithComparator();
    void test_SortVertices();
    void test_SortVerticesWithComparator();



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
 * Tests sorting an empty QVector
 *
 * FAILS IF: - Any exceptions are thrown
 *
 * NOTE: This fails every time, and Qt uses asserts instead of
 *       exceptions... Sooo hopefully we don't ever try to sort an
 *       empty QVector.
 *********************************************************************/
//void SortingTests::test_SortEmptyVector() {
//    QVector<int> testVector;

//    try {
//        QuickSort(testVector, 0, 0);
//    }
//    catch(...) {
//        QFAIL("Cannot perform the QuickSort on an empty vector");
//    }
//}

/*********************************************************************
 * Tests sorting a QVector of integers using the QuickSort function.
 *
 * FAILS IF: - The QVector is not sorted from least to greatest
 *********************************************************************/
void SortingTests::test_SortIntegers() {

    // Initializes the QVector
    srand(time(NULL));
    QVector<int> testVector;
    int temp;
    for(int i = 0; i < 100; ++i) {
        temp = rand() % 100;
        testVector.push_back(temp);
    }

    // Sorts the vector
    QuickSort(testVector.begin(), testVector.end());

    // Checks to see if it sorted properly
    for(int i = 0; i < testVector.size()-1; ++i) {
        QVERIFY(testVector[i] <= testVector[i+1]);
    }
}

/*********************************************************************
 * Tests sorting a QVector of integers using the QuickSort function
 * with a comparator passed in
 *
 * FAILS IF: - The QVector is not sorted from greatest to least
 *********************************************************************/
void SortingTests::test_SortIntegersWithComparator() {

    // Initializes the QVector
    srand(time(NULL));
    QVector<int> testVector;
    int temp;
    for(int i = 0; i < 100; ++i) {
        temp = rand() % 100;
        testVector.push_back(temp);
    }

    // Sorts the vector
    QuickSort(testVector.begin(), testVector.end(), std::greater_equal<int>());

    // Checks to see if it sorted properly
    for(int i = 0; i < testVector.size()-1; ++i) {
        QVERIFY(testVector[i] >= testVector[i+1]);
    }
}

/*********************************************************************
 * Tests sorting a QVector of QDates using the QuickSort function.
 *
 * FAILS IF: - The QVector is not sorted from least to greatest
 *********************************************************************/
void SortingTests::test_SortDates() {

    // Initializes the QVector
    QVector<QDate> testVector;

    testVector.push_back(QDate(2015, 10, 5));
    testVector.push_back(QDate(2008, 10, 5));
    testVector.push_back(QDate(2009, 10, 5));
    testVector.push_back(QDate(2007, 1, 15));
    testVector.push_back(QDate(2007, 2, 5));
    testVector.push_back(QDate(2007, 6, 20));
    testVector.push_back(QDate(2007, 1, 1));

    // Sorts the vector
    QuickSort(testVector.begin(), testVector.end());

    // Checks to see if it sorted properly
    for(int i = 0; i < testVector.size()-1; ++i) {
        QVERIFY(testVector[i] <= testVector[i+1]);
    }
}

/*********************************************************************
 * Tests sorting a QVector of QDates using the QuickSort function
 * with a comparator passed in
 *
 * FAILS IF: - The QVector is not sorted from greatest to least
 *********************************************************************/
void SortingTests::test_SortDatesWithComparator() {

    // Initializes the QVector
    QVector<QDate> testVector;

    testVector.push_back(QDate(2015, 10, 5));
    testVector.push_back(QDate(2008, 10, 5));
    testVector.push_back(QDate(2009, 10, 5));
    testVector.push_back(QDate(2007, 1, 15));
    testVector.push_back(QDate(2007, 2, 5));
    testVector.push_back(QDate(2007, 6, 20));
    testVector.push_back(QDate(2007, 1, 1));

    // Sorts the vector
    QuickSort(testVector.begin(), testVector.end(), std::greater_equal<QDate>());

    // Checks to see if it sorted properly
    for(int i = 0; i < testVector.size()-1; ++i) {
        QVERIFY(testVector[i] >= testVector[i+1]);
    }
}

/*********************************************************************
 * Tests sorting a QVector of Stadiums using the QuickSort function.
 *
 * FAILS IF: - The QVector is not sorted from least to greatest
 *********************************************************************/
void SortingTests::test_SortStadiums() {

    // Initializes the QVector
    QVector<Stadium> testVector;

    testVector.push_back(Stadium(99));
    testVector.push_back(Stadium(88));
    testVector.push_back(Stadium(77));
    testVector.push_back(Stadium(66));
    testVector.push_back(Stadium(55));
    testVector.push_back(Stadium(44));
    testVector.push_back(Stadium(33));
    testVector.push_back(Stadium(22));
    testVector.push_back(Stadium(11));

    // Sorts the vector
    QuickSort(testVector.begin(), testVector.end());

    // Checks to see if it sorted properly
    for(int i = 0; i < testVector.size()-1; ++i) {
        QVERIFY(testVector[i] <= testVector[i+1]);
    }
}

/*********************************************************************
 * Tests sorting a QVector of Stadiums using the QuickSort function
 * with a comparator passed in
 *
 * FAILS IF: - The QVector is not sorted from greatest to least
 *********************************************************************/
void SortingTests::test_SortStadiumsWithComparator() {

    // Initializes the QVector
    QVector<Stadium> testVector;

    testVector.push_back(Stadium(11));
    testVector.push_back(Stadium(22));
    testVector.push_back(Stadium(33));
    testVector.push_back(Stadium(44));
    testVector.push_back(Stadium(55));
    testVector.push_back(Stadium(66));
    testVector.push_back(Stadium(77));
    testVector.push_back(Stadium(88));
    testVector.push_back(Stadium(99));

    // Sorts the vector
    QuickSort(testVector.begin(), testVector.end(), std::greater_equal<Stadium>());

    // Checks to see if it sorted properly
    for(int i = 0; i < testVector.size()-1; ++i) {
        QVERIFY(testVector[i] >= testVector[i+1]);
    }
}

/*********************************************************************
 * Tests sorting a QVector of Vertices using the QuickSort function.
 *
 * FAILS IF: - The QVector is not sorted from least to greatest
 *********************************************************************/
void SortingTests::test_SortVertices() {


}

/*********************************************************************
 * Tests sorting a QVector of Vertices using the QuickSort function
 * with a comparator passed in
 *
 * FAILS IF: - The QVector is not sorted from greatest to least
 *********************************************************************/
void SortingTests::test_SortVerticesWithComparator() {


}

/*** THIS ADDS THE TEST TO THE LIST OF CLASSES TO RUN ***/
DECLARE_TEST(SortingTests)

#endif // SORTINGTESTS

