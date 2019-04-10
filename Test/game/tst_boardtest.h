#ifndef TST_BOARDTEST_H
#define TST_BOARDTEST_H

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
    void test_cleanBoard();
    void test_boardJson();

};

//#include "tst_boardtest.moc"

#endif // TST_BOARDTEST_H
