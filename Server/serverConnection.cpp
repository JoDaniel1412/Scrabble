#include "serverConnection.h"
#include <iostream>
using namespace std;
#include "dataprocessor.h"

serverConnection::serverConnection(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()), SLOT(newConnection()));
    qDebug() << "Listening:" << server->listen(QHostAddress::Any, 12345);
}

void serverConnection::newConnection()
{
    while(server->hasPendingConnections())
    {
        socket = server->nextPendingConnection();
        connect(socket, SIGNAL(readyRead()), SLOT(readyRead()), Qt::DirectConnection);
        connect(socket, SIGNAL(disconnected()), SLOT(disconnected()));
    }
}

void serverConnection::disconnected()
{
    //QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
    QByteArray *buffer = buffers.value(socket);
    qint32 *s = sizes.value(socket);
    socket->deleteLater();
    delete(buffer);
    delete s;
    exit(0);
}


void serverConnection::readyRead()
{
    //QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
    qint64 size = socket->bytesAvailable();
    QByteArray byteArray = socket->read(size);
    QString data = QString::fromStdString(byteArray.toStdString());
    dataProcessor::receiver(data);

    QString response = dataSender::getInfoToSend();
    socket->write(response.toUtf8());
    qDebug() << "Server sending: " << response;

}



