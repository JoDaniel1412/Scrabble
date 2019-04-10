#include "server.h"

Server::Server(QObject *parent) :
    QTcpServer(parent)
{
    IP = QHostAddress::LocalHost;
    port = 12345;

    QList<QHostAddress> list = QNetworkInterface::allAddresses();

    for(int nIter=0; nIter<list.count(); nIter++)
    {
        if(!list[nIter].isLoopback())
        {
              if (list[nIter].protocol() == QAbstractSocket::IPv4Protocol )
              {
                  QString adress = list[nIter].toString();
              }
         }
    }
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
