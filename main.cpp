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

int Delete(int pos)
{
    int x;
    if (pos > 0 && pos <= Length())
    {
        struct Node* p;
        p = Head;

        if (pos == 1)
        {
            while (p->next != Head)
            {
                p = p->next;
            }

            struct Node* q;
            q = p->next;
            p->next = q->next;
            x = q->data;
            Head = q->next;

            if (p == q)
            {
                Head = nullptr;
            }
            delete q;
        }
        else
        {
            for (int i = 1; i < pos - 1; i++)
            {
                p = p->next;
            }
            struct Node* q;
            q = p->next;
            p->next = q->next;
            x = q->data;
            delete q;
        }
    }

    return x;
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

    printf("\n----- Delete -----");
    printf("\nDelete: %d", Delete(5));
    printf("\nDisplay: ");
    Display();


    return 0;
}
