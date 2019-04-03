#include "wordsdict.h"

#include <QDir>

QString WordsDict::path = QDir().rootPath() +
        "usr/share/dict/spanish";

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
            line = in.readLine();
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
