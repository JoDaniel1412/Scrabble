#ifndef STRINGTOJSON_H
#define STRINGTOJSON_H
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QByteArray>

class StringToJson
{
public:
    static QByteArray joinWindowObject(QString key, QString name);

    static QByteArray hostWindowObject(QString setKey, QString name, QString players);

    static QByteArray smsObject(QString string);

    static QByteArray tileObject(char letters, int i, int j);

private:
    StringToJson();
};

#endif // STRINGTOJSON_H
