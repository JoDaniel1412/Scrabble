#include "clientinterface.h"

Game *ClientInterface::game = Game::getInstance();
Board *ClientInterface::board = Board::getInstance();
Dock *ClientInterface::dock = Dock::getInstance();

void ClientInterface::updateGame(string json)
{
    unordered_map<string, int> *players = fromJSONtoPlayers("");
    game->setPlayers(players);

    List<char> *letters = fromJSONtoLetters("");
    dock->setLetters(letters);

    List<List<Tile *>*> *matrix = fromJSONtoMatrix("");
    board->setMatrix(matrix);
}

void ClientInterface::letterPlacedAt(char letter, int i, int j)
{

}

void ClientInterface::sendSMS(string word)
{

}

unordered_map<string, int> *ClientInterface::fromJSONtoPlayers(string json)
{

}

List<char> *ClientInterface::fromJSONtoLetters(string json)
{

}

List<List<Tile *> *> *ClientInterface::fromJSONtoMatrix(string json)
{

}
