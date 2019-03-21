#ifndef TILE_H
#define TILE_H


class Tile
{
public:
    Tile();

    Tile(char letter, bool free, int bonus);

    char getLetter();

    void setLetter(char letter);

    bool isFree();

    void setFree(bool free);

    int getBonus();

    void setBonus(int bonus);

private:
    char letter;
    bool free;
    int bonus;
};

#endif // TILE_H
