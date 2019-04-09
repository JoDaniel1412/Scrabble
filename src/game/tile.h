#ifndef TILE_H
#define TILE_H

#include "json/jsonserializable.h"

class Tile : public JsonSerializable
{
public:
    Tile();

    Tile(char letter, bool free, int bonus);

    char getLetter() const;
    void setLetter(char letter);

    bool isFree() const;
    void setFree(bool free);

    int getBonus() const;
    void setBonus(int bonus);

    void read(const QJsonObject &jsonObj);
    void write(QJsonObject &jsonObj) const;

private:
    char letter;
    bool free;
    int bonus;
};

#endif // TILE_H
