#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QtCore>
#include <QTcpSocket>
#include <QThreadPool>
#include <QDebug>
#include <propertieswindow.h>


class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);

public slots:

    bool connectToHost();
    bool writeData(QByteArray data);
    QByteArray readData();
    void setServerKey(int serverKey);
    int getServerKey();
    QTcpSocket* getSocket();

private:
   QTcpSocket *socket;
   int serverKey;
   QString ip;
   quint16 port;
};

#endif // CLIENT_H
