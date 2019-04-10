#include "dock.h"

Dock *Dock::instance = nullptr;

Dock::Dock()
{
    letters = new List<char>();
}

List<char> *Dock::getLetters() const
{
    return letters;
}

void Dock::setLetters(List<char> *value)
{
    letters = value;
}

void Dock::write(QJsonObject &jsonObj) const
{
    QJsonArray jsonArray;
    for (int i = 0; i < letters->getSize(); i++)
    {
        QString letter(letters->value(i));
        jsonArray.append(letter);
    }
    jsonObj["letters"] = jsonArray;
}

void Dock::read(const QJsonObject &jsonObj)
{
    letters->clean();

    // json encapsulates the QJsonArray
    QJsonArray jsonArray = jsonObj["letters"].toArray();
    foreach(QJsonValue jsonLetter, jsonArray)
    {
        char letter = jsonLetter.toString().toStdString().front();
        this->add(letter);
    }
}

Dock *Dock::getInstance()
{
    if (instance == nullptr) instance = new Dock();
    return instance;
}

void Dock::add(char letter)
{
    letters->pushTail(letter);
}

void Dock::remove(int index)
{
    letters->deleteValue(index);
}
