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
    if(dataSender::getInfoToSend() =="canJoin")
    {
        return "canJoin";
    }
}
