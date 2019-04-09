#include "tile.h"


Tile::Tile() {
    letter = '0';
    free = true;
    bonus = 1;
}

Tile::Tile(char letter, bool free, int bonus) {
    this->letter = letter;
    this->free = free;
    this->bonus = bonus;
}

char Tile::getLetter() const {
    return letter;
}

void Tile::setLetter(char letter) {
    Tile::letter = letter;
}

bool Tile::isFree() const {
    return free;
}

void Tile::setFree(bool free) {
    Tile::free = free;
}

int Tile::getBonus() const {
    return bonus;
}

void Tile::setBonus(int bonus) {
    Tile::bonus = bonus;
}

void Tile::read(const QJsonObject &jsonObj)
{
    this->setLetter(jsonObj["letter"].toString().toStdString().front());
    this->setFree(jsonObj["free"].toBool());
    this->setBonus(jsonObj["bonus"].toInt());
}

void Tile::write(QJsonObject &jsonObj) const
{
    QString letter(getLetter());
    jsonObj["letter"] = letter;
    jsonObj["free"] = isFree();
    jsonObj["bonus"] = getBonus();
}
