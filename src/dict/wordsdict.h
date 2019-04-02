#ifndef WORDSDICT_H
#define WORDSDICT_H

#include <fstream>
#include <iostream>
#include <QFile>
#include <QTextStream>

using namespace std;

class WordsDict
{
public:

    /**
     * @brief isWord reads a dictionari to check is the word exist
     * @param word to serch
     * @return a boolean
     */
    static bool isWord(QString word);

private:
    static QString path;
};

#endif // WORDSDICT_H
