#ifndef LIST_H
#define LIST_H

#include "node.h"

template<class T>
class List
{
public:
    List();

    int value(int index);

    void printList();

    void pushHead(T value);

    void pushTail(T value);

    void deleteValue(int index);

    void clean();

    int getSize();

    int getHead();

    int getTail();

    Node<T> *getNode(int index);

private:
    int size;
    Node<T> head;
    Node<T> tail;
};

#endif // LIST_H
