#ifndef DATASENDER_H
#define DATASENDER_H
#include <QString>
#include <QDebug>
#include <QThread>


class dataSender
{
public:
    dataSender();
    static void setInfoToSend(QString data);
    static QString getInfoToSend();
    static QString dataToSend();
private:
    static QString infoToSend;


};

#endif // DATASENDER_H
