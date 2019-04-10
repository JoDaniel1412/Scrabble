#ifndef GAME_H
#define GAME_H

#include <unordered_map>
#include <json/jsonserializable.h>
#include <QJsonArray>

using namespace std;

class Game : public JsonSerializable
{
public:
    static Game *getInstance();

    void passTurn();

    bool isPlaying() const;
    void setPlaying(bool value);

    unordered_map<string, int> *getPlayers() const;
    void setPlayers(unordered_map<string, int> *value);

    QString getPlayerPlaying() const;
    void setPlayerPlaying(const QString &value);

    void write(QJsonObject &jsonObj) const;
    void read(const QJsonObject &jsonObj);

    QString getMyID() const;
    void setMyID(const QString &value);

private:
    static Game *instance;
    bool playing;
    unordered_map<string, int> *players;  // Players names and points
    QString playerPlaying;
    QString myID;

    Game();
};

#endif // GAME_H
