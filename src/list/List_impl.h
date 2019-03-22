//
// Created by José Acuña on 15/03/2019.
//

#include "list/List.h"
#include <iostream>

using namespace std;

template<class T>
List<T>::List() {
    size = 0;
    head = nullptr;
    tail = nullptr;
}

template<class T>
List<T>::~List() { clean(); }

template<class T>
T List<T>::value(int index) {
    Node<T> *node = getNode(index);
    return node->getValue();
}

template<class T>
void List<T>::pushHead(T value) {
    auto *node = new Node<T>(value);

    if (size == 0) head = tail = node;
    else {
        node->setNext(head);
        head->setPrev(node);
        head = node;
    }

    size++;
}

template<class T>
void List<T>::pushTail(T value) {
    auto *node = new Node<T>(value);

    if (size == 0) tail = head = node;
    else {
        node->setPrev(tail);
        tail->setNext(node);
        tail = node;
    }

    size++;
}

template<class T>
void List<T>::printList() {
    Node<T> *node = head;

    while (node) {
        cout << node->getValue() << ", ";
        node = node->getNext();
    }

    cout << '\b' << '\b' << " " << endl; // Overwrites last ','
}

template<class T>
void List<T>::deleteValue(int index) {
    Node<T> *node = getNode(index);  // Gets the node in the index

    // Switch the node pointers
    Node<T> *nextNode = node->getNext();
    Node<T> *prevNode = node->getPrev();

    if (index == 0) head = nextNode; // In case the head is deleted
    else prevNode->setNext(nextNode);

    if (index == size - 1) tail = prevNode; // In case the tail is deleted
    else nextNode->setPrev(prevNode);

    delete node;
    size--;
}

template<class T>
void List<T>::clean() {
    Node<T> *node = head;

    while (node) {
        Node<T> *tmp = node;
        node = node->getNext();
        delete tmp;
    }
    size = 0;
    head = nullptr;
}

template<class T>
Node<T> *List<T>::getNode(int index) {
    if (index > size - 1) throw invalid_argument("Index out of range");
    if (index < 0) throw invalid_argument("Index cannot be less than 0");

    Node<T> *node;
    if (index < size / 2) { // Search the node from the Head
        node = head;
        for (int i = 0; i < index; i++) {
            node = node->getNext();
        }
    } else { // Search the node from the Tail
        node = tail;
        for (int i = size - 1; i > index; i--) {
            node = node->getPrev();
        }
    }
    return node;
}

template<class T>
int List<T>::getSize() {
    return size;
}

template<class T>
Node<T> *List<T>::getHead() {
    return head;
}

template<class T>
Node<T> *List<T>::getTail() {
    return tail;
}
