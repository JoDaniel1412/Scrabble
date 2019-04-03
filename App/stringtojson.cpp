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
