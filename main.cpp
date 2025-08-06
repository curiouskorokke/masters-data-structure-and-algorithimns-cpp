#include<iostream>
#include<cmath>
using namespace std;

/*
 * Array Cons
 * 1. Fixed Size
 *
 * Thus, Linked List!
 * Properties
 * 1. Self-Referential
 *
 */

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
}* first = nullptr;


void Create(const int arr[], const int n)
{
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->prev = nullptr;
    p->data = arr[0];
    p->next = nullptr;
    first = p;

    for (int i = 1; i < n; i++)
    {
        struct Node* q = (struct Node*)malloc(sizeof(struct Node));
        q->prev = p;
        q->data = arr[i];
        q->next = nullptr;
        p->next = q;
        p = p->next;
    }
}

void Display()
{
    struct Node* p;
    p = first;

    while (p != nullptr)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void RDisplay(struct Node* p)
{
    if (p == nullptr)
    {
        return;
    }

    printf("%d ", p->data);
    RDisplay(p->next);
}

int main()
{
    int arr[] = {1, 2, 5, 9};
    Create(arr, 4);

    printf("----- Display -----");
    printf("\nDisplay: ");
    Display();
    printf("\nRDisplay: ");
    RDisplay(first);

    return 0;
}
