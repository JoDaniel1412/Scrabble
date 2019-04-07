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

    game->setPlayers(player);
}

