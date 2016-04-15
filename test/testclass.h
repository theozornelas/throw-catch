#ifndef TESTCLASS_H
#define TESTCLASS_H

#include "TestRunner.h"
#include <QObject>

class TestingSuiteName : public QObject
{
 Q_OBJECT
private slots:
 void testingTest();

};

DECLARE_TEST(TestingSuiteName)

#endif // TESTCLASS_H
