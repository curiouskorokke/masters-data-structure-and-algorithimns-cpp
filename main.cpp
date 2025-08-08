#include<iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

/*
 * There's no need for create method since linked list don't follow a fixed size
 * declaration like array.
 */
class Stack
{
private:
    Node* top;

public:
    Stack()
    {
        top = nullptr;
    }

    ~Stack()
    {
        delete top;
    }

    void Push(int x)
    {
        Node* t = new Node();

        if (t == nullptr)
        {
            printf("Out of memory!");
            return;
        }

        t->data = x;
        t->next = top;
        top = t;
    }

    int Pop()
    {
        int x = -1;

        if (top == nullptr)
        {
            return x;
        }

        struct Node* p;
        p = top;
        x = top->data;
        top = top->next;

        free(p);

        return x;
    }

    void Display()
    {
        Node* p;
        p = top;

        while (p != nullptr)
        {
            printf("%d ", p->data);
            p = p->next;
        }
    }

    bool IsEmpty()
    {
        return top == nullptr;
    }

    bool IsFull()
    {
        Node* t = new Node();

        if (t == nullptr)
        {
            return 1;
        }

        delete t;
        return 0;
    }

    int Peek(int pos)
    {
        int x = -1;
        Node* p;
        p = top;

        for (int i = 0; p != nullptr && i < pos; i++)
        {
            p = p->next;
        }

        if (p != nullptr) x = p->data;

        return x;
    }

    int StackTop()
    {
        if (top == nullptr)
        {
            return -1;
        }

        return top->data;
    };
};

bool IsParenthesisBalance(char* str)
{
    Stack* stk = new Stack();

    bool match = true;
    for (int i = 0; str[i] != '\0'; i++)
    {
        int curr = str[i];

        if (curr == 40 || curr == 91 || curr == 123)
        {
            stk->Push(curr);
            continue;
        }

        if (curr == 41 || curr == 93 || curr == 125)
        {

            int latest = stk->Pop();

            if ((latest == 40 && latest == curr - 1) || ((latest == 91 || latest == 123) && latest == curr - 2))
            {
                continue;
            }

            match = false;
            break;
        }
    }

    if (!stk->IsEmpty())
    {
        match = false;
    }

    delete stk;

    return match;
}

int main()
{
    char str[] = "({[{}]}{})";

    cout << "Parenthesis balance: " << IsParenthesisBalance(str) << endl;


    return 0;
}
