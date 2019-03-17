#ifndef NODE_H
#define NODE_H

template<class T>
class Node
{
public:
    Node();

    Node(T value);

    Node(T value, Node<T> *next, Node<T> *prev);

    T getValue();

    void setValue(T value);

    Node<T> *getNext();

    void setNext(Node<T> *next);

    Node<T> *getPrev();

    void setPrev(Node<T> *prev);

private:
    T value;
    Node<T> *next;
    Node<T> *prev;
};

#include "node_impl.h"

#endif // NODE_H
