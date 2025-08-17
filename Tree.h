//
// Created by Nicholas  Ng on 16/08/2025.
//

#ifndef TREE_H
#define TREE_H
#include <sys/_types/_null.h>

#include<iostream>
#include "Queue.h"
#include "Stack.h"

using namespace std;

template <typename T>
class Node;

template <typename T>
class Tree
{
public:
    T data;
    Tree* lChild;
    Tree* rChild;
    Tree();
    ~Tree();
    void Create(Tree* root);
    void Preorder(Tree* t, Stack<Tree*>* st);
    void Inorder(Tree* t, Stack<Tree*>* st);
    void Postorder(Tree* t, Stack<Tree*>* st);
    void LevelOrder(Tree* t, Queue<Tree*>* st);
};

template <typename T>
Tree<T>::Tree()
{
    data = -1;
    lChild = nullptr;
    rChild = nullptr;
}

template <typename T>
Tree<T>::~Tree()
{
    delete lChild;
    delete rChild;
}

template <typename T>
void Tree<T>::Create(Tree* root)
{
    int rootValue;
    cout << "What will be the root value? ";
    cin >> rootValue;

    root->data = rootValue;

    Node<Tree*>* n = new Node<Tree*>;
    n->data = root;

    Queue<Tree*>* q = new Queue<Tree*>;
    q->Enqueue(n);

    while (!q->IsEmpty())
    {
        Node<Tree*>* fn = q->Dequeue();
        Tree* fq = fn->data;

        int leftChildValue;
        cout << "Insert left child value: ";
        cin >> leftChildValue;

        if (leftChildValue != -1)
        {
            Tree* leftChildTree = new Tree;
            leftChildTree->data = leftChildValue;
            fq->lChild = leftChildTree;
            Node<Tree*>* leftChildNode = new Node<Tree*>;
            leftChildNode->data = leftChildTree;
            q->Enqueue(leftChildNode);
        }

        int rightChildValue;
        cout << "Insert right child value: ";
        cin >> rightChildValue;

        if (rightChildValue != -1)
        {
            Tree* rightChildTree = new Tree;
            rightChildTree->data = rightChildValue;
            fq->rChild = rightChildTree;
            Node<Tree*>* rightChildNode = new Node<Tree*>;
            rightChildNode->data = rightChildTree;
            q->Enqueue(rightChildNode);
        }

        delete fn;
    }
}

template <typename T>
void Tree<T>::Preorder(Tree* t, Stack<Tree*>* st)
{
    if (t || !st->IsEmpty())
    {
        cout << t->data << " ";
        DoublyNode<Tree*>* n = new DoublyNode<Tree*>;
        n->data = t;
        st->Push(n);

        if (t->lChild)
        {
            Preorder(t->lChild, st);
        }

        if (t->rChild)
        {
            Preorder(t->rChild, st);
        }

        st->Pop();
    }
}

template <typename T>
void Tree<T>::Inorder(Tree* t, Stack<Tree*>* st)
{
    if (t || !st->IsEmpty())
    {
        if (t->lChild)
        {
            Inorder(t->lChild, st);
        }

        cout << t->data << " ";
        DoublyNode<Tree*>* n = new DoublyNode<Tree*>;
        n->data = t;
        st->Push(n);

        if (t->rChild)
        {
            Inorder(t->rChild, st);
        }

        st->Pop();
    }
}

template <typename T>
void Tree<T>::Postorder(Tree* t, Stack<Tree*>* st)
{
    if (t || !st->IsEmpty())
    {
        if (t->rChild)
        {
            Postorder(t->rChild, st);
        }

        if (t->lChild)
        {
            Postorder(t->lChild, st);
        }

        cout << t->data << " ";
        DoublyNode<Tree*>* n = new DoublyNode<Tree*>;
        n->data = t;
        st->Push(n);


        st->Pop();
    }
}

template <typename T>
void Tree<T>::LevelOrder(Tree* t, Queue<Tree*>* q)
{
    if (t || !q->IsEmpty())
    {
        cout << t->data << " ";

        if (t->lChild)
        {
            Node<Tree*>* nl = new Node<Tree*>;
            nl->data = t->lChild;
            q->Enqueue(nl);
        }

        if (t->rChild)
        {
            Node<Tree*>* nr = new Node<Tree*>;
            nr->data = t->rChild;
            q->Enqueue(nr);
        }

        if (!q->IsEmpty())
        {
            LevelOrder(q->Dequeue()->data, q);
        }

    }
}

#endif //TREE_H
