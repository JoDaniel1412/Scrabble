#include "clientinterface.h"

Game *ClientInterface::game = Game::getInstance();
Board *ClientInterface::board = Board::getInstance();
Dock *ClientInterface::dock = Dock::getInstance();

void ClientInterface::updateGame(string json)
{
    unordered_map<string, int> *players;
    game->setPlayers(players);

    List<char> *letters;
    dock->setLetters(letters);

    List<List<Tile *>*> *matrix;
    board->setMatrix(matrix);
}

void ClientInterface::sendLetterAt(char letter, int i, int j)
{
    QByteArray data = StringToJson::tileObject(letter, i, j);
    send(data);
}

void ClientInterface::sendSMS(string word)
{
    QString qword = QString::fromStdString(word);
    QByteArray data = StringToJson::smsObject(qword);
    send(data);
}

void ClientInterface::send(QByteArray data)
{
    Client client;
    client.connectToHost();
    client.writeData(data);
    QByteArray response = client.getSocket()->readAll();
}
