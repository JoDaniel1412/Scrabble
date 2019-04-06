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
