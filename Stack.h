//
// Created by Nicholas  Ng on 17/08/2025.
//

#ifndef STACK_H
#define STACK_H
#include <sys/_types/_null.h>

template <typename T>
class DoublyNode
{
public:
    T data;
    DoublyNode* prev;
    DoublyNode* next;
    DoublyNode();
    ~DoublyNode();
};

template <typename T>
DoublyNode<T>::DoublyNode()
{
    data = NULL;
    prev = nullptr;
    next = nullptr;
}

template <typename T>
DoublyNode<T>::~DoublyNode()
{
    delete prev;
    delete next;
}

template <typename T>
class Stack
{
private:
    DoublyNode<T>* top;

public:
    Stack();
    ~Stack();
    bool IsEmpty();
    void Push(DoublyNode<T>* n);
    DoublyNode<T>* Pop();
};

template <typename T>
Stack<T>::Stack()
{
    top = nullptr;
}

template <typename T>
Stack<T>::~Stack()
{
    delete top;
}

template <typename T>
bool Stack<T>::IsEmpty()
{
    return !top;
}

template <typename T>
void Stack<T>::Push(DoublyNode<T>* n)
{
    if (top)
    {
        DoublyNode<T>* curr = top;
        top->next = n;
        top = n;
        top->prev = curr;
    } else
    {
        top = n;
    }
}

template <typename T>
DoublyNode<T>* Stack<T>::Pop()
{
    DoublyNode<T>* n = top;

    if (top->prev)
    {
        top->prev->next = nullptr;
        top = top->prev;
    }
    else
    {
        top = nullptr;
        n = top;
    }


    return n;
}


#endif //STACK_H
