#include "dataprocessor.h"
#include <QDebug>



dataProcessor::dataProcessor()
{}

void dataProcessor::receiver(QString data)
{
    QJsonObject obj = dataProcessor::StringToJson(data);
    qDebug()<<obj;
    QString key = obj.value("keyi").toString();
    qDebug()<<key;
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
