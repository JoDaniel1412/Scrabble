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

void WordsDictTest::test_lettersValues()
{
    QHash<char, pair<int, int>> letters = WordsDict::getLettersValues();

    QCOMPARE(letters.value('0').first, 0);
    QCOMPARE(letters.value('0').second, 2);

    QCOMPARE(letters.value('S').first, 1);
    QCOMPARE(letters.value('S').second, 6);
}
