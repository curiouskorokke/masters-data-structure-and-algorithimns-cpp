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
} * Head;


void Create(const int arr[], const int n)
{
    struct Node* p;
    p = nullptr;
    Head = p;

    if (n != 0)
    {
        for (int i = 1; i < n + 1; i++)
        {
            struct Node* t = (struct Node*)malloc(sizeof(struct Node));
            t->data = arr[i - 1];
            t->next = nullptr;

            if (i == 1)
            {
                p = t;
                p->next = t;
                Head = p;
            }
            else
            {
                p->next = t;
                p = p->next;
            }
        }

        p->next = Head;
    }
}


void Display()
{
    if (Head == nullptr)
    {
        return;
    }

    struct Node* p = Head;

    int flag = 0;
    while (p != Head || flag == 0)
    {
        flag = 1;
        printf("%d ", p->data);
        p = p->next;
    }
}

void RDisplay(struct Node* p)
{
    static int flag = 0;
    if ((p != Head || flag == 0) && Head != nullptr)
    {
        flag = 1;
        printf("%d ", p->data);
        RDisplay(p->next);
    }
}

int Length()
{
    struct Node* p;

    p = Head;
    int len = 0;
    int flag = 0;
    while (p != Head || flag == 0)
    {
        flag = 1;
        len++;
        p = p->next;
    }

    return len;
}

/*
* There are two conditions to consider
* 1. Inserting at head
* 2. Inserting between
* 3. Empty linked list
*/
void Insert(int value, int pos = 0)
{
    struct Node* p = Head;
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = value;


    if (pos < 0 || pos > Length())
    {
        return;
    }

    if (pos == 0)
    {
        if (Head == nullptr)
        {
            Head = t;
            Head->next = Head;
        }
        else
        {
            t->next = Head;
            while (p->next != Head)
            {
                p = p->next;
            }
            p->next = t;
            Head = t;
        }
    }
    else
    {
        // Inserting in between

        t->next = nullptr;
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }

        t->next = p->next;
        p->next = t;
    }
}


int main()
{
    int arr[] = {1, 2, 5, 7, 9, 10, 14, 18};
    Create(arr, 8);
    printf("\n----- Display -----");
    printf("\nDisplay Loop: ");
    Display();
    printf("\nDisplay Recursive Loop: ");
    RDisplay(Head);

    printf("\n----- Length -----");
    printf("\nLength: %d", Length());;

    printf("\n----- Inserted -----");
    printf("\nInserted: ");
    Insert(4, 8);
    Display();


    return 0;
}
