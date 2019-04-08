#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
}

bool Client::connectToHost()
{
    QString ip = "127.0.0.1";
    quint16 port = 12345;
    socket->connectToHost(ip, port);
    qInfo() << "Client conecting to: " << ip << ":"<< port;
    return socket->waitForConnected();
}

bool Client::writeData(QByteArray data)
{
    if(socket->state() == QAbstractSocket::ConnectedState)
    {
        //socket->write(IntToArray(data);  //write size of data
        socket->write(data);  //write the data itself
        qInfo() << "Client sending: " << data;
        return socket->waitForBytesWritten();
    }
    else
        return false;
}


void Client::setServerKey(int Key)
{
    this->serverKey = Key;
}

int Client::getServerKey()
{
    return this->serverKey;
}

QTcpSocket* Client::getSocket()
{
    return this->socket;
}

