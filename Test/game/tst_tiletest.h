#ifndef TST_TILETEST_H
#define TST_TILETEST_H

#include <QtTest>

#include <game/tile.h>
#include "json/jsonserializer.h"

// add necessary includes here

class TileTest : public QObject
{
    Q_OBJECT

public:
    TileTest();
    ~TileTest();

private slots:
    void test_get_set();
    void test_tileJson();
};

//#include "tst_tiletest.moc"

#endif // TST_TILETEST_H
