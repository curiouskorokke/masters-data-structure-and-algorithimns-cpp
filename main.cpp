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

void Display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
    cout << endl;
}

void Append(struct Array *arr, int value)
{
    if ((*arr).length < (*arr).size)
    {
        (*arr).A[(*arr).length] = value;
    }

    (*arr).length++;
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

    cout << "----- Display -----" << endl;
    Display(arr);

    cout << "----- Append -----" << endl;
    Append(&arr, 10);
    Display(arr);
}
