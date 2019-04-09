#include "game/tst_boardtest.h"
#include "game/tst_tiletest.h"
#include "game/tst_docktest.h"
#include "game/tst_gametest.h"
#include "dict/tst_wordsdicttest.h"
#include "json/tst_stringtojsontest.h"

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
    {
        GameTest tc;
        status |= QTest::qExec(&tc, argc, argv);
    }
    {
        WordsDictTest tc;
        status |= QTest::qExec(&tc, argc, argv);
    }
    {
        StringToJsonTest tc;
        status |= QTest::qExec(&tc, argc, argv);
    }
    return status;
}
