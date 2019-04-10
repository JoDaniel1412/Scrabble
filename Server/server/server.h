#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include "socket.h"


class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);

    void start();

signals:

public slots:

protected:
    void incomingConnection(qintptr socketDescriptor);


private:
    QHostAddress IP;
    quint16 port;

};

#endif // SERVER_H
