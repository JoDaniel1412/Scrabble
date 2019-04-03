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
        QTcpSocket *socket = server->nextPendingConnection();
        connect(socket, SIGNAL(readyRead()), SLOT(readyRead()));
        connect(socket, SIGNAL(disconnected()), SLOT(disconnected()));
        QByteArray *buffer = new QByteArray();
        qint32 *s = new qint32(0);
        buffers.insert(socket, buffer);
        sizes.insert(socket, s);


    }
}

void serverConnection::disconnected()
{
    QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
    QByteArray *buffer = buffers.value(socket);
    qint32 *s = sizes.value(socket);
    socket->deleteLater();
    delete(buffer);
    delete s;
}


void serverConnection::readyRead()
{
    QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
    qint64 size = socket->bytesAvailable();
    QByteArray byteArray = socket->read(size);
    QString data = QString::fromStdString(byteArray.toStdString());
    dataProcessor::receiver(data);

}



