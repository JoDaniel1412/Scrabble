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

void GameTest::test_jsonGame()
{
    Game game = *Game::getInstance();

    unordered_map<string, int> players;
    players.insert(make_pair("Juan", 3));
    players.insert(make_pair("Jess", 2));
    players.insert(make_pair("Pedro", 4));
    game.setPlayers(&players);

    game.setPlayerPlaying("Jess");

    // Serialize
    QString json = JsonSerializer::serialize(game);

    //qDebug() << json;

    // Parse serialization output to rebuild list
    Game parsedGame = game;
    JsonSerializer::parse(json, parsedGame);

    unordered_map<string, int> parsePlayers = *parsedGame.getPlayers();
    QCOMPARE(parsePlayers.size(), 3);
    QCOMPARE(parsePlayers.at("Jess"), 2);
    QCOMPARE(parsePlayers.at("Pedro"), 4);

    QCOMPARE(parsedGame.getPlayerPlaying(), "Jess");
}
