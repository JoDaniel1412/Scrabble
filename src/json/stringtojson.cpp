#include "stringtojson.h"

StringToJson::StringToJson()
{

}

QByteArray StringToJson::joinWindowObject(QString key, QString name)
{
    QJsonObject jObject;
    jObject.insert("key", key);
    jObject.insert("name", name);
    QJsonDocument doc(jObject);
    QByteArray data = doc.toJson(QJsonDocument::Compact);
    return data;
}

QByteArray StringToJson::hostWindowObject(QString setKey, QString name, QString players)
{
    QJsonObject jObject;
    jObject.insert("setKey", setKey);
    jObject.insert("name", name);
    jObject.insert("players", players);
    QJsonDocument doc(jObject);
    QByteArray data = doc.toJson(QJsonDocument::Compact);
    return data;
}

QByteArray StringToJson::smsObject(QString string)
{
    QJsonObject jObject;
    jObject.insert("word", string);
    QJsonDocument doc(jObject);
    QByteArray data = doc.toJson(QJsonDocument::Compact);
    return data;
}

QByteArray StringToJson::tileObject(char letter, int i, int j)
{
    QJsonObject jObject;
    jObject.insert("letter", letter);
    jObject.insert("i", i);
    jObject.insert("j", j);
    QJsonDocument doc(jObject);
    QByteArray data = doc.toJson(QJsonDocument::Compact);
    return data;
}
