#ifndef TESTADDER_H
#define TESTADDER_H

//////////////////////////////////////////////////////////////////////////
template <class T>
class TestAdder
{
public:

 TestAdder(const QString& name)
 {
   T newTest = new T();
   newTest->setObjectName(name);
   TestRunner::Instance().RegisterTest(newTest);
 }
 void RegisterTest(QObject* test)
 {
    auto testName = test->objectName();

    if ( std::find_if(begin(m_tests), end(m_tests), [&testName](QSharedPointer<QObject>& elem)
         { return elem->objectName() == testName; }) == end(m_tests) )
        m_tests.push_back(QSharedPointer<QObject>(test));
 }

};

#endif // TESTADDER_H
