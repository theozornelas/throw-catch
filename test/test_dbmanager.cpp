#include <QtTest/QtTest>

class Test_DBManager : public QObject
{
    Q_OBJECT
private slots:
    // Put testing slots here
    void initTest();

private:
    // Put testing variables here
};

void Test_DBManager::initTest(){
    QVERIFY(true);
}

//#endif //TEST_DATABASE_H

QTEST_MAIN(Test_DBManager)
#include "test_dbmanager.moc"

