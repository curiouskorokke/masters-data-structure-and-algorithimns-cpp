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
struct Node
{
    T data;
    Node* next;
};

template <typename T>
struct Queue
{
    Node<T>* first;
    Node<T>* rear;
};

template <typename T>
struct Queue<T>* Create(struct Queue<T>* q)
{
    q = (struct Queue<T>*)malloc(sizeof(struct Queue<T>));
    q->first = nullptr;
    q->rear = nullptr;

    return q;
}

template <typename T>
bool IsEmpty(struct Queue<T>* q)
{
    return !(q->first && q->rear);
}

template <typename T>
T Enqueue(struct Queue<T>* q, T value)
{
    struct Node<T>* p = (struct Node<T>*)malloc(sizeof(struct Node<T>));
    p->data = value;
    p->next = nullptr;

    if (IsEmpty(q))
    {
        q->first = q->rear = p;
    }
    else
    {
        q->rear->next = p;
        q->rear = p;
    }

    return p->data;
}

template <typename T>
T Dequeue(struct Queue<T>* q)
{
    T x = -1;

    if (IsEmpty(q))
    {
        return x;
    }

    if (q->first == q->rear)
    {
        x = q->rear->data;
        q->first = nullptr;
        q->rear = nullptr;
        return x;
    }

    struct Node<T>* r = q->first;
    q->first = q->first->next;
    r->next = nullptr;
    x = r->data;
    delete r;

    return x;
}

template <typename T>
void Display(struct Queue<T>* q)
{
    struct Node<T>* curr = q->first;
    while (curr)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

int main()
{
    struct Queue<int>* q;

    q = Create<int>(q);


    printf("\nAdded new item to queue: %d", Enqueue(q, 1));
    printf("\nAdded new item to queue: %d", Enqueue(q, 2));
    printf("\nAdded new item to queue: %d", Enqueue(q, 3));
    printf("\nRemove item from front of queue: %d", Dequeue(q));
    // printf("\nRemove item from front of queue: %d", Dequeue(q));
    // printf("\nRemove item from front of queue: %d", Dequeue(q));
    // printf("\nRemove item from front of queue: %d", Dequeue(q));
    printf("\nDisplay: ");
    Display(q);


    return 0;
}
