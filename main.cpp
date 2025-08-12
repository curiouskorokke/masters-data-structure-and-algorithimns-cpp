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

struct Queue
{
    int size;
    int first;
    int rear;
    int* Q;
};

struct Queue* Create(struct Queue* q, int size)
{
    q = (struct Queue*)malloc(sizeof(struct Queue));
    q->size = size;
    q->first = q->rear = -1;
    q->Q = (int*)malloc(size * sizeof(int));

    return q;
}

bool IsEmpty(struct Queue* q)
{
    return q->first == q->rear;
}

bool IsFull(struct Queue* q)
{
    return q->rear == q->size - 1;
}

int Enqueue(struct Queue* q, int value)
{
    if (IsFull(q))
    {
        printf("\nUh-oh. Think again! Queue is full.");
        return -1;
    }

    q->Q[++q->rear] = value;
    return value;
}

int Dequeue(struct Queue* q)
{
    int x = -1;

    if (IsEmpty(q))
    {
        printf("\nMan, queue is empty. Add some spice in it first.");
    }
    else
    {
        x = q->Q[++q->first];
    }

    return x;
}

void Display(struct Queue* q)
{
    int i = q->first + 1;
    while (i <= q->rear)
    {
        printf("%d ", q->Q[i]);
        i++;
    }
}


int main()
{
    struct Queue* q;

    q = Create(q, 3);
    printf("New item added to queue: %d", Enqueue(q, 9));
    printf("\nNew item added to queue: %d", Enqueue(q, 8));
    // printf("\nNew item added to queue: %d", Enqueue(q, 7));
    printf("\nDisplay: ");
    Display(q);
    // printf("\nItem removed from front of queue: %d", Dequeue(q));
    // printf("\nItem removed from front of queue: %d", Dequeue(q));

    delete q;

    return 0;
}
