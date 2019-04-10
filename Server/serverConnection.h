#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtCore>
#include <datasender.h>
class Server;

class serverConnection : public QObject
{
    Q_OBJECT
public:
    explicit serverConnection(QObject *parent = 0);
    void setServerKey(int serverKey);
    int getServerKey();

signals:
    void dataReceived(QByteArray);

public slots:
    void newConnection();
    void disconnected();
    void readyRead();

private:
    QTcpServer *server;
    QTcpSocket *socket;
    int *serverKey;
    QHash<QTcpSocket*, QByteArray*> buffers; //We need a buffer to store data until block has completely received
    QHash<QTcpSocket*, qint32*> sizes; //We need to store the size to verify if a block has received completely
};
#endif // SERVER_H
