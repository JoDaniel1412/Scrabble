#include "server.h"

Server::Server(QObject *parent) :
    QTcpServer(parent)
{
    IP = QHostAddress::Any;
    port = 12345;
}

void Server::start()
{
    if(!this->listen(IP, port))
    {
        qDebug() << "Failed to start Server";
    }
    else {
        qDebug() << "Listening..";
        qDebug() << IP << ":" << port;
    }
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << "Connecting :" << socketDescriptor;
    Socket *socket = new Socket(socketDescriptor, this);
    connect(socket, SIGNAL(finished()), socket, SLOT(deleteLater()));
    socket->start();
}
