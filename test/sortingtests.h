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
    void test_SortIntegersWithComparator();
    void test_SortDates();
    void test_SortDatesWithComparator();
    void test_SortStadiums();
    void test_SortStadiumsWithComparator();



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
    QuickSort(testVector, 0, testVector.size()-1);

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
    QuickSort(testVector, 0, testVector.size()-1, std::greater<int>());

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
    QuickSort(testVector, 0, testVector.size()-1);

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
    QuickSort(testVector, 0, testVector.size()-1, std::greater<QDate>());

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
    QuickSort(testVector, 0, testVector.size()-1);

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
    QuickSort(testVector, 0, testVector.size()-1, std::greater<Stadium>());

    // Checks to see if it sorted properly
    for(int i = 0; i < testVector.size()-1; ++i) {
        QVERIFY(testVector[i] >= testVector[i+1]);
    }
}

///*********************************************************************
// * Tests sorting a QVector on an int, QDate, Stadium, and Edge of various types using the QuickSort
// * function with a comparator.
// *
// * FAILS IF: - The QVectors are not sorted from greatest to least
// *********************************************************************/
//void SortingTests::test_SortWithComparator() {

//    // Initializes the int vector
//    srand(time(NULL));
//    QVector<int> intVector;
//    int temp;
//    for(int i = 0; i < 100; ++i) {
//        temp = rand() % 100;
//        intVector.push_back(temp);
//    }

//    // Initializes the Date vector
//    QVector<QDate> dateVector;
//    dateVector.push_back(QDate(2015, 10, 5));
//    dateVector.push_back(QDate(2008, 10, 5));
//    dateVector.push_back(QDate(2009, 10, 5));
//    dateVector.push_back(QDate(2007, 1, 15));
//    dateVector.push_back(QDate(2007, 2, 5));
//    dateVector.push_back(QDate(2007, 6, 20));
//    dateVector.push_back(QDate(2007, 1, 1));

//    // Initializes the Stadium Vector
//    QVector<Stadium> stadiumVector;
//    stadiumVector.push_back(Stadium(11));
//    stadiumVector.push_back(Stadium(22));
//    stadiumVector.push_back(Stadium(33));
//    stadiumVector.push_back(Stadium(44));
//    stadiumVector.push_back(Stadium(55));
//    stadiumVector.push_back(Stadium(66));
//    stadiumVector.push_back(Stadium(77));
//    stadiumVector.push_back(Stadium(88));
//    stadiumVector.push_back(Stadium(99));

//    // Sorts the vectors
//    QuickSort(intVector, 0, intVector.size()-1, std::greater<int>());
//    QuickSort(dateVector, 0, dateVector.size()-1, std::greater<QDate>());
//    QuickSort(stadiumVector, 0, stadiumVector.size()-1, std::greater<Stadium>());

//    // Checks to see they were sorted properly
//    for(int i = 0; i < intVector.size()-1; ++i) {
//        QVERIFY(intVector[i] >= intVector[i+1]);
//    }

//    for(int i = 0; i < dateVector.size()-1; ++i) {
//        QVERIFY(dateVector[i] >= dateVector[i+1]);
//    }

//    for(int i = 0; i < stadiumVector.size()-1; ++i) {
//        QVERIFY(stadiumVector[i] >= stadiumVector[i+1]);
//    }

//}

/*** THIS ADDS THE TEST TO THE LIST OF CLASSES TO RUN ***/
DECLARE_TEST(SortingTests)

#endif // SORTINGTESTS

