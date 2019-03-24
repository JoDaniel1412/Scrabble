#include "wordsdict.h"

#include <QDir>

QString WordsDict::path = QDir().rootPath() +
        "usr/share/dict/words";

bool WordsDict::isWord(QString word)
{
    bool isWord = false;
    QString line;
    QFile file(path);

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
