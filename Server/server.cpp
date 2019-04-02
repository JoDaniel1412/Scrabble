#include "server.h"
Server *Server::instance = 0;


Server::Server()
{
}

Server *Server::getInstance()
{
    if (instance == 0)
    {
        instance = new Server();
    }
    return instance;
}

void Server::setServerKey(int key)
{
    serverKey = key;
}
int Server::getServerKey()
{
    return serverKey;
}
