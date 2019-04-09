#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include <QString>
#include <game/board.h>
#include <list/List.h>
#include "dict/wordsdict.h"

class GameInterface
{
public:
    static bool isWord(QString word);

    static QString whoIsTurn();

    static void passTurn();

    static char popRandomLetter();

    static List<char> popRandomLettersList(int size);

    static int wordPoints(QString word);

    static void addPlayerID(QString &playerID);

    static int getPlayerPoints(QString playerID);

    static void sumPlayerPoints(QString playerID, int points);

    static Board *getBoard();

    static List<QString> getPlayersID();
    static void setPlayersID(const List<QString> &value);

    static QHash<QString, int> getPlayersPoints();
    static void setPlayersPoints(const QHash<QString, int> &value);

    static int getMaxPlayers();
    static void setMaxPlayers(int value);

private:
    static List<QString> playersID;
    static QHash<QString, int> playersPoints;
    static int currentPlayer;
    static Board *board;
    static int maxPlayers;
};

#endif // GAMEINTERFACE_H
