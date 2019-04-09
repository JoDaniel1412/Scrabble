#ifndef STRINGTOJSON_H
#define STRINGTOJSON_H
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QByteArray>

#include <game/tile.h>
#include <game/board.h>
#include "jsonserializer.h"

class StringToJson
{
public:
    static QByteArray joinWindowObject(QString key, QString name);

    static QByteArray hostWindowObject(QString setKey, QString name, QString players);

    static QByteArray smsObject(QString string);

    static QByteArray letterInGridObject(char letters, int i, int j);

    static QByteArray boardObject(Board board);
};

#endif // STRINGTOJSON_H
