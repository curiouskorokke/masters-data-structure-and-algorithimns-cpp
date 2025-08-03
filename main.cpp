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
    printf("\n");
}

void RecursiveDisplay(struct Node* node)
{
    if (node != nullptr)
    {
        printf("%d ", node->data);
        RecursiveDisplay(node->next);
    }
}

void ReverseRecursiveDisplay(struct Node* node)
{
    if (node != nullptr)
    {
        ReverseRecursiveDisplay(node->next);
        printf("%d ", node->data);
    }
}

int main()
{
    int arr[] = {1, 4, 20, 2, 8};
    first = Create(arr, 5);
    printf("Display: ");
    Display();

    printf("Recursive Display: ");
    RecursiveDisplay(first);

    printf("\nReverse Recursive Display: ");
    ReverseRecursiveDisplay(first);


    return 0;
}
