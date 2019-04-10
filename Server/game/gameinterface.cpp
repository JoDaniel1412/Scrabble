#include "gameinterface.h"

List<QString> GameInterface::playersID = List<QString>();
QHash<QString, int> GameInterface::playersPoints = QHash<QString, int>();
QHash<QString, List<char>*> GameInterface::playersLetters = QHash<QString, List<char>*>();
int GameInterface::currentPlayer = 0;
Board *GameInterface::board = Board::getInstance();
Game *GameInterface::game = Game::getInstance();
Dock *GameInterface::dock = Dock::getInstance();
int GameInterface::maxPlayers = 0;

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
    if (currentPlayer >= playersID.getSize()) currentPlayer = 0;
}

char GameInterface::popRandomLetter()
{
    char letter = WordsDict::popRandomLetter();
    return letter;
}

void GameInterface::placeLetter(int i, int j, char letter, QString playerID)
{
    board->putLetter(i, j, letter);
    List<char> *letters = playersLetters.value(playerID);
    int index = letters->index(letter);
    letters->deleteValue(index);
    letters->pushTail(popRandomLetter());
    passTurn();
    updateGameToSend(playerID);
}

List<char> *GameInterface::popRandomLettersList(int size)
{
    List<char> *letters = WordsDict::popRandomLettersList(size);
    return letters;
}

int GameInterface::wordPoints(QString word)
{
    return WordsDict::wordPoints(word);
}

void GameInterface::updateGameToSend(QString playerID)
{
    game->setPlayerPlaying(whoIsTurn());
    unordered_map<string, int> players = fromQHashToUnorderedMap(playersPoints);
    game->setPlayers(&players);
    List<char> *letters = playersLetters.value(playerID);
    dock->setLetters(letters);

    QByteArray data = StringToJson::gameObject(*game, *dock, *board);
    dataSender::setInfoToSend(data);
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
    playersLetters.insert(playerID, popRandomLettersList(7));
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

unordered_map<string, int> GameInterface::fromQHashToUnorderedMap(QHash<QString, int> map)
{
    unordered_map<string, int> result;
    for(auto entry = map.begin(); entry != map.end(); ++entry)
    {
        string key = entry.key().toStdString();
        int value = entry.value();
        result.insert(make_pair(key, value));
    }
    return result;
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

int GameInterface::getMaxPlayers()
{
    return maxPlayers;
}

void GameInterface::setMaxPlayers(int value)
{
    maxPlayers = value;
}

QHash<QString, List<char> *> GameInterface::getPlayersLetters()
{
    return playersLetters;
}

void GameInterface::setPlayersLetters(const QHash<QString, List<char> *> value)
{
    playersLetters = value;
}
