#ifndef TST_GAMETEST_H
#define TST_GAMETEST_H

#include<QTest>

#include "game/game.h"
#include "json/jsonserializer.h"

class GameTest : public QObject
{
    Q_OBJECT

public:
    GameTest();
    ~GameTest();

private slots:
    void test_passTurn();
    void test_jsonGame();

};

//#include "tst_gametest.moc"

#endif // TST_GAMETEST_H
