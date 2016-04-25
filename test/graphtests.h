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

private:
    Graph<QString>* stringGraph_;   //< Graph of strings
};

/********************************************************************************************
 *                         IMPLEMENTATION OF SETUP / TEARDOWN METHODS
 ********************************************************************************************/

void GraphTests::init() {
    stringGraph_ = new Graph<QString>;
    stringGraph_->insertEdge("begin", "end", 545);
}

// empties the list for the next test
void GraphTests::cleanup() {
    delete list_;
}

/********************************************************************************************
 *                                  IMPLEMENTATION OF TESTS
 ********************************************************************************************/

/*** THIS ADDS THE TEST TO THE LIST OF CLASSES TO RUN ***/
DECLARE_TEST(GraphTests)
#endif // GRAPHTESTS_H
