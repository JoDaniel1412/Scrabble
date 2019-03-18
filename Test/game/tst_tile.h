#pragma once

#include <gtest/gtest.h>
#include "../../src/game/tile.h"

TEST(TileTest, Constructor_Test)
{
    Tile tile = Tile('A', false, 2);

    EXPECT_EQ(tile.getLetter(), 'A');
    EXPECT_FALSE(tile.isFree());
    EXPECT_EQ(tile.getBonus(), 2);
}

TEST(TileTest, GetSet_Test)
{
    Tile tile = Tile();

    EXPECT_EQ(tile.getLetter(), '0');
    EXPECT_TRUE(tile.isFree());
    EXPECT_EQ(tile.getBonus(), 1);

    tile.setLetter('C');
    tile.setFree(false);
    tile.setBonus(4);

    EXPECT_EQ(tile.getLetter(), 'C');
    EXPECT_FALSE(tile.isFree());
    EXPECT_EQ(tile.getBonus(), 4);
}
