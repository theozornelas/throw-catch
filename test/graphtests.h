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
    void test_MSTRealPrim();    // Tests the basic prim MST algortihm with ass12 data
    void test_Dijkstra();       // Test the dijkstra algorithm


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
    int testWeight = 0;
    int expectedWeight = 6513;

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

    Graph<QString>::EdgeList output  = stringGraph_->MSTPrim();
    Graph<QString>::EdgeList output2 = stringGraph_->PrimJarnek();

    for(Graph<QString>::EdgeItr i = output.begin(); i != output.end(); i++) {
 //       qDebug() << i->print() << i->weight();
        testWeight += i->weight();
    }

    QCOMPARE(output, output2);
    QCOMPARE(testWeight, expectedWeight);
}

void GraphTests::test_MSTRealPrim(){
    int testWeight = 0;
    int expectedWeight = 6513;

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

    Graph<QString>::EdgeList output = stringGraph_->PrimJarnek();
    Graph<QString>::EdgeList output2 = stringGraph_->MSTPrim();

    for(Graph<QString>::EdgeItr i = output.begin(); i != output.end(); i++) {
//        qDebug() << i->print() << i->weight();
        testWeight += i->weight();
    }

    QCOMPARE(output, output2);
    QCOMPARE(testWeight, expectedWeight);
}

