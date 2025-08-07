#include<iostream>

using namespace std;

struct Stack
{
    int* arr;
    int size;
    int top;
}* stArr = nullptr;

void Create()
{
    stArr = (struct Stack*)malloc(sizeof(struct Stack));
    printf("Enter size of stack: ");
    scanf("%d", &stArr->size);
    stArr->arr = (int*)malloc(stArr->size * sizeof(int));
    stArr->top = -1;
}

void Display()
{
    for (int i = 0; i <= stArr->top; i++)
        printf("%d ", stArr->arr[i]);

    printf("\n");
}

void Push(int x)
{
    if (stArr->top == stArr->size - 1)
    {
        printf("\nStack size overflow.");
        return;
    }

    stArr->arr[stArr->top + 1] = x;
    stArr->top++;
}

int Pop()
{

    int x = -1;
    if (x == stArr->top)
    {
        printf("Stack is underflow.");
        return x;
    }

    x = stArr->arr[stArr->top--];
    return x;

}

bool IsEmpty()
{
    if (stArr->top == -1)
    {
        return true;
    }

    return false;
}

bool IsFull()
{
    if (stArr->top == stArr->size - 1)
    {
        return true;
    }

    return false;
}

int Peek(int index)
{
    if (index > 0 && index < stArr->size)
    {
        return stArr->arr[index];
    }

    return index;
}

int main()
{
    Create();

    printf("----- Display -----\n");
    printf("Display: ");
    Display();

    printf("----- Push -----\n");
    Push(4);
    Push(10);
    Push(14);
    Push(18);
    Push(22);
    printf("Push: ");
    Display();

    printf("\n----- Pop -----");
    printf("\nPop: %d", Pop());

    printf("\n----- IsEmpty -----");
    printf("\nIsEmpty: %d", IsEmpty());

    printf("\n----- IsFull -----");
    printf("\nIsFull: %d", IsFull());

    printf("\n----- Peak at 3 -----");
    printf("\nPeak: %d", Peek(3));


    return 0;
}
