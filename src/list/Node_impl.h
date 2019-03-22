//
// Created by José Acuña on 16/03/2019.
//

#include "list/Node.h"

template<class T>
Node<T>::Node() {
    next = nullptr;
    prev = nullptr;
}

template<class T>
Node<T>::Node(T value) {
    this->value = value;
    this->next = nullptr;
    this->prev = nullptr;
}

template<class T>
Node<T>::Node(T value, Node<T> *next, Node<T> *prev) {
    this->value = value;
    this->next = next;
    this->prev = prev;
}

template<class T>
T Node<T>::getValue() {
    return value;
}

template<class T>
void Node<T>::setValue(T value) {
    Node::value = value;
}

template<class T>
Node<T> *Node<T>::getNext() {
    return next;
}

template<class T>
void Node<T>::setNext(Node<T> *next) {
    Node::next = next;
}

template<class T>
Node<T> *Node<T>::getPrev() {
    return prev;
}

template<class T>
void Node<T>::setPrev(Node<T> *prev) {
    Node::prev = prev;
}