#ifndef TEST2CLASS_H
#define TEST2CLASS_H

#include "TestRunner.h"
#include <QObject>

class TestingSuiteTwo : public QObject
{
 Q_OBJECT
private slots:
    /*** GENERAL TEST SETUP AND TEARDOWN ***/
    // Called before every test, if it fails then the NEXT test does not run
    void initTestCase() { qDebug("initTestCase() is called before each test!"); }
    // Called after the last test function was executed.
    void cleanupTestCase() {}

    /*** PER-TEST SETUP AND TEARDOWN ***/
    // Called before the first test function is executed. If this fails no tests are run
    void init() { qDebug("init() is called before every function!"); }
    // Called after every test function
    void cleanup() { qDebug("cleanup() runs after every test!"); }

    /*** TESTS FOR THE CLASS ***/
    //void initTest();
    void testingTest() { qDebug("*** RUNNING THE ACTUAL TEST ***"); QVERIFY(true); }

};

DECLARE_TEST(TestingSuiteTwo)

#endif // TEST2CLASS_H
