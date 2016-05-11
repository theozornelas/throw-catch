#ifndef SORTINGTESTS
#define SORTINGTESTS

#include "testrunner.h"
#include <QObject>
#include <QString>
#include <QList>
#include "mainwindow.h"


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
    void test_SortIntegers();
    void test_SortDates();



private:
    template <typename E>
    static void QuickSort(QVector<E> &vecToSort, int left, int right);

};



template <typename E>
void SortingTests::QuickSort(QVector<E> &vecToSort, int left, int right)
{
    int i = left;
    int j = right;
    E temp;

    //Finds the pivot
    E pivot = vecToSort[(left + right) / 2];

    //Sorts the vector
    while(i <= j)
    {
        while(vecToSort[i] < pivot)
        {
            ++i;
        }
        while(vecToSort[j] > pivot)
        {
            --j;
        }
        if(i <= j)
        {
            temp = vecToSort[i];
            vecToSort[i] = vecToSort[j];
            vecToSort[j] = temp;
            ++i;
            --j;
        }
    }

    if(left < j)
    {
        QuickSort(vecToSort, left, j);
    }
    if(i < right)
    {
        QuickSort(vecToSort, i, right);
    }
}

/********************************************************************************************
 *                         IMPLEMENTATION OF SETUP / TEARDOWN METHODS
 ********************************************************************************************/

void SortingTests::init() {

}

void SortingTests::cleanup() {

}

void SortingTests::test_SortIntegers() {

    //Initializes the QVectors
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

void SortingTests::test_SortDates() {

    //Initializes the QVectors
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
        qDebug() << testVector[i];
        QVERIFY(testVector[i] <= testVector[i+1]);
    }
}

/*** THIS ADDS THE TEST TO THE LIST OF CLASSES TO RUN ***/
DECLARE_TEST(SortingTests)

#endif // SORTINGTESTS

