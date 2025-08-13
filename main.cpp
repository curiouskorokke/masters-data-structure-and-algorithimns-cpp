#include<iostream>

using namespace std;

// Double Queue Queue - DEQueue using array
template <typename T>
class Queue
{
private:
    int size;
    int first;
    int last;
    int* Q;

public:
    explicit Queue(int length = 5);
    ~Queue();
    bool IsEmpty();
    bool IsFull(bool fromRear = 0);
    T Enqueue(T value, bool fromRear = 0);
    T Dequeue(bool fromRear = 0);
    void Display();
};

template <typename T>
Queue<T>::Queue(int length)
{
    size = length;
    first = -1;
    last = -1;
    Q = new int[size];
}

template <typename T>
Queue<T>::~Queue()
{
    delete[] Q;
}

template <typename T>
bool Queue<T>::IsEmpty()
{
    return first == last;
}

template <typename T>
bool Queue<T>::IsFull(bool fromRear)
{
    return fromRear ? last == size - 1 : first <= 0;
}

template <typename T>
T Queue<T>::Enqueue(T value, bool fromRear)
{
    T x = -1;

    if (IsFull(fromRear))
    {
        string isRearStr = fromRear ? "rear." : "front.";
        cout << "Oi! Try to fill up from other end mate! It's full on the " << isRearStr << endl;
        return x;
    }

    fromRear ? Q[++last] = value : Q[first--] = value;

    x = value;

    return x;
}

template <typename T>
T Queue<T>::Dequeue(bool fromRear)
{
    T x = -1;

    if (IsEmpty())
    {
        cout << "Oi! Shit is already empty mate. Get your shit together." << endl;
        return x;
    }

    if (fromRear)
    {
        x = Q[last--];
    }
    else
    {
        x = Q[++first];
    }

    return x;
}

template <typename T>
void Queue<T>::Display()
{
    if (IsEmpty())
    {
        cout<<"Uhm bro. It's empty. What are you yapping for me to show?"<<endl;
        return;
    }

    cout<<"Display: ";
    for (int i = first == -1 ? 0 : first + 1; i <= last; i++)
    {
        cout << Q[i] << " ";
    }
}


int main()
{
    Queue<int>* q = new Queue<int>();

    cout << "Added new item to queue: " << q->Enqueue(1, true) << endl;
    cout << "Added new item to queue: " << q->Enqueue(2, true) << endl;
    cout << "Added new item to queue: " << q->Enqueue(3, true) << endl;
    cout << "Added new item to queue: " << q->Enqueue(4, true) << endl;
    cout << "Added new item to queue: " << q->Enqueue(5, true) << endl;
    q->Display();
    cout<<endl;

    cout << "Remove item from front of queue: " << q->Dequeue() << endl;
    cout << "Remove item from front of queue: " << q->Dequeue() << endl;
    cout << "Remove item from front of queue: " << q->Dequeue(true) << endl;
    cout << "Remove item from front of queue: " << q->Dequeue(true) << endl;
    cout << "Remove item from front of queue: " << q->Dequeue(true) << endl;
    q->Display();
    cout<<endl;


    delete q;

    return 0;
}
