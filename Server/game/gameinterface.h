#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include <QString>
#include <game/board.h>
#include "game/dock.h"
#include <list/List.h>
#include "dict/wordsdict.h"
#include "json/stringtojson.h"
#include "datasender.h"

class GameInterface
{
public:
    static bool isWord(QString word);

    static QString whoIsTurn();

    static void passTurn();

    static char popRandomLetter();

    static List<char> *popRandomLettersList(int size);

    static int wordPoints(QString word);

    static void updateGameToSend(QString playerID);

    static void addPlayerID(QString &playerID);

    static int getPlayerPoints(QString playerID);

    static void sumPlayerPoints(QString playerID, int points);

    static unordered_map<string, int> fromQHashToUnorderedMap(QHash<QString, int> map);

    static Board *getBoard();

    static List<QString> getPlayersID();
    static void setPlayersID(const List<QString> &value);

    static QHash<QString, int> getPlayersPoints();
    static void setPlayersPoints(const QHash<QString, int> &value);

    static int getMaxPlayers();
    static void setMaxPlayers(int value);

    static QHash<QString, List<char> *> getPlayersLetters();
    static void setPlayersLetters(const QHash<QString, List<char> *> value);

private:
    static List<QString> playersID;
    static QHash<QString, int> playersPoints;
    static QHash<QString, List<char>*> playersLetters;
    static int currentPlayer;
    static Board *board;
    static Game *game;
    static Dock *dock;
    static int maxPlayers;
};

#endif // GAMEINTERFACE_H
