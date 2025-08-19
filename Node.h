//
// Created by Nicholas  Ng on 19/08/2025.
//

#ifndef NODE_H
#define NODE_H
template <typename T>
class Node
{
public:
    T data;
    Node* lChild;
    Node* rChild;
    Node();
    ~Node();
};

template <typename T>
Node<T>::Node()
{
    lChild = nullptr;
    rChild = nullptr;
}

template <typename T>
Node<T>::~Node()
{
    delete lChild;
    delete rChild;
}
#endif //NODE_H
