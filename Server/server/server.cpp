#include "server.h"

Server::Server(QObject *parent) :
    QTcpServer(parent)
{
    IP = QHostAddress("192.168.100.10");
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
        qDebug() << this->serverAddress() << ":" << port;
    }
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    //qDebug() << "Connecting :" << socketDescriptor;
    Socket *socket = new Socket(socketDescriptor, this);
    connect(socket, SIGNAL(finished()), socket, SLOT(deleteLater()));
    socket->start();
}
