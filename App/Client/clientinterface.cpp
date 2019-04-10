#include "clientinterface.h"

Game *ClientInterface::game = Game::getInstance();
Board *ClientInterface::board = Board::getInstance();
Dock *ClientInterface::dock = Dock::getInstance();

void ClientInterface::updateGame(QString json)
{
    QJsonObject jsonObj = StringToJson::stringToJsonObject(json);

    QString jsonGame = jsonObj["game"].toString();
    QString jsonDock = jsonObj["dock"].toString();
    QString jsonBoard = jsonObj["board"].toString();

    JsonSerializer::parse(jsonGame, *game);
    JsonSerializer::parse(jsonDock, *dock);
    JsonSerializer::parse(jsonBoard, *board);
}

void ClientInterface::sendLetterAt(char letter, int i, int j)
{
    QByteArray data = StringToJson::letterInGridObject(letter, i, j);
    QByteArray response = send(data);
    QString json(response);
    updateGame(json);
}

void ClientInterface::sendSMS(string word)
{
    QString qword = QString::fromStdString(word);
    QByteArray data = StringToJson::smsObject(qword);
    send(data);
}

QByteArray ClientInterface::send(QByteArray data)
{
    Client client;
    client.connectToHost();
    client.writeData(data);
    return client.getSocket()->readAll();
}
