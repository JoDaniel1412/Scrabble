#ifndef CLIENTINTERFACE_H
#define CLIENTINTERFACE_H

#include "game/board.h"
#include "game/dock.h"
#include "game/game.h"
#include "client.h"
#include <json/stringtojson.h>


class ClientInterface
{
public:
    static void updateGame(string json);

    static void sendLetterAt(char letter, int i, int j);

    static void sendSMS(string word);

private:
    static Game *game;
    static Board *board;
    static Dock *dock;

    static void send(QByteArray data);
};

#endif // CLIENTINTERFACE_H
