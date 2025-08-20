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
    int Height(Node<T>* n);
    Node<T>* InPre(Node<T>* n);
    Node<T>* InSuc(Node<T>* n);
    Node<T>* Insert(Node<T>* n, T val);
    void Search(Node<T>* n, T val);
    Node<T>* Delete(Node<T>* n, T val);
};

template <typename T>
int BinarySearchTree<T>::Height(Node<T>* n)
{
    int x, y;
    if (!n)
    {
        return 0;
    }

    x = Height(n->lChild);
    y = Height(n->rChild);

    return x > y ? x + 1 : y + 1;
}

template <typename T>
Node<T>* BinarySearchTree<T>::InPre(Node<T>* n)
{
    while (n && n->rChild)
    {
        n = n->rChild;
    }

    return n;
}

template <typename T>
Node<T>* BinarySearchTree<T>::InSuc(Node<T>* n)
{
    while (n && n->lChild)
    {
        n = n->lChild;
    }

    return n;
}


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
        cout << "Awww! " << val << " not found! :(" << endl;
        return;
    }

    if (val == n->data)
    {
        cout << "Awwww yisssss! " << val << " found!" << endl;
        return;
    }

    if (val < n->data)
    {
        Search(n->lChild, val);
    }
    else
    {
        Search(n->rChild, val);
    }
}

/*
 * There are three scenario to cater for in deletion
 * 1. Leaf node deletion
 * 2. Node deletion with child node
 * 3. Root node deletion
 *
 * For 2 and 3 , inorder predecessor / inrorder successor should replace the value :|
 */
template <typename T>
Node<T>* BinarySearchTree<T>::Delete(Node<T>* n, T val)
{
    if (val == n->data)
    {
        // N is a leaf node
        if (!n->lChild && !n->rChild)
        {
            cout << val << " found and deleted! wooohooo!";
            return nullptr;
        }

        // N is a root / parent node
        Node<T>* q;
        if (Height(n->lChild) > Height(n->rChild))
        {
            q = InPre(n->lChild);
            n->data = q->data;
            n->lChild = Delete(n->lChild, q->data);
        } else
        {
            q = InSuc(n->rChild);
            n->data = q->data;
            n->rChild = Delete(n->rChild, q->data);
        }

        return n;
    }

    if (val < n->data)
    {
        n->lChild = Delete(n->lChild, val);
    }
    else
    {
        n->rChild = Delete(n->rChild, val);
    }

    return n;
}

#endif //BINARYSEARCHTREE_H
