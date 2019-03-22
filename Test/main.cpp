#include "tst_boardtest.cpp"
#include "tst_tiletest.cpp"



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
       return status;
}
