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

bool IsSorted()
{
    struct Node* curr;
    curr = first;

    while (curr != nullptr)
    {
        int nextData = curr->next == nullptr ? curr->data + 1 : curr->next->data;
        if (curr->data > nextData)
        {
            return false;
        }

        curr = curr->next;
    }

    return true;
}


int main()
{
    int arr[] = {1, 4, 20, 2, 8};
    int sortedArr[] = {1, 2, 4, 8, 20};
    printf("Array Created {1, 2, 4, 8, 20}...");
    first = Create(sortedArr, 5);

    printf("\n----- Display -----");
    printf("\nDisplay: ");
    Display();

    printf("\n Is above sorted?: %d", IsSorted());


    return 0;
}
