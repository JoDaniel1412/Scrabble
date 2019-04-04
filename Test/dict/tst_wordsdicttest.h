#ifndef TST_WORDSDICTTEST_H
#define TST_WORDSDICTTEST_H

#include <QTest>
#include <fstream>
#include "dict/wordsdict.h"

class WordsDictTest : public QObject
{
    Q_OBJECT

public:
    WordsDictTest();
    ~WordsDictTest();

private slots:
    void test_isWord();
    void test_lettersValues();
    void test_popRandomLetter();
    void test_popRandomLettersList();
    void test_wordPoint();
};

#endif // TST_WORDSDICTTEST_H
