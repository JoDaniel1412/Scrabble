#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H
#include <QJsonObject>
#include <QString>
#include <QJsonDocument>

class dataProcessor
{
    private:
        dataProcessor();
        static QJsonObject StringToJson(const QString& data);


    public:

        static void receiver(QString data);

};

#endif // DATAPROCESSOR_H
