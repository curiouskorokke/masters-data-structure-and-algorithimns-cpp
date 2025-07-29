#include<iostream>

using namespace std;

int main()
{
    // Update size of array P
    int* p;
    p = new int[5];
    int* q;
    q = new int[10];


    // Filling up array
    for (int i = 0; i < 5; i++)
    {
        p[i] = i;
    }

    for (int i = 0; i < 10; i++)
    {
        q[i] = i + 10;
    }

    delete []p;
    p = nullptr;
    p = new int(10);

    for (int i = 0; i < 10; i++)
    {
        p[i] = q[i];
        cout<< p + i <<": "<< p[i]<<endl;
    }

    cout<<"----------"<<endl;

    delete []q;
    q = nullptr;

    for (int i = 0; i < 10; i++)
    {
        cout <<p + i<<": " <<p[i] << endl;
    }

    delete []p;
    p = nullptr;


    return 0;
}
