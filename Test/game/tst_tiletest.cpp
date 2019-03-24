#include "tst_tiletest.h"

TileTest::TileTest()
{
    Tile tile = Tile('A', false, 2);

    QCOMPARE(tile.getLetter(), 'A');
    QCOMPARE(tile.getBonus(), 2);
    QVERIFY(!tile.isFree());
}

TileTest::~TileTest()
{

}

void TileTest::test_get_set()
{
    Tile tile = Tile();

    QCOMPARE(tile.getLetter(), '0');
    QVERIFY(tile.isFree());
    QCOMPARE(tile.getBonus(), 1);

    tile.setLetter('C');
    tile.setFree(false);
    tile.setBonus(4);

    QCOMPARE(tile.getLetter(), 'C');
    QVERIFY(!tile.isFree());
    QCOMPARE(tile.getBonus(), 4);
}
