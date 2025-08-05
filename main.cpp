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
};


struct Node* Create(const int arr[], const int n)
{
    struct Node* first = (struct Node*)malloc(sizeof(struct Node));
    first->data = arr[0];
    first->next = nullptr;

    struct Node* curr;
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

void Display(struct Node* node)
{
    struct Node* curr = node;

    while (curr != nullptr)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

void Merging(struct Node* first, struct Node* second)
{
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    third == nullptr;

    while (first && second)
    {
        if (first->data < second->data)
        {
            third->next = first;
            first = first->next;
        }
        else
        {
            third->next = second;
            second = second->next;
        }
        third = third->next;
        third->next = nullptr;
    }

    if (first != nullptr)
    {
        third->next = first;
    }

    if (second != nullptr)
    {
        third->next = second;
    }
}

int main()
{
    int arr[] = {1, 2, 5, 9};
    int arr2[] = {3, 4, 6, 8};
    struct Node* first = Create(arr, 4);
    struct Node* second = Create(arr2, 4);
    printf("\n----- Display -----");
    printf("\nDisplay: ");
    Display(first);
    printf("\nDisplay: ");
    Display(second);

    printf("\n----- Merging -----");
    printf("\nMerging: ");
    Merging(first, second);
    Display(first);

    return 0;
}
