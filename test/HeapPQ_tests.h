#ifndef HEAPPQUEUE_TESTS
#define HEAPPQUEUE_TESTS


#include "testrunner.h"
#include <QObject>
#include <QString>
#include <functional>
#include "HeapPriorityQueue.h"
#include "stadium.h"

class HeapPQ_tests : public QObject
{
    typedef HeapPriorityQueue<int, std::greater<int> >     intPQueue;
    typedef HeapPriorityQueue<QString, std::greater<QString> > stringPQueue;
    typedef HeapPriorityQueue<Stadium, std::greater<Stadium> > stadiumPQueue;
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
    void test_constructor(); // tests the creation of the tree
    void test_insert(); // tests to ensure all values are added and size is correct

private:

};

// tree constructor test
void HeapPQ_tests::test_constructor()
{
    intPQueue     queue1;
    stringPQueue  queue2;
    stadiumPQueue queue3;

    Q_ASSERT(queue1.empty());
    Q_ASSERT(queue2.empty());
    Q_ASSERT(queue3.empty());
}

// testing the insert method
void HeapPQ_tests::test_insert()
{
    intPQueue queue;
    int testData[]    = { -1, 0, 65536, 1, 1024 };
    int testExpe[]    = { -1, 0, 1, 1024, 65536 };
    const int AR_SIZE = 5;

    // fill the queue
    for(int i=0; i<AR_SIZE; i++) { queue.push(testData[i]); }

    // run tests to make sure in proper order and they are all there
    for(int i=0; i<AR_SIZE; i++) {
      QCOMPARE(queue.top(), testExpe[i]);
      queue.pop();
    }
}

/*** THIS ADDS THE TEST TO THE LIST OF CLASSES TO RUN ***/
DECLARE_TEST(HeapPQ_tests)
#endif // HEAPPQUEUE_TESTS

