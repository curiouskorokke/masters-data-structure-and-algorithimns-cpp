//
// Created by Nicholas  Ng on 16/08/2025.
//

#ifndef TREE_H
#define TREE_H
#include <sys/_types/_null.h>

#include<iostream>
#include "Queue.h"
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
    void Preorder(Tree* t);
    void Inorder(Tree* t);
    void Postorder(Tree* t);
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
        cout<<"Insert left child value: ";
        cin>>leftChildValue;

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
        cout<<"Insert right child value: ";
        cin>>rightChildValue;

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
void Tree<T>::Preorder(Tree* t) {

    if (t)
    {
        cout<<t->data<<" ";
        Preorder(t->lChild);
        Preorder(t->rChild);
    }
}

template <typename T>
void Tree<T>::Inorder(Tree* t) {

    if (t)
    {
        Inorder(t->lChild);
        cout<<t->data<<" ";
        Inorder(t->rChild);
    }
}

template <typename T>
void Tree<T>::Postorder(Tree* t) {

    if (t)
    {
        Postorder(t->lChild);
        Postorder(t->rChild);
        cout<<t->data<<" ";
    }
}


#endif //TREE_H
