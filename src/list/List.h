//
// Created by José Acuña on 15/03/2019.
//

#ifndef DATASTRUCTURES_CXX_LIST_H
#define DATASTRUCTURES_CXX_LIST_H

#include "list/Node.h"

template<class T>
class List {

public:
    List();

    ~List();

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

#include "../../src/list/List_impl.h"

#endif //DATASTRUCTURES_CXX_LIST_H
