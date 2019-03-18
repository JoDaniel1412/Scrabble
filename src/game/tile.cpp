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

char Tile::getLetter() {
    return letter;
}

void Tile::setLetter(char letter) {
    Tile::letter = letter;
}

bool Tile::isFree() {
    return free;
}

void Tile::setFree(bool free) {
    Tile::free = free;
}

int Tile::getBonus() {
    return bonus;
}

void Tile::setBonus(int bonus) {
    Tile::bonus = bonus;
}
