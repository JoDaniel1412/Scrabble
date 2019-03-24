#include "tst_gametest.h"

GameTest::GameTest()
{
    Game *game = Game::getInstance();
    QVERIFY(!game->isPlaying());
    QVERIFY(game->getPlayers()->empty());
}

GameTest::~GameTest()
{

}

void GameTest::test_passTurn()
{
    Game *game = Game::getInstance();

    game->setPlaying(true);
    QVERIFY(game->isPlaying());

    game->passTurn();
    QVERIFY(!game->isPlaying());
}
