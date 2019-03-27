#ifndef SMS_H
#define SMS_H

#include <string>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QAuthenticator>
#include <QUrlQuery>
#include <QObject>

using namespace std;

class SMS : public QObject
{
    Q_OBJECT

public:
    SMS() = default;
    ~SMS() = default;

    void sendMessage(QString to, QString from, QString body);

    QString getGameMaster() const;

    QString getTwilio() const;

private slots:
    void replyFinished(QNetworkReply *);
    void provideAuthenication(QNetworkReply*,QAuthenticator*);

private:
    const QString account_sid = "ACb3783348901163d362e74b52ec2af18c";
    const QString auth_token = "e3641f15a39fcfa8cab8a0a13cc40639";
    const QString gameMaster = "+50670247476";
    const QString twilio = "+12017204633";

};

#endif // SMS_H
