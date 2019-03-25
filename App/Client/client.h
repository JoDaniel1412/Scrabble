#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QtCore>
#include <QtNetwork>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);


public slots:
    bool connectToHost();
    bool writeData(QByteArray data);
    QByteArray IntToArray(qint32 source);
private:
   QTcpSocket *socket;
};

#endif // CLIENT_H
