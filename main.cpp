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

void Concatenate(struct Node* target, struct Node* value)
{
    struct Node* curr = target;

    while (curr->next != nullptr)
    {
        curr = curr->next;
    }

    curr->next = value;
    value = nullptr;

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

    printf("\n----- Concatenate -----");
    printf("\nConcatenate: ");
    Concatenate(first, second);
    Display(first);


    return 0;
}