void GraphTests::test_Dijkstra(){
    StadiumGraph_ = new Graph<Stadium>;
    Stadium safeco(1, "safeco field");
    Stadium rogers(2, "rogers centre");
    Stadium fenway(3, "fenway park");
    Stadium target(4, "Target Field");
    Stadium miller(5, "Miller Park");
    Stadium commerce(6, "Commerce Park");
    Stadium progressive(7, "Progressive Field");
    Stadium pnc(8, "PNC Park");
    Stadium yankee(9, "Yankee Stadium");
    Stadium citi(10, "Citi Field");
    Stadium wrigley(11, "Wrigley Field");
    Stadium usCell(12, "US Cellular Field");
    Stadium greatAmer(13, "Great American Ballfield");
    Stadium oriole(14, "Oriole Park");
    Stadium citizens(15, "Citizens Bank");
    Stadium nationals(16, "Nationals Park");
    Stadium turner(17, "Turner Field");
    Stadium busch(18, "Busch Stadium");
    Stadium kauffman(19, "Kauffman Stadium");
    Stadium coors(20, "Coors Field");
    Stadium att(21, "AT&T Park");
    Stadium dodgers(22, "Dodger Stadium");
    Stadium angels(23, "Angel Stadium");
    Stadium petco(24, "Petco Park");
    Stadium chase(25, "Chase Field");
    Stadium globeLife(26, "Globe Life Park");
    Stadium minMaid(27, "Minute Maid Park");
    Stadium tropicana(28, "Tropicana Field");
    Stadium marlins(29, "Marlins Park");
    Stadium oco(30, "O.co Coliseum");
    Stadium lasVegas(31, "Las Begas Stadium");

    // expected result from shortest path method
    Graph<Stadium>::VertexList expectedpath;
    expectedpath.push_back(dodgers);
    expectedpath.push_back(target);
    expectedpath.push_back(miller);
    expectedpath.push_back(wrigley);
    expectedpath.push_back(usCell);
    expectedpath.push_back(commerce);
    expectedpath.push_back(progressive);

    StadiumGraph_->insertEdge(safeco, rogers, 2070);
    StadiumGraph_->insertEdge(safeco, target, 1390);
    StadiumGraph_->insertEdge(safeco, att, 680);

    StadiumGraph_->insertEdge(att, oco, 50);

    StadiumGraph_->insertEdge(oco, dodgers, 340);
    StadiumGraph_->insertEdge(oco, chase, 650);

    StadiumGraph_->insertEdge(dodgers, angels, 50);
    StadiumGraph_->insertEdge(dodgers, target, 1500);

    StadiumGraph_->insertEdge(angels, petco, 110);

    StadiumGraph_->insertEdge(petco, coors, 830);
    StadiumGraph_->insertEdge(petco, chase, 300);

    StadiumGraph_->insertEdge(chase, coors, 580);
    StadiumGraph_->insertEdge(chase, globeLife, 870);
    StadiumGraph_->insertEdge(chase, minMaid, 1115);

    StadiumGraph_->insertEdge(minMaid, marlins, 965);
    StadiumGraph_->insertEdge(minMaid, tropicana, 790);
    StadiumGraph_->insertEdge(minMaid, busch, 680);
    StadiumGraph_->insertEdge(minMaid, globeLife, 230);

    StadiumGraph_->insertEdge(marlins, tropicana, 210);
    StadiumGraph_->insertEdge(marlins, turner, 600);
    StadiumGraph_->insertEdge(marlins, nationals, 930);
    StadiumGraph_->insertEdge(marlins, fenway, 1255);

    StadiumGraph_->insertEdge(tropicana, greatAmer, 790);

    StadiumGraph_->insertEdge(globeLife, coors, 650);
    StadiumGraph_->insertEdge(globeLife, kauffman, 460);
    StadiumGraph_->insertEdge(globeLife, turner, 740);

    StadiumGraph_->insertEdge(coors, kauffman, 560);

    StadiumGraph_->insertEdge(kauffman, busch, 235);
    StadiumGraph_->insertEdge(kauffman, wrigley, 415);

    StadiumGraph_->insertEdge(target, busch, 465);
    StadiumGraph_->insertEdge(target, miller, 300);

    StadiumGraph_->insertEdge(miller, wrigley, 80);
    StadiumGraph_->insertEdge(miller, rogers, 430);

    StadiumGraph_->insertEdge(wrigley, usCell, 50);

    StadiumGraph_->insertEdge(busch, greatAmer, 310);

    StadiumGraph_->insertEdge(turner, greatAmer, 375);
    StadiumGraph_->insertEdge(turner, nationals, 560);

    StadiumGraph_->insertEdge(pnc, rogers, 225);
    StadiumGraph_->insertEdge(pnc, progressive, 115);
    StadiumGraph_->insertEdge(pnc, greatAmer, 260);
    StadiumGraph_->insertEdge(pnc, yankee, 315);
    StadiumGraph_->insertEdge(pnc, nationals, 195);

    StadiumGraph_->insertEdge(nationals, oriole, 50);
    StadiumGraph_->insertEdge(oriole, citizens, 90);
    StadiumGraph_->insertEdge(citizens, yankee, 80);
    StadiumGraph_->insertEdge(yankee, citi, 50);
    StadiumGraph_->insertEdge(citi, fenway, 195);
    StadiumGraph_->insertEdge(fenway, rogers, 430);

    StadiumGraph_->insertEdge(commerce, usCell, 240);
    StadiumGraph_->insertEdge(commerce, rogers, 210);
    StadiumGraph_->insertEdge(commerce, progressive, 90);

    StadiumGraph_->insertEdge(greatAmer, usCell, 250);
    StadiumGraph_->insertEdge(greatAmer, progressive, 225);

    QCOMPARE(StadiumGraph_->GetDistance(dodgers, dodgers), 0);
    QCOMPARE(StadiumGraph_->GetDistance(dodgers, angels), 50);
    QCOMPARE(StadiumGraph_->GetDistance(dodgers, petco), 160);

    QCOMPARE(StadiumGraph_->GetDistance(dodgers, chase), 460);
    QCOMPARE(StadiumGraph_->GetDistance(dodgers, minMaid), 1560);
    QCOMPARE(StadiumGraph_->GetDistance(dodgers, tropicana), 2350);

    QCOMPARE(StadiumGraph_->GetDistance(dodgers, marlins), 2525);

    QCOMPARE(StadiumGraph_->GetDistance(dodgers, globeLife), 1330);
    QCOMPARE(StadiumGraph_->GetDistance(dodgers, turner), 2070);

    QCOMPARE(StadiumGraph_->GetDistance(dodgers, coors), 990);
    QCOMPARE(StadiumGraph_->GetDistance(dodgers, kauffman), 1550);
    QCOMPARE(StadiumGraph_->GetDistance(dodgers, busch), 1785);
    QCOMPARE(StadiumGraph_->GetDistance(dodgers, greatAmer), 2095);
    QCOMPARE(StadiumGraph_->GetDistance(dodgers, pnc), 2355);

    QCOMPARE(StadiumGraph_->GetDistance(dodgers, nationals), 2550);
    QCOMPARE(StadiumGraph_->GetDistance(dodgers, oriole), 2600);
    QCOMPARE(StadiumGraph_->GetDistance(dodgers, citizens), 2690);

    QCOMPARE(StadiumGraph_->GetDistance(dodgers, yankee), 2670);
    QCOMPARE(StadiumGraph_->GetDistance(dodgers, citi), 2720);

    QCOMPARE(StadiumGraph_->GetDistance(dodgers, target), 1500);
    QCOMPARE(StadiumGraph_->GetDistance(dodgers, miller), 1800);
    QCOMPARE(StadiumGraph_->GetDistance(dodgers, wrigley), 1880);
    QCOMPARE(StadiumGraph_->GetDistance(dodgers, usCell), 1930);
    QCOMPARE(StadiumGraph_->GetDistance(dodgers, commerce), 2170);
    QCOMPARE(StadiumGraph_->GetDistance(dodgers, progressive), 2260);

    QCOMPARE(StadiumGraph_->GetDistance(dodgers, safeco), 1070);
    QCOMPARE(StadiumGraph_->GetDistance(dodgers, rogers), 2230);
    QCOMPARE(StadiumGraph_->GetDistance(dodgers, fenway), 2660);

    Graph<Stadium>::VertexList path = StadiumGraph_->shortestPathTo(progressive);
    Graph<Stadium>::VertexItr itr1 = path.begin();
    Graph<Stadium>::VertexItr itr2 = expectedpath.begin();
    while(itr1 != path.end() && itr2 != expectedpath.end()){
        QCOMPARE(*itr1, *itr2);
        itr1++;
        itr2++;
    }

}

/*** THIS ADDS THE TEST TO THE LIST OF CLASSES TO RUN ***/
DECLARE_TEST(GraphTests)
#endif // GRAPHTESTS_H
