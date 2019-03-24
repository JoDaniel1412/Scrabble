//
// Created by José Acuña on 16/03/2019.
//

#ifndef DATASTRUCTURES_CXX_NODE_H
#define DATASTRUCTURES_CXX_NODE_H

template<class T>
class Node {

public:
    // Constructors

    Node();

    explicit Node(T value);

    Node(T value, Node<T> *next, Node<T> *prev);

    ~Node() = default;


    // Methods

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

#include "../../src/list/Node_impl.h"

#endif //DATASTRUCTURES_CXX_NODE_H
