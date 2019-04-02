#include "sms.h"

void SMS::sendMessage(QString to, QString from, QString body)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager();

    // Creates the url
    QString path = "https://api.twilio.com/2010-04-01/Accounts/" + account_sid + "/Messages.json";
    QUrl url(path);
    QNetworkRequest request(url);

    // Creates the Request
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QUrlQuery query(url);
    query.addQueryItem("To", to);
    query.addQueryItem("From", from);
    query.addQueryItem("Body", body);

    url.setQuery(query);

    QObject::connect(manager, SIGNAL(finished(QNetworkReply *)),
            this, SLOT(replyFinished(QNetworkReply *)));
    QObject::connect(manager, SIGNAL(authenticationRequired(QNetworkReply*,QAuthenticator*)),
                     this, SLOT(provideAuthenication(QNetworkReply*,QAuthenticator*)));

    // Makes the request
    manager->post(request, query.query(QUrl::FullyEncoded).toUtf8());
}

void SMS::replyFinished(QNetworkReply *reply)
{
    qDebug() << reply->readAll();
}

void SMS::provideAuthenication(QNetworkReply *, QAuthenticator *auth)
{
    auth->setUser(account_sid);
    auth->setPassword(auth_token);
}

QString SMS::getTwilio() const
{
    return twilio;
}

QString SMS::getGameMaster() const
{
    return gameMaster;
}
