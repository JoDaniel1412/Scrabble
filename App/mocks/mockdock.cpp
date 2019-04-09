#include "mockdock.h"


void MockDock::makeLetters(){

    Dock * dock = Dock::getInstance();

    dock->add('a');
    dock->add('x');
    dock->add('c');
    dock->add('n');
    dock->add('a');
    dock->add('f');
    dock->add('d');
    dock->add('s');
    dock->add('j');
}

void MockDock::updateLetters()
{
    Dock * dock = Dock::getInstance();
    List<char> * newDock = new List<char>();

    newDock->pushTail('f');
    newDock->pushTail('u');
    newDock->pushTail('n');
    newDock->pushTail('c');
    newDock->pushTail('a');

    dock->setLetters(newDock);
}

void MockDock::makeNewBoard()
{
    Board * board = Board::getInstance();

    board->putLetter(3, 4, 'z');
    board->putLetter(12, 4, 'a');
    board->putLetter(3, 9, 's');

}
