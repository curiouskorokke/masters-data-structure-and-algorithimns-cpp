#include<iostream>
using namespace std;

template <class T>
class Arithmetic
{
private:
    T a;
    T b;

public:
    Arithmetic(T a, T b)
    {
        this->a = a;
        this->b = b;
    }
    T add()
    {
        return a + b;
    }
    T subtract()
    {
        return a - b;
    }
};

int main()
{
    Arithmetic a(1,2);

    cout<<"Add: "<<a.add()<<endl;
    cout<<"Subtract: "<<a.subtract()<<endl;


    return 0;
}
