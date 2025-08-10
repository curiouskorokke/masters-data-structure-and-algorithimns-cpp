#include<iostream>

using namespace std;

class Node
{
public:
    char data;
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

    void Push(char x)
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

    char StackTop()
    {
        if (top == nullptr)
        {
            return -1;
        }

        return top->data;
    };
};

/*
 * Infix, prefix & postfix
 *
 * Rules:
 * 1. Equation must be fully parenthesis
 *
 * | Symbol | Precedence |
 * | + , -  |     1      |
 * | * , \  |     2      |
 * | ( , )  |     3      |
 *
 * Infix to prefix and postfix conversion
 * Equation: a + b + c * d
 * Prefix: a + b + [*cd] -> [+ab] + [*cd] -> ++ab*cd
 * Postfix: a + b + [cd*] -> [ab+] + [cd*] -> ab+cd*+
 *
 * Equation: (a + b) * (c - d);
 * Prefix: (+ab) * (-cd) -> *+ab-cd
 * Postfix:(ab+) * (cd-) -> ab+cd-*
 *
 * ----------------------------------
 *
 * Associativity - How to handle operators of same precedence
 *
 * Symbol           | Precedence | Associativity
 * + , -            |     1      |    L -> R
 * * , /            |     2      |    L -> R
 *   ^              |     3      |    R -> L
 * =, +=, -=, unary |     4      |    R -> L
 *  ()              |     5      |    L -> R
 *
 * Equation: a + b - c - d
 * Postfix (L->R): (((a + b) - c) - d) -> ab+c-d-
 * Why not (R-L): (a+(b-(c-d))) -> Then the equation becomes a + b - c + d
 *
 * Equation: a = b = c = 5
 * Postfix (R->L): (a=(b=(c=5)) -> abc5===
 *
 * Equation: a ^ b ^ c
 * Postfix (R->L): (a ^ (b ^ c)) -> a ^ bc^ -> abc^^
 *
 * Equation: - a + b * log n!
 * Postfix: - a + b * log n! -> - a + b * n!log -> a- + b * n!log -> a- + bn!log* -> a-bn!log*+
 *
 * Code Logic:
 * Loop through equation, if it's an operand add to postfix variable
 * If it's an operator, check the top stack if operator is lower than or equal
 * to the top stack operator.
 * 1. If it is, pop top stack until current operator is more than or stack is empty then add operator to stack
 * 2. If it isn't, add to stack
 *
 * If reached end of equation, pop remaining operator from stack into postfix variable
 *
 * Example using Method 1
 * Equation: a + b * c - d / e
 *
 * |    symbol    |   stack   |   postfix   |
 * |      a       |    []     |      a      |
 * |      +       |    [+]    |      a      |
 * |      b       |    [+]    |      ab     |
 * |      *       |   [*,+]   |      ab     |
 * |      c       |   [*,+]   |     abc     |
 * |      -       |    [-]    |     abc*+   |
 * |      d       |    [-]    |    abc*+d   |
 * |      /       |   [/,-]   |    abc*+d   |
 * |      e       |   [/,-]   |   abc*+de   |
 *
 * Final outcome: abc*+de/-
 *
*  Example using Method 2
*  In this case, operand has a precedence of 3, * & / of 2 and * & - of 1
 * Equation: a + b * c - d / e
 *
 *
 * |    symbol    |   stack   |   postfix   |
 * |      a       |    [a]    |             |
 * |      +       |    [+]    |      a      |
 * |      b       |   [b, +]  |      a      |
 * |      *       |   [*, +]  |     ab      |
 * |      c       |  [c,*,+]  |     ab      |
 * |      -       |    [-]    |    abc*+    |
 * |      d       |   [d,-]   |    abc*+    |
 * |      /       |   [/,-]   |    abc*+d   |
 * |      e       |  [e,/,-]  |    abc*+d   |
 *
 * Final outcome: abc*+de/-
 */

bool IsOperand(char x)
{
    return x != '+' && x != '-' && x != '*' && x != '/';
}

int GetPrecedence(char operand)
{
    if (operand == '+' || operand == '-')
    {
        return 1;
    }

    if (operand == '*' || operand == '/')
    {
        return 2;
    }

    return 0;
}


// Method one.
char* InfixToPostfixConversion(char* infix)
{
    Stack* st = new Stack();
    char* postfix = new char[strlen(infix) + 1];
    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        char curr = infix[i];

        if (IsOperand(curr))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            int currPrecedence = GetPrecedence(curr);

            while (currPrecedence <= GetPrecedence(st->StackTop()))
            {
                postfix[j++] = st->Pop();
            }

            st->Push(curr);
            i++;
        }
    }

    while (!st->IsEmpty())
    {
        postfix[j++] = st->Pop();
    }

    postfix[j] = '\0';
    delete st;

    return postfix;
}


int main()
{
    char* infix = "a+b*c-d/e";

    cout << InfixToPostfixConversion(infix) << endl;
    return 0;
}
