#include <gtest/gtest.h>
#include "list/tst_list.h"
#include "list/tst_node.h"
#include "game/tst_board.h"
#include "game/tst_tile.h"

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
