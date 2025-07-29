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
    for (int i = 0; i < arr.length; i++) // O(n)
    {
        cout << arr.A[i] << " "; // O(1)
    }
    cout << endl;
} // Time Complexity: n + 1 = O(n)

void Append(struct Array* arr, int value)
{
    if ((*arr).length < (*arr).size) // O(1)
    {
        (*arr).A[(*arr).length] = value; // O(1)
        (*arr).length++; // O(1)
    }
    else
    {
        cout << "Array size is at it's capacity." << endl;
    }
} // Time Complexity: O(1)

void Insert(struct Array* arr, int value, int index)

{
    if (arr->length == arr->size) // O(1)
    {
        cout << "Array size is at it's capacity." << endl;
        return;
    }

    if (index > arr->length && index < 0) // O(1)
    {
        cout << "Invalid index." << endl;
        return;
    }


    for (int i = (*arr).length - 1; i >= 0; i--) // Best: O(1), Worst: O(n)
    {
        (*arr).A[i + 1] = (*arr).A[i]; // O(1)

        if (i == index) // O(1)
        {
            (*arr).A[index] = value; // O(1)
            break;
        }
    }

    (*arr).length++; // O(1)
} // Time Complexity: O(n +5) = O(n)

int Delete(struct Array* arr, int index)
{
    int x = (*arr).A[index]; // O(1)
    if (index < (*arr).length - 1 && index >= 0) // O(1)
    {
        for (int i = index; i < (*arr).length; i++) // Best: O(1), Worst: O(n)
        {
            (*arr).A[i] = (*arr).A[i + 1]; // O(1)
        }

        (*arr).length--; // O(1)
        return x;
    }
    else
    {
        cout << "Invalid index." << endl;
        return -1;
    }
} // Time Complexity: O(n + 4) = O(n)

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

    cout << "----- Append 10 -----" << endl;
    Append(&arr, 10);
    Display(arr);

    cout << "----- Insert value: 23 at index: 3 -----" << endl;
    Insert(&arr, 23, 0);
    Display(arr);

    cout << "----- Delete at index: 3 -----" << endl;
    cout << Delete(&arr, 3) << " is deleted." << endl;
    Display(arr);
}
