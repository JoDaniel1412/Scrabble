#ifndef LIST_H
#define LIST_H

#include "node.h"

template<class T>
class List
{
public:
    List();

    T value(int index);

    void printList();

    void pushHead(T value);

    void pushTail(T value);

    void deleteValue(int index);

    void clean();

    int getSize();

    Node<T> *getHead();

    Node<T> *getTail();

    Node<T> *getNode(int index);

private:
    int size;
    Node<T> *head;
    Node<T> *tail;
};

#include "list_impl.h"

#endif // LIST_H
