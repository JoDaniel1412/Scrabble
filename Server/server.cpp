#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
    if(!server->listen(QHostAddress::Any, 12345))
    {
        qDebug()<<"Server";
    }
    else
    {
        qDebug() << "Server started";
    }
}

void Server::newConnection()
{
    QTcpSocket *socket = server->nextPendingConnection();
    socket->write("Hello client \n");
    socket->flush();
    socket->close();
}
