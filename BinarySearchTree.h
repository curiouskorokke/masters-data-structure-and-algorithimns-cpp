//
// Created by Nicholas  Ng on 19/08/2025.
//

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "TreeNode.h"
#include "Stack.h"

template <typename T>
class BinarySearchTree
{
public:
    int Height(TreeNode<T>* n);
    TreeNode<T>* InPre(TreeNode<T>* n);
    TreeNode<T>* InSuc(TreeNode<T>* n);
    TreeNode<T>* Insert(TreeNode<T>* n, T val);
    void Search(TreeNode<T>* n, T val);
    TreeNode<T>* Delete(TreeNode<T>* n, T val);
    TreeNode<T>* GenerateFromPreorder(TreeNode<T>* n, int* arr, int length);
};

template <typename T>
int BinarySearchTree<T>::Height(TreeNode<T>* n)
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
TreeNode<T>* BinarySearchTree<T>::InPre(TreeNode<T>* n)
{
    while (n && n->rChild)
    {
        n = n->rChild;
    }

    return n;
}

template <typename T>
TreeNode<T>* BinarySearchTree<T>::InSuc(TreeNode<T>* n)
{
    while (n && n->lChild)
    {
        n = n->lChild;
    }

    return n;
}


template <typename T>
// Recursive Approach
TreeNode<T>* BinarySearchTree<T>::Insert(TreeNode<T>* n, T val)
{
    if (!n)
    {
        auto t = new TreeNode<T>;
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
void BinarySearchTree<T>::Search(TreeNode<T>* n, T val)
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
 * 1. Leaf TreeNode deletion
 * 2. TreeNode deletion with child TreeNode
 * 3. Root TreeNode deletion
 *
 * For 2 and 3 , inorder predecessor / inrorder successor should replace the value :|
 */
template <typename T>
TreeNode<T>* BinarySearchTree<T>::Delete(TreeNode<T>* n, T val)
{
    if (val == n->data)
    {
        // N is a leaf TreeNode
        if (!n->lChild && !n->rChild)
        {
            cout << val << " found and deleted! wooohooo!" << endl;
            return nullptr;
        }

        // N is a root / parent TreeNode
        TreeNode<T>* q;
        if (Height(n->lChild) > Height(n->rChild))
        {
            q = InPre(n->lChild);
            n->data = q->data;
            n->lChild = Delete(n->lChild, q->data);
        }
        else
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

template <typename T>
TreeNode<T>* BinarySearchTree<T>::GenerateFromPreorder(TreeNode<T>* n, int* arr, int length)
{
    auto* st = new Stack<int>;
    TreeNode<T>* root = n;
    TreeNode<T>* prev = root;

    for (int i = 0; i < length; i++)
    {
        auto t = new TreeNode<T>;
        t->data = arr[i];

        if (!prev)
        {
            prev = t;
            root = t;
            continue;
        }

        if (arr[i] < prev->data)
        {
            prev->lChild = t;
            st->Push(prev);
            prev = t;
            continue;
        }

        while (arr[i] > prev->data && (st->top && arr[i] > st->top->data->data))
        {
            prev = st->Pop();
        }

        prev->rChild = t;
        prev = t;

    };

    return root;
}

#endif //BINARYSEARCHTREE_H
