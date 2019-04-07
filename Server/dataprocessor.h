#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H
#include <QJsonObject>
#include <QString>
#include <QJsonDocument>
#include <serverdata.h>
#include <datasender.h>

class dataProcessor
{
    private:
        dataProcessor();
        static QJsonObject StringToJson(const QString& data);
        static void setMatchKey(QString key);


    public:

        static void receiver(QString data);

};

#endif // DATAPROCESSOR_H
