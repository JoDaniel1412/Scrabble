#ifndef GAME_H
#define GAME_H

#include<unordered_map>

using namespace std;

class Game
{
public:
    static Game *getInstance();

    void passTurn();

    bool isPlaying() const;
    void setPlaying(bool value);

    unordered_map<string, int> *getPlayers() const;
    void setPlayers(unordered_map<string, int> *value);

private:
    static Game *instance;
    bool playing;
    unordered_map<string, int> *players;  // Players names and points

    Game();
};

#endif // GAME_H