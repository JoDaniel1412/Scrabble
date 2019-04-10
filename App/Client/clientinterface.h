#ifndef CLIENTINTERFACE_H
#define CLIENTINTERFACE_H

#include "game/board.h"
#include "game/dock.h"
#include "game/game.h"
#include "client.h"
#include <json/stringtojson.h>
#include <gamewindow.h>


class ClientInterface : public QObject
{
    Q_OBJECT
public:
    static void updateGame(QString json);

    static void askUpdate(QString playerID);

    static void sendLetterAt(char letter, int i, int j, QString playerID);

    static void sendSMS(string word);

    static void setGameWindow(GameWindow *value);

private:
    static Game *game;
    static Board *board;
    static Dock *dock;
    static GameWindow *gameWindow;

    static QByteArray send(QByteArray data);
};

#endif // CLIENTINTERFACE_H
