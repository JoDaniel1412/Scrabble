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
