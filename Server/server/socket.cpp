#include "socket.h"

Socket::Socket(qintptr ID, QObject *parent) :
    QThread (parent)
{
    this->socketDescriptor = ID;
}

void Socket::run()
{
    qDebug() <<  "Starting socket :" << socketDescriptor;
    socket = new QTcpSocket();
    if (!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()), Qt::DirectConnection);

    //qDebug() << "Client connected :" << socketDescriptor;

    exec();
}

void Socket::readyRead()
{
    QByteArray data = socket->readAll();
    qDebug() << "Reading data" << data;

    dataProcessor::receiver(data);

    QString response = dataSender::getInfoToSend();
    socket->write(response.toUtf8());
    qDebug() << "Sending data";
}

void Socket::disconnected()
{
    //qDebug() << "Disconnected : " << socketDescriptor;
    socket->deleteLater();
    exit(0);
}
