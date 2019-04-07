#ifndef BOARD_H
#define BOARD_H

#include "tile.h"

#include <list/List.h>

class Board
{
public:
    static Board *getInstance();

    void load();

    bool putLetter(int i, int j, char letter);

    char getLetter(int i, int j);

    List<List<Tile*>*> *getMatrix();

    Tile *getTile(int i, int j);

    void clean();

private:
    static Board *instance;
    List<List<Tile*>*> *matrix;
    int rows;
    int columns;

    Board();  // Private Constructor
};

#endif // BOARD_H
