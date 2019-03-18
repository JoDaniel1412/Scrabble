#include "board.h"

Board *Board::instance = nullptr;

Board::Board() {
    matrix = new List<List<Tile*>*>();
    rows = 15;
    columns = 15;
};

Board *Board::getInstance()
{
    if (instance == nullptr) instance = new Board();
    return instance;
}

void Board::load()
{
    for (int i = 0; i < rows; i++) {  // Loads the rows into the matrix
        List<Tile*> *row = new List<Tile*>();
        matrix->pushTail(row);

        for (int j = 0; j < columns; j++) {  // Loads the columns into the matrix
            Tile *tile = new Tile();
            row->pushTail(tile);
        }
    }
}

void Board::putLetter(int i, int j, char letter)
{
    Tile *tile = getTile(i, j);
    tile->setLetter(letter);
}

char Board::getLetter(int i, int j)
{
    Tile *tile = getTile(i, j);
    return tile->getLetter();
}

List<List<Tile*>*> *Board::getMatrix()
{
    return matrix;
}

Tile *Board::getTile(int i, int j)  // Searchs the Tile inthe matrix
{
    List<Tile*> *row = matrix->value(i);
    Tile *tile = row->value(j);
    return tile;
}

void Board::clean()
{
    matrix->clean();
}
