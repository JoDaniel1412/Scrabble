#include "game/tst_boardtest.cpp"
#include "game/tst_tiletest.cpp"
#include <game/tst_docktest.cpp>


int main(int argc, char** argv)
{
    int status = 0;
    {
       BoardTest tc;
       status |= QTest::qExec(&tc, argc, argv);
    }
    {
       TileTest tc;
       status |= QTest::qExec(&tc, argc, argv);
    }
    {
       DockTest tc;
       status |= QTest::qExec(&tc, argc, argv);
    }
    return status;
}
