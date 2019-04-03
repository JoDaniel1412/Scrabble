#include "gameinterface.h"

List<QString> GameInterface::playersID = List<QString>();
int GameInterface::currentPlayer = 0;

bool GameInterface::isWord(QString word)
{
    bool isWord = WordsDict::isWord(word);
    return isWord;
}

QString GameInterface::whoIsTurn()
{
    QString player = playersID.value(currentPlayer);
    return player;
}

void GameInterface::passTurn()
{
    currentPlayer += 1;
    if (currentPlayer > playersID.getSize()) currentPlayer = 0;
}

List<QString> GameInterface::getPlayersID()
{
    return playersID;
}

void GameInterface::setPlayersID(const List<QString> &value)
{
    playersID = value;
}
