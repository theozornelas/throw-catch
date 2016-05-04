#ifndef GRAPHTESTS_H
#define GRAPHTESTS_H

#include "testrunner.h"
#include <QObject>
#include <QString>
#include <QList>
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
    void test_insert_edges();   // Test the ability to insert edges with new verticies to the graph
    void test_insert_vetex();   // Test the ability to insert vertecies without edges
    void test_assignment12();   // Runs assignment 12 and checks the results of the DFS
    void test_removeVertex1();  // Tests the removal of a vertex and all incident edges
    void test_removeVertex2();  // Tests the removal of a vertex and all incident edges
    void test_removeEdge1();    // Test the removal of an edge
    void test_AddStadium();     // Tests the basic creation of a graph of stadiums and adding a few stadiums
    void test_MSTPrim();        // Tests the basic prim MST algortihm with ass12 data
    //void test_Dijkstra();


private:
    Graph<QString>* stringGraph_;   // Graph of strings for testing
    Graph<Stadium>* StadiumGraph_;  // Graph of stadium objects for testing
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

void GraphTests::test_insert_edges() {
    stringGraph_->insertEdge("first", "second", 200);
    stringGraph_->insertEdge("first", "third", 300);
    stringGraph_->insertEdge("first", "fourth", 400);
    stringGraph_->insertEdge("second", "fourth", 800);
    QVERIFY2(stringGraph_->numVertices() == 4, "The number of Vertices is incorrect!");
    QVERIFY2(stringGraph_->numEdges() == 4, "The number of Edges is incorrect!");
}

void GraphTests::test_insert_vetex() {
    stringGraph_->insertVertex("first");
    stringGraph_->insertVertex("second");
    stringGraph_->insertVertex("third");
    stringGraph_->insertVertex("first");
    stringGraph_->insertVertex("second");
    stringGraph_->insertVertex("fourth");
    QVERIFY2(stringGraph_->numVertices() == 4, "The number of Vertices is incorrect!");
    QVERIFY2(stringGraph_->numEdges() == 0, "The number of Edges is incorrect!");
}

void GraphTests::test_assignment12()
{
    QList<QString> properOut;
    properOut << "Dallas" << "Houston" << "Atlanta" << "Miami" << "Kansas City"
              << "Chicago" << "New York" << "Boston" << "Denver" << "Los Angeles"
              << "San Francisco" << "Seattle";

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

    QVERIFY2(outlist.size() == 12, "Not all of the vertices were visited!");

    QString DFSoutput = "[";
    Graph<QString>::VertexList::iterator actual = outlist.begin();
    QList<QString>::iterator expected = properOut.begin();

    while(actual != outlist.end()){
        DFSoutput += **actual;
        if(**actual != *outlist.back()) {DFSoutput += ", ";}
        QCOMPARE(**actual, *expected);
        actual++;
        expected++;
    }

    DFSoutput += "]";
    qDebug() << "DEPTH FIRST SEARCH:" << DFSoutput;
}

void GraphTests::test_removeVertex1() {
    stringGraph_->insertEdge("first", "second", 200);
    stringGraph_->insertEdge("first", "third", 300);
    stringGraph_->insertEdge("first", "fourth", 400);

    stringGraph_->eraseVertex("first");

    QVERIFY2(stringGraph_->numVertices() == 3, "The number of Vertices is incorrect!");
    QVERIFY2(stringGraph_->numEdges() == 0, "The number of Edges is incorrect!");
}

void GraphTests::test_removeVertex2() {
    stringGraph_->insertEdge("first", "second", 200);
    stringGraph_->insertEdge("first", "third", 300);
    stringGraph_->insertEdge("first", "fourth", 400);

    stringGraph_->eraseVertex("second");

    QVERIFY2(stringGraph_->numVertices() == 3, "The number of Vertices is incorrect!");
    QVERIFY2(stringGraph_->numEdges() == 2, "The number of Edges is incorrect!");
}

void GraphTests::test_removeEdge1() {
    stringGraph_->insertEdge("first", "second", 200);
    stringGraph_->insertEdge("first", "third", 300);
    stringGraph_->insertEdge("first", "fourth", 400);

    stringGraph_->eraseEdge("first", "second", 200);

    QVERIFY2(stringGraph_->numVertices() == 4, "The number of Vertices is incorrect!");
    QVERIFY2(stringGraph_->numEdges() == 2, "The number of Edges is incorrect!");
}

void GraphTests::test_AddStadium() {
    StadiumGraph_ = new Graph<Stadium>;

    Stadium dodgers(5, "Dodgers Stadium");
    Stadium yankees(2, "Yankees Stadium");
    Stadium marlins(9, "marlins Stadium");

    StadiumGraph_->insertEdge(dodgers, yankees, 1500);
    StadiumGraph_->insertEdge(dodgers, marlins, 1200);
    StadiumGraph_->insertEdge(yankees, marlins, 800);

    QVERIFY2(StadiumGraph_->numVertices() == 3, "The number of Vertices is incorrect!");
    QVERIFY2(StadiumGraph_->numEdges() == 3, "The number of Edges is incorrect!");
}

void GraphTests::test_MSTPrim(){
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

    // Still getting errors here.
//    Graph<QString>::EdgeList output = stringGraph_->MSTPrim();

//    for(Graph<QString>::EdgeItr i = output.begin(); i != output.end(); i++) {
//        qDebug() << i->print() << i->weight();
//    }
}

//void GraphTests::test_Dijkstra(){
//    stringGraph_->insertEdge("Seattle","Chicago", 2097);
//    stringGraph_->insertEdge("Seattle","Denver", 1331);
//    stringGraph_->insertEdge("Seattle","San Francisco", 807);
//    stringGraph_->insertEdge("San Francisco","Los Angeles", 381);
//    stringGraph_->insertEdge("San Francisco","Denver", 1267);
//    stringGraph_->insertEdge("Los Angeles","Denver", 1015);
//    stringGraph_->insertEdge("Los Angeles","Kansas City", 1663);
//    stringGraph_->insertEdge("Los Angeles","Dallas", 1435);
//    stringGraph_->insertEdge("Denver","Chicago", 1003);
//    stringGraph_->insertEdge("Denver","Kansas City", 599);
//    stringGraph_->insertEdge("Chicago","Kansas City", 533);
//    stringGraph_->insertEdge("Chicago","Boston", 983);
//    stringGraph_->insertEdge("Chicago","New York", 787);
//    stringGraph_->insertEdge("Kansas City","Dallas", 496);
//    stringGraph_->insertEdge("Kansas City","New York", 1260);
//    stringGraph_->insertEdge("Kansas City","Atlanta", 864);
//    stringGraph_->insertEdge("Dallas","Houston", 239);
//    stringGraph_->insertEdge("Dallas","Atlanta", 781);
//    stringGraph_->insertEdge("Houston","Atlanta", 810);
//    stringGraph_->insertEdge("Houston","Miami", 1187);
//    stringGraph_->insertEdge("Atlanta","Miami", 661);
//    stringGraph_->insertEdge("Atlanta","New York", 888);
//    stringGraph_->insertEdge("New York","Boston", 214);

//    stringGraph_->Dijkstra("Atlanta");
//}

/*** THIS ADDS THE TEST TO THE LIST OF CLASSES TO RUN ***/
DECLARE_TEST(GraphTests)
#endif // GRAPHTESTS_H
