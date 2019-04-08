#ifndef CLIENTINTERFACE_H
#define CLIENTINTERFACE_H

#include "game/board.h"
#include "game/dock.h"
#include "game/game.h"


class ClientInterface
{
public:
    static void updateGame(string json);

    static void letterPlacedAt(char letter, int i, int j);

    static void sendSMS(string word);

private:
    static Game *game;
    static Board *board;
    static Dock *dock;

    static unordered_map<string, int> *fromJSONtoPlayers(string json);

    static List<char> *fromJSONtoLetters(string json);

    static List<List<Tile *>*> *fromJSONtoMatrix(string json);
};

#endif // CLIENTINTERFACE_H
