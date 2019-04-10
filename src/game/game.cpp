#include "game.h"

Game *Game::instance = nullptr;

Game::Game()
{
    playing = false;
    players = new unordered_map<string, int>;
    playerPlaying = "";
}

Game *Game::getInstance()
{
    if (instance == nullptr) instance = new Game();
    return instance;
}

void Game::passTurn()
{
    playing = false;
}

bool Game::isPlaying() const
{
    return playing;
}

void Game::setPlaying(bool value)
{
    playing = value;
}

unordered_map<string, int> *Game::getPlayers() const
{
    return players;
}

void Game::setPlayers(unordered_map<string, int> *value)
{
    players = value;
}

QString Game::getPlayerPlaying() const
{
    return playerPlaying;
}

void Game::setPlayerPlaying(const QString &value)
{
    playerPlaying = value;
}

void Game::write(QJsonObject &jsonObj) const
{
    QJsonArray jsonArray;
    for(pair<string, int> entry : *players)
    {
        QJsonObject jsonPair;

        QString player = QString::fromStdString(entry.first);
        jsonPair["player"] = player;
        jsonPair["points"] = entry.second;

        jsonArray.append(jsonPair);
    }

    jsonObj["playing"] = playerPlaying;
    jsonObj["players"] = jsonArray;
}

void Game::read(const QJsonObject &jsonObj)
{
    players->clear();
    // json encapsulates the QJsonArray
    playerPlaying = jsonObj["playing"].toString();
    QJsonArray jsonArray = jsonObj["players"].toArray();
    foreach(QJsonValue jsonPlayer, jsonArray)
    {
        // the QJsonValue encapsulates the person QJsonObject
        string player = jsonPlayer["player"].toString().toStdString();
        int points = jsonPlayer["points"].toInt();

        pair<string, int> pair(player, points);
        this->players->insert(pair);
    }
}
