#include "datasender.h"

QString dataSender::infoToSend = "";

dataSender::dataSender()
{
}

QString dataSender::getInfoToSend()
{
    return dataSender::infoToSend;
}

void dataSender::setInfoToSend(QString data)
{
    dataSender::infoToSend = data;
}

QString dataSender::dataToSend()
{
    QString response = "";
    if(dataSender::getInfoToSend() == "canJoin")
    {
        response = "canJoin";
    }

    qDebug() << "Server sending: " << response;
    return response;
}
