#include "mocks/mockgame.h"

MockGame::MockGame()
{
}

void MockGame::makePlayers()
{
    Game * game = Game::getInstance();

    unordered_map<string, int> *player = new unordered_map<string, int>();
    player->insert(pair<string, int>("Mari", 100));
    player->insert(pair<string, int>("Mario", 10));
    player->insert(pair<string, int>("Pene", 100));
    player->insert(pair<string, int>("Jo", 1));

    game->setPlaying(true);

    game->setPlayers(player);
}

void MockGame::updatePlayers()
{
    Game * game = Game::getInstance();

    unordered_map<string, int> *newplayer = new unordered_map<string, int>();
    newplayer->insert(pair<string, int>("Isaac", 453));
    //newplayer->insert(pair<string, int>("Mario2", 123));
    newplayer->insert(pair<string, int>("Fabian", 18));
    newplayer->insert(pair<string, int>("Tommy", 789));

    game->setPlayers(newplayer);
}

