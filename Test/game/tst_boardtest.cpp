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
