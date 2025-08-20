//
// Created by Nicholas  Ng on 20/08/2025.
//

#ifndef STACK_H
#define STACK_H

#include "TreeNode.h"

template <typename T>
class Node
{
public:
    T data;
    Node* next;
};

template <typename T>
class Stack
{
public:
    Node<TreeNode<T>*>* top;
    Stack();
    ~Stack();
    void Push(TreeNode<T>* n);
    TreeNode<T>* Pop();
};

template <typename T>
Stack<T>::Stack()
{
    top = nullptr;
}

template <typename T>
Stack<T>::~Stack()
{
    Node<T>* n = top;

    while (n)
    {
        Node<T>* temp = n;
        n = n->next;
        delete temp;
    }
}

template <typename T>
void Stack<T>::Push(TreeNode<T>* n)
{
    auto* t = new Node<TreeNode<T>*>;
    t->data = n;

    if (!top)
    {
        top = t;
        t->next = nullptr;
        return;
    }

    t->next = top;
    top = t;
}

template <typename T>
TreeNode<T>* Stack<T>::Pop()
{
    if (!top)
    {
        cout << "Stack is empty boss!" << endl;
        return nullptr;
    }

    auto temp = top;
    top = top->next;

    return temp->data;
}
#endif //STACK_H
