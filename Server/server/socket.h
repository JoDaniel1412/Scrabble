#ifndef SOCKET_H
#define SOCKET_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include "dataprocessor.h"


class Socket : public QThread
{
    Q_OBJECT
public:
    explicit Socket(qintptr ID, QObject *parent = 0);

    void run();

signals:
    void error(QTcpSocket::SocketError socketError);

public slots:
    void readyRead();
    void disconnected();

private:
    QTcpSocket *socket;
    qintptr socketDescriptor;
};

#endif // SOCKET_H
