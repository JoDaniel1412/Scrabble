#include "client.h"

Client::Client(QObject *parent) :
    QObject(parent)
{
    socket = new QTcpSocket();
    ip = "127.0.0.1";
    port = 12345;
}


bool Client::connectToHost()
{
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

QByteArray Client::readData()
{
    QThread::msleep(1000);
    QByteArray response = this->getSocket()->readAll();
    qDebug() << "Client reads: " << response;
    return response;
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

