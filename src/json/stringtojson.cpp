#include "stringtojson.h"

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

QByteArray StringToJson::letterInGridObject(char letter, int i, int j)
{
    QJsonObject jObject;
    jObject.insert("letter", letter);
    jObject.insert("i", i);
    jObject.insert("j", j);
    QJsonDocument doc(jObject);
    QByteArray data = doc.toJson(QJsonDocument::Compact);
    return data;
}

QByteArray StringToJson::boardObject(Board board)
{
    QString json = JsonSerializer::serialize(board);
    QJsonObject jObject;
    QJsonDocument doc(jObject);
    QByteArray data = doc.toJson(QJsonDocument::Compact);
    return data;
}

QByteArray StringToJson::gameObject(Board board, Dock dock, unordered_map<string, int> players)
{
    QJsonObject jObject;
    QString boardJason = JsonSerializer::serialize(board);

    jObject.insert("board", boardJason);
    //jObject.insert("dock", i);
    //jObject.insert("players", j);

    QJsonDocument doc(jObject);
    QByteArray data = doc.toJson(QJsonDocument::Compact);
    return data;
}
