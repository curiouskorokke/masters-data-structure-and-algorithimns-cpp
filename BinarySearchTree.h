//
// Created by Nicholas  Ng on 19/08/2025.
//

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "Node.h"

template <typename T>
class BinarySearchTree
{
private:
    Node<T>* root;

public:
    BinarySearchTree();
    void Insert(T val);
    ~BinarySearchTree();
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
    root = nullptr;
}

template <typename T>
// Iterative Approach
void BinarySearchTree<T>::Insert(T val)
{
    if (!root)
    {
        auto r = new Node<T>;
        r->data = val;
        root = r;
        return;
    }

    auto t = root;
    Node<T>* r;

    while (t)
    {
        r = t;
        if (val == t->data)
        {
            cout << "Value already exist!" << endl;
            return;
        }

        if (val < t->data)
        {
            t = t->lChild;
        }
        else
        {
            t = t->rChild;
        }
    }

    auto n = new Node<T>;
    n->data = val;
    if (val < r->data)
    {
        r->lChild = n;
    }
    else
    {
        r->rChild = n;
    }
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
    delete root;
}

#endif //BINARYSEARCHTREE_H
