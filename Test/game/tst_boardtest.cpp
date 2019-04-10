#include "tst_boardtest.h"

BoardTest::BoardTest()
{
    Board::getInstance();
}

BoardTest::~BoardTest()
{

}

void BoardTest::test_load()
{
    Board *board = Board::getInstance();
    auto matrix = board->getMatrix();

    // Checks for the dimension of the matrix
    QCOMPARE(matrix->getSize(), 15);
    QCOMPARE(matrix->value(8)->getSize(), 15);
}

void BoardTest::test_putLetter()
{
    Board *board = Board::getInstance();

    QCOMPARE(board->getLetter(2, 4), '0');

    board->putLetter(2, 4, 'A');
    QCOMPARE(board->getLetter(2, 4), 'A');

    board->putLetter(0, 14, 'F');
    QCOMPARE(board->getLetter(0, 14), 'F');

    board->putLetter(13, 14, 'R');
    QCOMPARE(board->getLetter(13, 14), 'R');

    board->clean();
}

void BoardTest::test_getTile()
{
    Board *board = Board::getInstance();

    QVERIFY_EXCEPTION_THROWN(board->getTile(15, 3), out_of_range);  // Out of bounds

    Tile *emptyTile = board->getTile(3, 6);
    QVERIFY(emptyTile->isFree());
    QCOMPARE(emptyTile->getLetter(), '0');

    Tile *tile = board->getTile(4, 5);
    board->putLetter(4, 5, 'T');
    QVERIFY(!tile->isFree());
    QCOMPARE(tile->getLetter(), 'T');
}

void BoardTest::test_cleanBoard()
{
    Board *board = Board::getInstance();

    board->putLetter(2, 4, 'A');
    QCOMPARE(board->getLetter(2, 4), 'A');

    board->clean();
    QCOMPARE(board->getLetter(2, 4), '0');
}

void BoardTest::test_boardJson()
{
    Board board = *Board::getInstance();
    board.putLetter(0, 0, 'A');

    // Serialize
    QString json = JsonSerializer::serialize(board);

    //qDebug() << json;

    // Parse serialization output to rebuild list
    Board parsedBord = board;
    JsonSerializer::parse(json, parsedBord);
    parsedBord.putLetter(13, 13, 'B');

    QCOMPARE(parsedBord.getLetter(0, 0), 'A');
    QCOMPARE(parsedBord.getLetter(2, 3), '0');
    QCOMPARE(parsedBord.getLetter(13, 13), 'B');
    board.clean();
}

void BoardTest::test_words()
{
    Board board = *Board::getInstance();
    board.putLetter(2, 4, 'P');
    board.putLetter(2, 5, 'E');
    board.putLetter(2, 6, 'R');
    board.putLetter(2, 7, 'R');
    board.putLetter(2, 8, 'O');

    board.putLetter(0, 7, 'C');
    board.putLetter(1, 7, 'A');
    board.putLetter(3, 7, 'R');
    board.putLetter(4, 7, 'O');

    pair<QString, QString> *words = board.getWords(2, 7);
    QCOMPARE(words->first, "PERRO");
    QCOMPARE(words->second, "CARRO");
}
