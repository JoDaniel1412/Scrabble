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

void TileTest::test_tileJson()
{
    Tile tile('A', false, 2);

    // Serialize
    QString json = JsonSerializer::serialize(tile);

    //qDebug() << json;

    // Parse serialization output to rebuild tile
    Tile parsedTile;
    JsonSerializer::parse(json, parsedTile);

    QCOMPARE(parsedTile.getLetter(), tile.getLetter());
    QCOMPARE(parsedTile.isFree(), tile.isFree());
    QCOMPARE(parsedTile.getBonus(), tile.getBonus());
}
