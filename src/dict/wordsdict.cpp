#include "wordsdict.h"

#include <QDir>

QString WordsDict::path = QDir().rootPath() +
        "usr/share/dict/spanish";

QHash<char, pair<int, int>> WordsDict::lettersValues = loadLettersValues();

bool WordsDict::isWord(QString word)
{
    bool isWord = false;
    QString line;
    QFile file(path);

    // Opens and read the file
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in (&file);

        do {
            line = unaccent(in.readLine());
            if (!QString::compare(word, line, Qt::CaseInsensitive)) {
                isWord = true;
            }
        } while (!line.isNull());

        file.close();
    }
    else {
        string error =file.errorString().toStdString();
        cout << error << endl;
        exit(1);
    }

    return isWord;
}

int WordsDict::wordPoints(QString word)
{
    int result = 0;
    for (int i = 0; i < word.size(); i++)
    {
         char letter = word[i].toUpper().toLatin1();
         pair<int, int> values = lettersValues.value(letter);
         result += values.first;
    }

    return result;
}

QHash<char, pair<int, int> > WordsDict::getLettersValues()
{
    return lettersValues;
}

char WordsDict::popRandomLetter()
{
    QList<char> letters = lettersValues.keys();
    int index = rand() % letters.size();

    char letter = letters.at(index);
    pair<int, int> pair = lettersValues.value(letter);
    pair.second -= 1;

    return letter;
}

List<char> WordsDict::popRandomLettersList(int size)
{
    List<char> letters;
    for (int i = 0; i < size; i++)
    {
        letters.pushTail(popRandomLetter());
    }

    return letters;
}

QString WordsDict::unaccent(QString word)
{
    QString output(word.normalized(QString::NormalizationForm_D));
    return output.replace(QRegExp("[^a-zA-Z\\s]"), "");
}

QHash<char, pair<int, int>> WordsDict::loadLettersValues()
{
    // [Letter, [points, amount]]

    QHash<char, pair<int, int>> values;
    values.insert('0', make_pair(0, 2));

    values.insert('A', make_pair(1, 12));
    values.insert('E', make_pair(1, 12));
    values.insert('I', make_pair(1, 6));
    values.insert('O', make_pair(1, 9));
    values.insert('U', make_pair(1, 5));
    values.insert('L', make_pair(1, 4));
    values.insert('N', make_pair(1, 5));
    values.insert('S', make_pair(1, 6));
    values.insert('T', make_pair(1, 4));
    values.insert('R', make_pair(1, 5));

    values.insert('D', make_pair(2, 5));
    values.insert('G', make_pair(2, 2));

    values.insert('B', make_pair(3, 2));
    values.insert('C', make_pair(3, 4));
    values.insert('M', make_pair(3, 2));
    values.insert('P', make_pair(3, 2));

    values.insert('F', make_pair(4, 1));
    values.insert('H', make_pair(4, 2));
    values.insert('V', make_pair(4, 1));
    values.insert('Y', make_pair(4, 1));

    values.insert('Q', make_pair(5, 1));

    values.insert('J', make_pair(8, 1));
    values.insert('X', make_pair(8, 1));

    values.insert('Z', make_pair(10, 1));

    return values;
}
