#ifndef TST_DOCKTEST_H
#define TST_DOCKTEST_H

#include <QtTest>

#include <game/dock.h>
#include "json/jsonserializer.h"

// add necessary includes here

class DockTest : public QObject
{
    Q_OBJECT

public:
    DockTest();
    ~DockTest();

private slots:
    void test_load();
    void test_json();

};

//#include "tst_docktest.moc"

#endif // TST_DOCKTEST_H
