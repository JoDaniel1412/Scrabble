#ifndef STRINGTOJSON_H
#define STRINGTOJSON_H
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QByteArray>
#include <QDebug>

#include "game/tile.h"
#include "game/board.h"
#include "game/dock.h"
#include "game/game.h"
#include "jsonserializer.h"
#include <unordered_map>

class StringToJson
{
public:
    static QByteArray joinWindowObject(QString key, QString name);

    static QByteArray hostWindowObject(QString setKey, QString name, QString players);

    static QByteArray smsObject(QString string);

    static QByteArray playerIDObject(QString playerID);

    static QByteArray letterInGridObject(char letters, int i, int j);

    static QByteArray boardObject(Board board);

    static QByteArray gameObject(Game game, Dock dock, Board board);

    static QJsonObject stringToJsonObject(const QString& data);
};

#endif // STRINGTOJSON_H
