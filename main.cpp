#include<iostream>

using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node* next;
};

/*
 * There's no need for create method since linked list don't follow a fixed size
 * declaration like array.
 */
template <typename T>
class Stack
{
private:
    Node<T>* top;

public:
    Stack()
    {
        top = nullptr;
    }

    ~Stack()
    {
        delete top;
    }

    void Push(T x)
    {
        Node<T>* t = new Node<T>();

        if (t == nullptr)
        {
            printf("Out of memory!");
            return;
        }

        t->data = x;
        t->next = top;
        top = t;
    }

    T Pop()
    {
        int x = -1;

        if (top == nullptr)
        {
            return x;
        }

        struct Node<T>* p;
        p = top;
        x = top->data;
        top = top->next;

        free(p);

        return x;
    }

    void Display()
    {
        Node<T>* p;
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
        Node<T>* t = new Node<T>();

        if (t == nullptr)
        {
            return 1;
        }

        delete t;
        return 0;
    }

    T Peek(int pos)
    {
        int x = -1;
        Node<T>* p;
        p = top;

        for (int i = 0; p != nullptr && i < pos; i++)
        {
            p = p->next;
        }

        if (p != nullptr) x = p->data;

        return x;
    }

    T StackTop()
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
 * ---- The Why -----
 * Why converting to postfix is necessary ? Because
 * without it we would need to re-evaluate the equation
 * x times based on the precedence of an operator.
 *
 * For instance:
 * Imagine a string of equation given as such
 * a + (b + c) * d
 *
 * 1st iteration: b + c
 * 2nd iteration: (b + c) * d
 * 3rd iteration: a + (b + c) * d
 *
 * It takes three loops and various conditions to get the answer!
 *
 * But by converting the equation to postfix using stack
 * bc+d*a+
 *
 * Then using stack, to evaluate them
 * It only requires a single iteration!
 * Read below for more.
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
    return x != '+' && x != '-' && x != '*' && x != '/' && x != '^' && x != '(' && x != ')';
}

int GetPrecedence(int env, char operatorStr)
{
    int precedence = 8;
    // env - 0: Out of stack, 1: In of stack
    switch (operatorStr)
    {
    case '+':
    case '-':
        precedence = env ? 2 : 1;
        break;
    case '*':
    case '/':
        precedence = env ? 4 : 3;
        break;
    case '^':
        precedence = env ? 5 : 6;
        break;
    case '(':
        precedence = env ? 0 : 7;
        break;
    case ')':
        precedence = 0;
        break;
    }

    return precedence;
}


char* InfixToPostfixConversion(char* infix)
{
    Stack<char>* st = new Stack<char>();
    char* postfix = new char[strlen(infix) + 1];
    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        char curr = infix[i];

        int currOutOfStackPrecedence = GetPrecedence(0, curr);

        if (!st->IsEmpty())
        {
            while (st->StackTop() != -1 && currOutOfStackPrecedence <= GetPrecedence(1, st->StackTop()))
            {
                char stackTopCurr = st->Pop();
                if (stackTopCurr == '(' && curr == ')')
                {
                    break;
                }

                postfix[j++] = stackTopCurr;
            }
        }

        if (curr != ')')
        {
            st->Push(curr);
        }
        i++;
    }

    while (!st->IsEmpty())
    {
        postfix[j++] = st->Pop();
    }

    postfix[j] = '\0';
    delete st;

    return postfix;
}

/*
 * After converting to postfix, it's time to EVALUATE!
 * abc*+de/-
 *
 */

int PostfixResult(char* postfix)
{
    Stack<int>* st = new Stack<int>();
    int result;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        const char curr = postfix[i];

        if (IsOperand(curr))
        {
            st->Push(curr - '0');
        }
        else
        {
            const int operand2 = st->Pop();
            const int operand1 = st->Pop();

            switch (curr)
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            case '^':
                result = operand1;
                int j = 0;
                while (j<operand2 - 1)
                {
                    result *= operand1;
                    j++;
                }



            }

            st->Push(result);
        }
    }

    return st->Pop();
}


int main()
{
    char* infix = "4*3-(6/3)^3";
    char* postfix = InfixToPostfixConversion(infix);
    int result = PostfixResult(postfix);
    cout << "Postfix: "<<postfix<<endl;
    cout<< "Result: "<<result<<endl;
    return 0;


}
