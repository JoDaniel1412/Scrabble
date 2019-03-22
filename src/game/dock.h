#ifndef DOCK_H
#define DOCK_H

#include <list/List.h>


class Dock
{
public:
    Dock *getInstance();

    void add(char letter);

    void remove(int index);

private:
    Dock();

    static Dock *instance;
    List<char> *letters;
};

#endif // DOCK_H
