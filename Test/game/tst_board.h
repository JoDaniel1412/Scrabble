#pragma once

#include <gtest/gtest.h>
#include "game/board.h"

TEST(BoardTest, Instance_Test)
{
    Board *board = Board::getInstance();

    EXPECT_EQ(board->getMatrix()->getSize(), 0);
}

TEST(BoardTest, Load_Test)
{
    Board *board = Board::getInstance();
    board->load();
    auto matrix = board->getMatrix();

    // Checks for the dimension of the matrix
    EXPECT_EQ(matrix->getSize(), 15);
    EXPECT_EQ(matrix->value(8)->getSize(), 15);

    board->clean();
}


TEST(BoardTest, PutLetter_Test)
{
    Board *board = Board::getInstance();
    board->load();

    EXPECT_EQ(board->getLetter(2, 4), '0');

    board->putLetter(2, 4, 'A');
    EXPECT_EQ(board->getLetter(2, 4), 'A');

    board->putLetter(0, 14, 'F');
    EXPECT_EQ(board->getLetter(0, 14), 'F');

    board->clean();
}

TEST(BoardTest, GetTile_Test)
{
    Board *board = Board::getInstance();
    board->load();

    EXPECT_ANY_THROW(board->getTile(15, 3));

    Tile *emptyTile = board->getTile(3, 6);
    EXPECT_TRUE(emptyTile->isFree());
    EXPECT_EQ(emptyTile->getLetter(), '0');

    board->clean();
}
