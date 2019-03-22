#include <QtTest>

#include <game/tile.h>

// add necessary includes here

class TileTest : public QObject
{
    Q_OBJECT

public:
    TileTest();
    ~TileTest();

private slots:
    void test_get_set();

};

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

//QTEST_APPLESS_MAIN(TileTest)

#include "tst_tiletest.moc"
