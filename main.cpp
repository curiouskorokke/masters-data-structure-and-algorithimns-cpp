#include<iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
}* top = nullptr;


/*
 * There's no need for create since linked list don't follow a fixed size
 * declaration like array.
 */
void Push(int x)
{
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));

    if (t == nullptr)
    {
        printf("Out of memory!");
        return;
    }

    t->data = x;
    t->next = top;
    top = t;
}

int Pop()
{
    int x = -1;

    if (top == nullptr)
    {
        printf("\nOy! It's an empty stack mate!");
        return x;
    }

    struct Node* p;
    p = top;
    x = top->data;
    top = top->next;

    free(p);

    return x;
}

void Display()
{
    struct Node* p;
    p = top;

    while (p != nullptr)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int IsEmpty()
{
    return top == nullptr;
}

int IsFull()
{
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));

    if (t == nullptr)
    {
        return 1;
    }

    free(t);
    return 0;
}

int Peek(int pos)
{
    int x = -1;
    struct Node* p;
    p = top;

    for (int i = 0; p != nullptr && i < pos; i++)
    {
        p = p->next;
    }

    if (p != nullptr) x = p->data;

    return x;
}

int StackTop()
{
    if (top == nullptr)
    {
        return -1;
    }

    return top->data;
}

int main()
{
    printf("\n----- Time to push! -----");
    Push(1);
    Push(2);
    Push(3);
    Push(4);
    Push(5);
    printf("\nDisplay: ");
    Display();

    printf("\n----- Time to pop, pop! -----");
    printf("\nPop!: %d", Pop());
    printf("\nPop!: %d", Pop());
    printf("\nPop!: %d", Pop());
    printf("\nDisplay: ");
    Display();

    printf("\n----- Time to take a peek! -----");
    printf("\nPeek: %d", Peek(1));

    printf("\n----- IsEmpty -----");
    printf("\nIsEmpty: %d", IsEmpty());

    printf("\n----- Stack Top -----");
    printf("\nStack Top: %d", StackTop());

    printf("\nPop!: %d", Pop());
    printf("\nPop!: %d", Pop());
    printf("\n----- IsEmpty -----");
    printf("\nIsEmpty: %d", IsEmpty());

    printf("\n----- IsFull -----");
    printf("\nIsFull: %d", IsFull());


    return 0;
}
