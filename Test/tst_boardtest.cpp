#include <QtTest>

#include <game/board.h>

// add necessary includes here

class BoardTest : public QObject
{
    Q_OBJECT

public:
    BoardTest();
    ~BoardTest();

private slots:
    void test_load();
    void test_putLetter();
    void test_getTile();

};

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
}

void BoardTest::test_getTile()
{
    Board *board = Board::getInstance();

    QVERIFY_EXCEPTION_THROWN(board->getTile(15, 3), out_of_range);  // Out of bounds

    Tile *emptyTile = board->getTile(3, 6);
    QVERIFY(emptyTile->isFree());
    QCOMPARE(emptyTile->getLetter(), '0');
}

//QTEST_APPLESS_MAIN(BoardTest)

#include "tst_boardtest.moc"
