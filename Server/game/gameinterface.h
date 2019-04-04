#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include <QString>
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

    static List<QString> getPlayersID();
    static void setPlayersID(const List<QString> &value);

private:
    static List<QString> playersID;
    static int currentPlayer;
};

#endif // GAMEINTERFACE_H
