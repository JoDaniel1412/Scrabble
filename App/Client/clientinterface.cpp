#include "clientinterface.h"

static Game *game = Game::getInstance();
static Board *board = Board::getInstance();
static Dock *dock = Dock::getInstance();

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
