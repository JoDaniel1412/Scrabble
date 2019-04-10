#include "tst_stringtojsontest.h"

StringToJsonTest::StringToJsonTest()
{

}

StringToJsonTest::~StringToJsonTest()
{

}

void StringToJsonTest::test_tileJson()
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

void StringToJsonTest::test_boardJson()
{
    Board board = *Board::getInstance();
    board.putLetter(0, 0, 'A');

    // Serialize
    QString json = JsonSerializer::serialize(board);

    //qDebug() << json;

    // Parse serialization output to rebuild list
	Board parsedBord = board;
    JsonSerializer::parse(json, parsedBord);

    QCOMPARE(parsedBord.getLetter(0, 0), 'A');
	QCOMPARE(parsedBord.getLetter(2, 3), '0');
}
