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

}

BoardTest::~BoardTest()
{

}

void BoardTest::test_load()
{
    Board *board = Board::getInstance();
    board->load();
    auto matrix = board->getMatrix();

    // Checks for the dimension of the matrix
    QCOMPARE(matrix->getSize(), 15);
    QCOMPARE(matrix->value(8)->getSize(), 15);

    board->clean();
}

void BoardTest::test_putLetter()
{

}

void BoardTest::test_getTile()
{

}

QTEST_APPLESS_MAIN(BoardTest)

#include "tst_boardtest.moc"
