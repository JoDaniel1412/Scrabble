#include "server.h"


//static inline qint32 ArrayToInt(QByteArray source);

Server::Server(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()), SLOT(newConnection()));
    qDebug() << "Listening:" << server->listen(QHostAddress::Any, 12345);
}

void Server::newConnection()
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

void Server::disconnected()
{
    QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
    QByteArray *buffer = buffers.value(socket);
    qint32 *s = sizes.value(socket);
    socket->deleteLater();
    delete(buffer);
    delete s;
}

/*
    QTcpSocket *socket = server->nextPendingConnection();
    socket->write("Hello client \n");
    socket->flush();
    socket->close();
    qDebug()<< "New connection\n";
  */

void Server::readyRead()
{
    QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
    QByteArray *buffer = buffers.value(socket);
    qint32 *s = sizes.value(socket);
    qint32 size = *s;
    while(socket->bytesAvailable()>0)
    {
        qDebug() << socket->readAll()<<"\n";
        buffer->append(socket->readAll());
        while((size == 0 && buffer->size() >= 4) || (size > 0 && buffer->size() >= size)) //while can procces data, process it
        {
            if (size == 0 && buffer->size() >= 4) //if size of data has received completely, then store it in out global variable
            {
               // size = ArrayToIint(buffer->mid(0,4));
                //*s = size;
                buffer->remove(0,4);
            }
            if(size > 0 && buffer->size() >= size) //if data has reveived completely, then emit our SIGNAL with data
            {
                QByteArray data = buffer->mid(0, size);
                buffer->remove(0, size);
                size = 0;
                emit dataReceived(data);
            }
        qDebug() << socket->readAll()<<"\n";
        }
    }
}



qint32 ArrayToIint(QByteArray source)
{
    qint32 temp;
    QDataStream data(&source, QIODevice::ReadWrite);
    data >> temp;
    return temp;
}
