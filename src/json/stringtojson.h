#ifndef STRINGTOJSON_H
#define STRINGTOJSON_H
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QByteArray>

#include <game/tile.h>
#include <game/board.h>
#include <game/dock.h>
#include "jsonserializer.h"
#include <unordered_map>

class StringToJson
{
public:
    static QByteArray joinWindowObject(QString key, QString name);

    static QByteArray hostWindowObject(QString setKey, QString name, QString players);

    static QByteArray smsObject(QString string);

    static QByteArray letterInGridObject(char letters, int i, int j);

    static QByteArray boardObject(Board board);

    static QByteArray gameObject(Board board, Dock dock, unordered_map<string, int> players);
};

#endif // STRINGTOJSON_H
