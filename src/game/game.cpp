#include "game.h"

Game *Game::instance = nullptr;

Game::Game()
{
    playing = false;
    players = new unordered_map<string, int>;
}

Game *Game::getInstance()
{
    if (instance == nullptr) instance = new Game();
    return instance;
}

void Game::passTurn()
{
    playing = false;
}

bool Game::isPlaying() const
{
    return playing;
}

void Game::setPlaying(bool value)
{
    playing = value;
}

unordered_map<string, int> *Game::getPlayers() const
{
    return players;
}

void Game::setPlayers(unordered_map<string, int> *value)
{
    players = value;
}
