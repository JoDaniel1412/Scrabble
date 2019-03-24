#include "tst_wordsdicttest.h"

WordsDictTest::WordsDictTest()
{

}

WordsDictTest::~WordsDictTest()
{

}

void WordsDictTest::test_isWord()
{
    QVERIFY(!WordsDict::isWord("dick"));
    QVERIFY(!WordsDict::isWord("DaRknEss"));
    QVERIFY(WordsDict::isWord("árbol"));
}
