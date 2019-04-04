#ifndef WORDSDICT_H
#define WORDSDICT_H

#include <fstream>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <cstdlib>
#include <list/List.h>

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

    /**
     * @brief popRandomLetter gets a letter from the list and removes on amount of it
     * @return a char
     */
    static char popRandomLetter();

    /**
     * @brief popRandomLettersList gets a list of random letters and removes on amount of each of them
     * @param size lenght of the list
     * @return a list of char
     */
    static List<char> popRandomLettersList(int size);

private:
    static QString path;
    static QHash<char, pair<int, int>> lettersValues;  // [Letter, [points, amount]]

    static QHash<char, pair<int, int>> loadLettersValues();
};

#endif // WORDSDICT_H
