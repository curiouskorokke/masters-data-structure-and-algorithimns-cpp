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


void Append(struct Array* arr, int value)
{
    if ((*arr).length < (*arr).size)
    {
        (*arr).A[(*arr).length] = value;
        (*arr).length++;
    }
    else
    {
        cout << "Array size is at it's capacity." << endl;
    }
}


void Insert(struct Array* arr, int value, int index)

{
    if (arr->length == arr->size)
    {
        cout << "Array size is at it's capacity." << endl;
        return;
    }

    if (index > arr->length && index < 0)
    {
        cout << "Invalid index." << endl;
        return;
    }


    for (int i = (*arr).length - 1; i >= 0; i--)
    {
        (*arr).A[i + 1] = (*arr).A[i];

        if (i == index)
        {
            (*arr).A[index] = value;
            break;
        }
    }

    (*arr).length++;
}

int Delete(struct Array* arr, int index)
{
    int x = (*arr).A[index];
    if (index < (*arr).length - 1 && index >= 0)
    {
        for (int i = index; i < (*arr).length; i++)
        {
            (*arr).A[i] = (*arr).A[i + 1];
        }

        (*arr).length--;
        return x;

    }
    else
    {
        cout << "Invalid index." << endl;
        return -1;
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

    cout << "----- Display -----" << endl;
    Display(arr);

    cout << "----- Append 10 -----" << endl;
    Append(&arr, 10);
    Display(arr);

    cout << "----- Insert value: 23 at index: 3 -----" << endl;
    Insert(&arr, 23, 0);
    Display(arr);

    cout << "----- Delete at index: 3 -----" << endl;
    cout<<Delete(&arr, 3)<<" is deleted."<<endl;
    Display(arr);
}
