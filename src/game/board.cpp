#include "board.h"

Board *Board::instance = nullptr;

Board::Board() {};

Board *Board::getInstance()
{
    if (instance == nullptr) instance = new Board();
    return instance;
}

void Board::add(int i, int j)
{
    // Searchs the Tile inthe matrix
    List<Tile> row = matrix.value(i);
    Tile tile = row.value(j);
}
