#include "gameinterface.h"

List<QString> GameInterface::playersID = List<QString>();
QHash<QString, int> GameInterface::playersPoints = QHash<QString, int>();
int GameInterface::currentPlayer = 0;
Board *GameInterface::board = Board::getInstance();

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

char GameInterface::popRandomLetter()
{
    char letter = WordsDict::popRandomLetter();
    return letter;
}

List<char> GameInterface::popRandomLettersList(int size)
{
    List<char> letters = WordsDict::popRandomLettersList(size);
    return letters;
}

int GameInterface::wordPoints(QString word)
{
    return WordsDict::wordPoints(word);
}

List<QString> GameInterface::getPlayersID()
{
    return playersID;
}

void GameInterface::setPlayersID(const List<QString> &value)
{
    playersID = value;
}

void GameInterface::addPlayerID(QString &playerID)
{
    playersID.pushTail(playerID);
    playersPoints.insert(playerID, 0);
}

int GameInterface::getPlayerPoints(QString playerID)
{
    return playersPoints.value(playerID);
}

void GameInterface::sumPlayerPoints(QString playerID, int points)
{
    int value = playersPoints.value(playerID);
    value += points;
}

Board *GameInterface::getBoard()
{
    return board;
}

QHash<QString, int> GameInterface::getPlayersPoints()
{
    return playersPoints;
}

void GameInterface::setPlayersPoints(const QHash<QString, int> &value)
{
    playersPoints = value;
}
