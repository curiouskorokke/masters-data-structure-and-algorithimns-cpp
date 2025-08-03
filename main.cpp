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

int Count()
{
    struct Node* curr = (struct Node*)malloc(sizeof(struct Node));
    curr = first;
    int count = 0; // Space: O(1)

    while (curr != nullptr) // Time: O(n)
    {
        curr = curr->next;
        count++;
    }

    return count;
} // Time: O(n), Space: O(1)

int RecursiveCount(struct Node* node)
{
    if (node == nullptr)
    {
        return 0;
    }

    return RecursiveCount(node->next) + 1;
} // Time: O(n), Space: O(n)

int Sum()
{
    struct Node* curr = (struct Node*)malloc(sizeof(struct Node));
    curr = first;
    int sum = 0; // Space: O(1)

    while (curr != nullptr) // Time: O(n)
    {
        sum += curr->data;
        curr = curr->next;
    }

    return sum;
} // Space O(1), Time O(n)

int RecursiveSum(struct Node* node)
{
    if (node == nullptr)
    {
        return 0;
    }

    return RecursiveSum(node->next) + node->data; // Space: O(n), Time: O(n)
} // Space: O(n), Time: O(n)


int Max()
{
    struct Node* curr = (struct Node*)malloc(sizeof(struct Node));
    curr = first;
    int max = INT32_MIN;

    while (curr != nullptr)
    {
        if (curr->data > max)
        {
            max = curr->data;
        }
        curr = curr->next;
    }

    return max;
} // Space: O(1), Time: O(n)

int RecursiveMax(struct Node* node)
{
    int max = INT32_MIN;

    if (node == nullptr)
    {
        return max;
    }

    max = RecursiveMax(node->next);

    return max > node->data ? max : node->data;
} // Space: O(n) , Time: O(n)

int main()
{
    int arr[] = {1, 4, 20, 2, 8};
    printf("Array Created {1, 4, 20, 2, 8}...");
    first = Create(arr, 5);

    printf("\n----- Display -----");
    printf("\nDisplay: ");
    Display();

    printf("\nRecursive Display: ");
    RecursiveDisplay(first);

    printf("\nReverse Recursive Display: ");
    ReverseRecursiveDisplay(first);

    printf("\n----- Count -----");
    printf("\nCount: %d", Count());
    printf("\nRecursive Count: %d", RecursiveCount(first));

    printf("\n----- Sum -----");
    printf("\nSum: %d", Sum());
    printf("\nRecursive Sum: %d", RecursiveSum(first));

    printf("\n----- Max -----");
    printf("\nMax: %d", Max());
    printf("\nRecursive Max: %d", RecursiveMax(first));

    return 0;
}
