#ifndef BOARD_H
#define BOARD_H

#include "tile.h"
#include "../list/list.h"

class Board
{
public:
    Board *getInstance();

    void add(int i, int j);

private:
    static Board *instance;
    List<List<Tile>> matrix;

    Board();  // Private Constructor
};

#endif // BOARD_H
