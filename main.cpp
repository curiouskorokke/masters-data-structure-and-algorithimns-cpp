#include<iostream>

using namespace std;

/*
 * Array (Abstract Datatype - ADT)
 */

struct Array
{
    int* A;
    int size;
    int length;
};

void Display(Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
}

int main()
{
    struct Array arr;

    cout << "Enter array size:" << endl;
    cin >> arr.size;

    arr.A = new int[arr.size];

    cout << "Enter array length:" << endl;
    cin >> arr.length;

    for (int i = 0; i < arr.length; i++)
    {
        cout << "Enter value of element: ";
        cout << endl;
        cin >> arr.A[i];
    }

    Display(arr);
}
