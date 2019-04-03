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
private:
    StringToJson();
};

#endif // STRINGTOJSON_H
