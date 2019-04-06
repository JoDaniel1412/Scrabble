#ifndef DOCK_H
#define DOCK_H

#include <list/List.h>


class Dock
{
public:
    static Dock *getInstance();

    void add(char letter);

    void remove(int index);


    List<char> *getLetters() const;
    void setLetters(List<char> *value);

private:
    Dock();

    static Dock *instance;
    List<char> *letters;
};

#endif // DOCK_H
