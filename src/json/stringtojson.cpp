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

QByteArray StringToJson::gameObject(Game game, Dock dock, Board board)
{
    QJsonObject jObject;
    QString boardJason = JsonSerializer::serialize(board);
    QString dockJason = JsonSerializer::serialize(dock);
    QString gameJason = JsonSerializer::serialize(game);

    jObject.insert("game", gameJason);
    jObject.insert("dock", dockJason);
    jObject.insert("board", boardJason);

    QJsonDocument doc(jObject);
    QByteArray data = doc.toJson(QJsonDocument::Compact);
    return data;
}

QJsonObject StringToJson::stringToJsonObject(const QString& data)
{
    QJsonObject obj;
    QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());

    if(!doc.isNull())
    {
        if(doc.isObject()) obj = doc.object();
        else qDebug() << "Document is not an object";
    }
    else qDebug() << "Invalid JSON...\n" << data;

    return obj;
}
