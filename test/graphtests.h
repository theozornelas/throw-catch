#ifndef GRAPHTESTS_H
#define GRAPHTESTS_H

#include "testrunner.h"
#include <QObject>
#include <QString>
#include "graph.h"
#include "entry.h"
#include "stadium.h"

class GraphTests : public QObject
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
    void test_insert();     // Test the ability to insert edges with new verticies to the graph
    void test_assignment12();

private:
    Graph<QString>* stringGraph_;   //< Graph of strings
};

/********************************************************************************************
 *                         IMPLEMENTATION OF SETUP / TEARDOWN METHODS
 ********************************************************************************************/

void GraphTests::init() {
    stringGraph_ = new Graph<QString>;
}

// empties the list for the next test
void GraphTests::cleanup() {
    delete stringGraph_;
}

/********************************************************************************************
 *                                  IMPLEMENTATION OF TESTS
 ********************************************************************************************/

void GraphTests::test_insert() {
    stringGraph_->insertEdge("first", "second", 200);
    stringGraph_->insertEdge("first", "third", 300);
    stringGraph_->insertEdge("first", "fourth", 400);
    stringGraph_->insertEdge("second", "fourth", 800);
}

void GraphTests::test_assignment12()
{
    stringGraph_->insertEdge("Seattle","Chicago", 2097);
    stringGraph_->insertEdge("Seattle","Denver", 1331);
    stringGraph_->insertEdge("Seattle","San Francisco", 807);
    stringGraph_->insertEdge("San Francisco","Los Angeles", 381);
    stringGraph_->insertEdge("San Francisco","Denver", 1267);
    stringGraph_->insertEdge("Los Angeles","Denver", 1015);
    stringGraph_->insertEdge("Los Angeles","Kansas City", 1663);
    stringGraph_->insertEdge("Los Angeles","Dallas", 1435);
    stringGraph_->insertEdge("Denver","Chicago", 1003);
    stringGraph_->insertEdge("Denver","Kansas City", 599);
    stringGraph_->insertEdge("Chicago","Kansas City", 533);
    stringGraph_->insertEdge("Chicago","Boston", 983);
    stringGraph_->insertEdge("Chicago","New York", 787);
    stringGraph_->insertEdge("Kansas City","Dallas", 496);
    stringGraph_->insertEdge("Kansas City","New York", 1260);
    stringGraph_->insertEdge("Kansas City","Atlanta", 864);
    stringGraph_->insertEdge("Dallas","Houston", 239);
    stringGraph_->insertEdge("Dallas","Atlanta", 781);
    stringGraph_->insertEdge("Houston","Atlanta", 810);
    stringGraph_->insertEdge("Houston","Miami", 1187);
    stringGraph_->insertEdge("Atlanta","Miami", 661);
    stringGraph_->insertEdge("Atlanta","New York", 888);
    stringGraph_->insertEdge("New York","Boston", 214);

    Graph<QString>::VertexList outlist = stringGraph_->dft("Dallas");

    qDebug() << outlist.size();

    for(Graph<QString>::VertexList::iterator itr = outlist.begin(); itr != outlist.end(); itr++){
        qDebug() << **itr;
    }

}

/*** THIS ADDS THE TEST TO THE LIST OF CLASSES TO RUN ***/
DECLARE_TEST(GraphTests)
#endif // GRAPHTESTS_H
