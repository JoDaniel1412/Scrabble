#include "dock.h"

Dock *Dock::instance = nullptr;

Dock::Dock()
{
    letters = new List<char>();
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

List<char> *Dock::getLetters()
{
    return letters;
}
