#ifndef NODE_H
#define NODE_H

template<class T>
class Node
{
public:
    Node();

    T getValue();

    Node *getNext();

    Node *getPrev();

private:
    T value;
    Node *next;
    Node *prev;
};

#endif // NODE_H
