#include "node.h"

template<class T>
Node<T>::Node()
{
     value = nullptr;
     next = nullptr;
     prev = nullptr;
}

template<class T>
T Node<T>::getValue()
{
    return value;
}

template<class T>
Node<T> *Node<T>::getNext() {
    return next;
}

template<class T>
Node<T> *Node<T>::getPrev() {
    return prev;
}
