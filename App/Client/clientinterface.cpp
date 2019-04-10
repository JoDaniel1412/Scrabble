#include "clientinterface.h"

Game *ClientInterface::game = Game::getInstance();
Board *ClientInterface::board = Board::getInstance();
Dock *ClientInterface::dock = Dock::getInstance();
GameWindow *ClientInterface::gameWindow = nullptr;

void ClientInterface::updateGame(QString json)
{
    if (json == "") return;
    QJsonObject jsonObj = StringToJson::stringToJsonObject(json);

    QString jsonGame = jsonObj["game"].toString();
    QString jsonDock = jsonObj["dock"].toString();
    QString jsonBoard = jsonObj["board"].toString();

    JsonSerializer::parse(jsonGame, *game);
    JsonSerializer::parse(jsonDock, *dock);
    JsonSerializer::parse(jsonBoard, *board);

    gameWindow->updateGame();
}

void ClientInterface::askUpdate(QString playerID)
{
    QByteArray data = StringToJson::playerIDObject(playerID);
    QByteArray response = send(data);
    QString json(response);
    updateGame(json);
}

void ClientInterface::sendLetterAt(char letter, int i, int j, QString playerID)
{
    QByteArray data = StringToJson::letterInGridObject(letter, i, j, playerID);
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

void ClientInterface::setGameWindow(GameWindow *value)
{
    gameWindow = value;
}

QByteArray ClientInterface::send(QByteArray data)
{
    Client client;
    client.connectToHost();
    client.writeData(data);
    return client.readData();
}
