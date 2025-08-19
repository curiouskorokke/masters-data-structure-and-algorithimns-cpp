//
// Created by Nicholas  Ng on 19/08/2025.
//

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "Node.h"

template <typename T>
class BinarySearchTree
{
public:
    Node<T>* Insert(Node<T>* n, T val);
    void Search(T val);
};


template <typename T>
// Recursive Approach
Node<T>* BinarySearchTree<T>::Insert(Node<T>* n, T val)
{
    if (!n)
    {
        auto t = new Node<T>;
        t->data = val;
        n = t;
    }
    else
    {
        if (val < n->data)
        {
            n->lChild = Insert(n->lChild, val);
        }
        else
        {
            n->rChild = Insert(n->rChild, val);
        }
    }


    return n;
}

#endif //BINARYSEARCHTREE_H
