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
    void Search(Node<T>* n, T val);
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

template <typename T>
void BinarySearchTree<T>::Search(Node<T>* n, T val)
{
    if (!n)
    {
        cout<<"Awww! "<<val<<" not found! :("<<endl;
        return;
    }

    if (val == n->data )
    {
        cout<<"Awwww yisssss! "<<val<<" found!"<<endl;
        return;
    }

    if (val < n->data)
    {
        Search(n->lChild, val);
    } else
    {
        Search(n->rChild, val);
    }
}

#endif //BINARYSEARCHTREE_H
