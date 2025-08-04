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

void Unique()
{
    struct Node* curr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* next = (struct Node*)malloc(sizeof(struct Node));
    curr = first;
    next = first->next;

    while (next != nullptr)
    {
        if (curr->data != next->data)
        {
            curr = next;
            next = next->next;
        }
        else
        {
            curr->next = next->next;
            free(next);
            next = curr->next;
        }
    }
}


int main()
{
    int arr[] = {1, 2, 2, 5, 5, 5, 9, 9, 9, 9};
    first = Create(arr, 8);

    printf("\n----- Display -----");
    printf("\nDisplay: ");
    Display();

    printf("\n----- Unique -----");
    Unique();
    printf("\nUnique: ");
    Display();


    return 0;
}
