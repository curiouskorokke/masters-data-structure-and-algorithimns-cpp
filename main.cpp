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

struct Node* Search(int value)
{
    struct Node* curr = (struct Node*)malloc(sizeof(struct Node));
    curr = first;
    while (curr != nullptr)
    {
        if (curr->data == value)
        {
            return curr;
        }

        curr = curr->next;
    }

    return curr;
} // Space: O(1), Time: O(n)

struct Node* RecursiveSearch(struct Node* node, int value)
{
    if (node == nullptr)
    {
        return node;
    }

    if (node->data == value)
    {
        return node;
    }

    return RecursiveSearch(node->next, value);
} // Space: O(n), Time: O(n)

/*
 * Move found node to header
 */
struct Node* CacheSearch(int value)
{
    struct Node* curr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* prev = (struct Node*)malloc(sizeof(struct Node));
    curr = first;


    while (curr != nullptr)
    {
        if (curr->data == value)
        {
            prev->next = curr->next;

            if (curr != first)
            {
                curr->next = first;
            }

            break;
        }
        prev = curr;
        curr = curr->next;
    }

    return curr;
}

void Insert(int pos, int value)
{
    /*
     * Array:        |  2  |  4  |  8  |  12  |  7  |  3  |
     *               ^     ^     ^     ^      ^     ^     ^
     * Index:        0  ^  1  ^  2  ^  3   ^  4  ^  5  ^  6
     * Position:        1     2     3      4     5     6
     *
     * Two Cases:
     * 1. Insertion before first
     * 2. Insertion after position
     */
    struct Node* curr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = nullptr;
    curr = first;

    if (pos == 0)
    {
        newNode->next = curr;
        first = newNode;
        return;
    }

    for (int i = 1; i < pos; i++)
    {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}

void InsertSorted(int value)
{
    struct Node* prev;
    struct Node* curr;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    curr = first;

    if (first == nullptr)
    {
        first = newNode;
    }
    else
    {
        while (curr && curr->data < value)
        {
            prev = curr;
            curr = curr->next;
        }

        if (value < first->data)
        {
            newNode->next = curr;
            first = newNode;
        }
        else
        {
            newNode->data = value;
            newNode->next = nullptr;
            prev->next = newNode;
            newNode->next = curr;
        }
    }
}

void Delete(int pos)
{
    struct Node* curr;
    struct Node* prev;
    curr = first;
    int currPos = 1;

    if (pos == 1)
    {
        first = curr->next;
    } else
    {
        while (curr != nullptr)
        {
            if (currPos == pos)
            {
                prev->next = curr->next;
                delete curr;
                break; 
            }

            prev = curr;
            curr = curr->next;
            currPos++;
        }
    }
}

void DeleteSorted()
{
}

int main()
{
    // int arr[] = {1, 4, 20, 2, 8};
    int arr[] = {1, 2, 4, 8, 20};
    printf("Array Created {1, 2, 4, 8, 20}...");
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

    printf("\n----- Search -----");
    printf("\nSearch: %d", Search(20)->data);
    printf("\nRecursive Search: %d", RecursiveSearch(first, 2)->data);
    printf("\nCache: ");
    first = CacheSearch(1);
    Display();

    printf("\n----- Insert -----");
    printf("\nInsert: ");
    Insert(5, 30);
    Display();
    printf("\nInsert in Sorted List: ");
    InsertSorted(0);
    InsertSorted(3);
    InsertSorted(100);
    Display();

    printf("\n ----- Delete -----");
    printf("\n Delete mid node (3): ");
    Delete(3);
    Display();
    printf("\n Delete start node (1): ");
    Delete(1);
    Display();
    printf("\n Delete end node (100): ");
    Delete(7);
    Display();

    return 0;
}
