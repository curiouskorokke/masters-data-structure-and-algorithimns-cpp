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
}* first = nullptr;


struct Node* Create(const int arr[], const int n)
{
    struct Node* curr;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = arr[0];
    first->next = nullptr;
    curr = first;

    for (int i = 1; i < n; i++)
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = nullptr;
        curr->next = newNode;
        curr = newNode;
    }

    return first;
}

void Display()
{
    struct Node* curr = (struct Node*)malloc(sizeof(struct Node));
    curr = first;

    while (curr != nullptr)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

// Using slider pointer
void Reverse()
{
    struct Node* r = nullptr;
    struct Node* q = nullptr;
    struct Node* p = first;

    while (p != nullptr)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void RecursionReverse(struct Node* q, struct Node* p)
{
    if (p != nullptr)
    {
        RecursionReverse(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}


int main()
{
    int arr[] = {1, 2, 5, 9};
    first = Create(arr, 4);

    printf("\n----- Display -----");
    printf("\nDisplay: ");
    Display();

    printf("\n----- Reverse -----");
    Reverse();
    // RecursionReverse(first, first->next);
    printf("\nReverse: ");
    Display();


    return 0;
}
