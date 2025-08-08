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
            printf("\nOy! It's an empty stack mate!");
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

int main()
{
    Stack* stk = new Stack();
    cout << "----- Time to push! -----" << endl;;
    cout << "Push 1: " << endl;
    stk->Push(1);
    cout << "Push 2: " << endl;
    stk->Push(2);
    cout << "Push 3: " << endl;
    stk->Push(3);
    cout << "Push 4: " << endl;
    stk->Push(4);
    cout << "Push 5: " << endl;
    stk->Push(5);

    cout << "----- Time to pop! -----" << endl;
    cout << "Pop: " << stk->Pop() << endl;
    cout << "Pop: " << stk->Pop() << endl;

    cout << "---- Display -----" << endl;
    stk->Display();
    cout<<endl;

    cout << "---- IsEmpty -----" << endl;
    cout << "IsEmpty: " << stk->IsEmpty()<<endl;

    cout << "---- IsFull -----" << endl;
    cout << "IsFull: " << stk->IsFull()<<endl;

    cout << "---- Peek -----" << endl;
    cout << "Peek: " << stk->Peek(1)<<endl;

    cout << "---- StackTop -----" << endl;
    cout << "StackTop: " << stk->StackTop()<<endl;



    delete stk;
    return 0;
}
