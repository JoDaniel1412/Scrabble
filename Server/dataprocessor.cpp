#include "dataprocessor.h"
#include <QDebug>



dataProcessor::dataProcessor()
{}

void dataProcessor::receiver(QString data)
{
    qInfo() << "Server received: " << data;
    QJsonObject obj = dataProcessor::StringToJson(data);
    QJsonValue MatchKey = obj.value("setKey");
    if (MatchKey.toString() != "")
    {
        QString key = MatchKey.toString();
        dataProcessor::setMatchKey(key);
        dataSender::setInfoToSend("canJoin");
    }
    if (obj.value("key").toString() == serverData::getInstance()->getKey())
    {
        dataSender::setInfoToSend("canJoin");
    }
    QString playerID = obj.value("name").toString();
    if (playerID != "")GameInterface::addPlayerID(playerID);

    QString playerToUpdate = obj.value("update").toString();
    if (playerToUpdate != "") GameInterface::updateGameToSend(playerToUpdate);

}

QJsonObject dataProcessor::StringToJson(const QString& data)
{
    QJsonObject obj;

    QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());

    if(!doc.isNull())
        {
            if(doc.isObject())
            {
                obj = doc.object();
            }
            else
            {
                qDebug() << "Document is not an object" << endl;
            }
        }
        else
        {
            qDebug() << "Invalid JSON...\n" << data << endl;
        }

        return obj;
}


void dataProcessor::setMatchKey(QString key)
{
    serverData::getInstance()->setKey(key);
    qDebug() << "Match key set as: " << key;

}
