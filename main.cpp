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

bool IsLoop()
{
    struct Node* p;
    struct Node* q;
    p = q = Head;

    int flag = 0;

    if (Head == nullptr)
    {
        return true;
    }

    while (p && q && p != q || flag == 0)
    {
        flag = 1;
        p = p->next;
        q = q->next->next;
    }

    if (p == q)
    {
        return true;
    }

    return false;
}

bool RIsLoop(struct Node* p, struct Node* q)
{
    if (p && q && p == q)
    {
        return true;
    }

    if (!p || !q)
    {
        return false;
    }

    return RIsLoop(p->next, q->next->next);
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

    printf("\n----- IsLoop -----");
    printf("\nIsLoop: %d", IsLoop());
    printf("\nRIsLoop: %d", RIsLoop(Head, Head));

    return 0;
}
