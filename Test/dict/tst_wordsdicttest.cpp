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
	QVERIFY(WordsDict::isWord("arbol"));
    QVERIFY(WordsDict::isWord("SASTRE"));
    QVERIFY(WordsDict::wordPoints("perro"));
    QVERIFY(WordsDict::wordPoints("casa"));
}

void WordsDictTest::test_lettersValues()
{
    QHash<char, pair<int, int>> letters = WordsDict::getLettersValues();

    QCOMPARE(letters.value('0').first, 0);
    QCOMPARE(letters.value('0').second, 2);

    QCOMPARE(letters.value('S').first, 1);
    QCOMPARE(letters.value('S').second, 6);
}

void WordsDictTest::test_popRandomLetter()
{
    QHash<char, pair<int, int>> letters = WordsDict::getLettersValues();

    WordsDict::popRandomLetter();
    WordsDict::popRandomLetter();
    WordsDict::popRandomLetter();
}

void WordsDictTest::test_popRandomLettersList()
{
    List<char> *letters = WordsDict::popRandomLettersList(4);

    QCOMPARE(letters->getSize(), 4);
}

void WordsDictTest::test_wordPoint()
{
	int points = WordsDict::wordPoints("arbol");
    QCOMPARE(points, 7);
}
