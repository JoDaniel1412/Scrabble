#include "tst_docktest.h"

DockTest::DockTest()
{

}

DockTest::~DockTest()
{

}

void DockTest::test_load()
{
    Dock dock = *Dock::getInstance();
    dock.add('A');
    dock.add('B');

    QCOMPARE(dock.getLetters()->getSize(), 2);
    QCOMPARE(dock.getLetters()->value(1), 'B');

    dock.getLetters()->clean();
    QCOMPARE(dock.getLetters()->getSize(), 0);
}

void DockTest::test_json()
{
    Dock dock = *Dock::getInstance();
    dock.add('A');
    dock.add('B');
    dock.add('C');

    // Serialize
    QString json = JsonSerializer::serialize(dock);

    //qDebug() << json;

    // Parse serialization output to rebuild list
    Dock parsedDock = dock;
    JsonSerializer::parse(json, parsedDock);

    List<char> letters = *parsedDock.getLetters();
    QCOMPARE(letters.getSize(), 3);
    QCOMPARE(letters.value(0), 'A');
    QCOMPARE(letters.value(2), 'C');
}
