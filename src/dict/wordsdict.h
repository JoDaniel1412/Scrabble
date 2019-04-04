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

    /**
     * @brief getLettersValues are the point and amount of each letter
     * @return a QHash with key as the letter and a pair of point and amount as the value
     */
    static QHash<char, pair<int, int> > getLettersValues();

private:
    static QString path;
    static QHash<char, pair<int, int>> lettersValues;  // [Letter, [points, amount]]

    static QHash<char, pair<int, int>> loadLettersValues();
};

#endif // WORDSDICT_H
