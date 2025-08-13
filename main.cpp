#include<iostream>

using namespace std;

/*
 * Queue (FIFO - First In, First Out)
 * Insertion on back and removal at front
 */

/*
 * ADT
 * Data - size, first, rear, array
 * Method - enqueue, dequeue, DIsplay, isEmpty, isFull
 *
 * What the the drawbacks for implementing Queue using array
 * 1. Unable to re-fill spaces of deleted elements because elements are not shift to the left once deleted from front.
 * 2. Because of point 1 , each space is only usable once.
 * 3. When front == rear, queue is full but technically, it's not.
 *    |  |  |  |  |  |
 *                f,R
 * Solution:
 * 1. Resetting Pointers
 * 2. Using circular queue (Downside, number of elements it can store is size - 1. Because q->first have to be empty)
 *
 */

template <typename T>
class Node
{
public:
    T data;
    Node* next;
};

template <typename T>
class Queue
{
private:
    Node<T>* first;
    Node<T>* rear;

public:
    Queue();
    ~Queue();
    bool IsEmpty();
    T Enqueue(T value);
    T Dequeue();
    void Display();
};

template <typename T>
Queue<T>::Queue()
{
    first = nullptr;
    rear = nullptr;
}

template <typename T>
Queue<T>::~Queue()
{
    while (first != rear + 1)
    {
        Node<T>* curr = first;
        first = first->next;
        delete curr;
    }
}

template <typename T>
bool Queue<T>::IsEmpty()
{
    return !(first && rear);
}

template <typename T>
T Queue<T>::Enqueue(T value)
{
    Node<T>* p = new Node<T>();

    if (!p)
    {
        cout << "Insufficient memory! Upgrade your tiny-puny RAM please :(";
        return -1;
    }

    p->data = value;
    p->next = nullptr;

    if (IsEmpty())
    {
        first = rear = p;
    }
    else
    {
        rear->next = p;
        rear = p;
    }

    return p->data;
}

template <typename T>
T Queue<T>::Dequeue()
{
    T x = -1;

    if (IsEmpty())
    {
        return x;
    }

    if (first == rear)
    {
        x = rear->data;
        first = nullptr;
        rear = nullptr;
        return x;
    }

    Node<T>* r = first;
    first = first->next;
    r->next = nullptr;
    x = r->data;
    delete r;

    return x;
}

template <typename T>
void Queue<T>::Display()
{
    Node<T>* curr = first;
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

// template <typename T>
// void Display(struct Queue<T>* q)
// {
//     struct Node<T>* curr = q->first;
//     while (curr)
//     {
//         printf("%d ", curr->data);
//         curr = curr->next;
//     }
// }

int main()
{
    Queue<int>* q = new Queue<int>();

    cout << endl;
    cout << "Added new item to queue: " << q->Enqueue(1) << endl;
    cout << "Added new item to queue: " << q->Enqueue(2) << endl;
    cout << "Added new item to queue: " << q->Enqueue(3) << endl;
    cout << "Remove item from front of queue: " << q->Dequeue() << endl;
    cout << "Display: ";
    q->Display();

    delete q;


    return 0;
}
