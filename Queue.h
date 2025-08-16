//
// Created by Nicholas  Ng on 16/08/2025.
//

#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;


template <typename T>
class Node
{
public:
    T data;
    Node* next;
    Node();
};

template <typename T>
Node<T>::Node()
{
    data = NULL;
    next = nullptr;
}

template <typename T>
class Queue
{
private:
    Node<T>* front;
    Node<T>* rear;

public:
    Queue();
    ~Queue();
    bool IsEmpty();
    void Enqueue(Node<T>* p);
    Node<T>* Dequeue();
};

template <typename T>
Queue<T>::Queue()
{
    front = rear = nullptr;
}

template <typename T>
Queue<T>::~Queue()
{
    delete front;
    delete rear;
}

template <typename T>
bool Queue<T>::IsEmpty()
{
    return front == nullptr && rear == nullptr;
}

template <typename T>
void Queue<T>::Enqueue(Node<T>* n)
{
    if (IsEmpty())
    {
        front = rear = n;
    }
    else
    {
        rear->next = n;
        rear = n;
    }
}

template <typename T>
Node<T>* Queue<T>::Dequeue()
{
    Node<T>* t;

    if (IsEmpty())
    {
        cout << "Ahoi! It's empty mate.";
        return NULL;
    }


    if (front == rear)
    {
        t = front;
        front = rear = nullptr;
        return t;
    }

    t = front;
    front = front->next;

    return t;
}


#endif //QUEUE_H
