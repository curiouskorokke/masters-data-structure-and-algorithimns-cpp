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

void Swap(struct Array* arr, int targetIndex, int index)
{
    int temp;

    temp = arr->A[targetIndex];
    arr->A[targetIndex] = arr->A[index];
    arr->A[index] = temp;
}

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

int LinearSearch(struct Array* arr, int value)
{
    for (int i = 0; i < arr->length; i++) // Worst: O(n), Best O(1)
    {
        if (arr->A[i] == value) // O(1)
        {
            // There are generally two ways to improve the next search
            // 1. Transportation
            // Swap(arr, i-1, i);
            // 2. Move to Head
            Swap(arr, 0, i);
            return i;
        }
    }

    return -1;
} // Time complexity: O(n + 1) = O(n)

/*
 * Condition
 * 1. Array must be sorted
 */
int BinarySearch(struct Array* arr, int value)
{
    int lowIndex, midIndex, highIndex;

    lowIndex = 0;
    highIndex = arr->length - 1;

    while (lowIndex <= highIndex)
    {
        midIndex = (lowIndex + highIndex) / 2;

        int mid = arr->A[midIndex];

        if (mid == value)
        {
            return midIndex;
        }

        if (value < mid)
        {
            highIndex = midIndex - 1;
        }
        else
        {
            lowIndex = midIndex + 1;
        }
    }

    return -1;
}

int Get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }
    return index;
}

int Set(struct Array* arr, int index, int value)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = value;
    }

    return arr->A[index];
}

int Max(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++) // O(n-1)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }

    return max;
} // Time complexity: O(n)

int Min(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++) // O(n-1)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }

    return min;
} // Time complexity: O(n)

int Sum(struct Array arr)
{
    int sum = arr.A[0]; // O(1)
    for (int i = 1; i < arr.length; i++) // O(n)
    {
        sum += arr.A[i]; // O(1)
    }

    return sum;
} // Time Complexity: O(n);

int RecursiveSum(struct Array arr, int index)
{
    if (index < 0)
    {
        return 0;
    }

    return RecursiveSum(arr, index - 1) + arr.A[index];
} // This approach is generally not preferred as it uses "stack"

int Reverse(struct Array arr)
{
    int i = 0;
    int j = arr.length - 1;

    while (i < j)
    {
        int temp = arr.A[i];
        arr.A[i] = arr.A[j];
        arr.A[j] = temp;

        i++;
        j--;
    }

    Display(arr);
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
    cout << Delete(&arr, 3) << " is deleted." << endl;
    Display(arr);

    cout << "----- Linear Search of value: 2 -----" << endl;
    cout << "Found at index " << LinearSearch(&arr, 2) << endl;
    cout << "After moving found value to head: " << endl;
    Display(arr);

    cout << "----- Binary Search of value: 3 -----" << endl;
    // Make sure to comment line 167 - 185
    cout << "Found at index " << BinarySearch(&arr, 3) << endl;

    cout << "----- Get of index: 3 -----" << endl;
    cout << "Value at index 3: " << Get(arr, 3) << endl;

    cout << "----- Set index 3 to value 100 -----" << endl;
    cout << "Value at index 3: " << Set(&arr, 3, 100) << endl;
    Display(arr);

    cout << "----- Max -----" << endl;
    cout << "Maximum value of the array: " << Max(arr) << endl;

    cout << "----- Min -----" << endl;
    cout << "Minimum value of the array: " << Min(arr) << endl;

    cout << "----- Sum -----" << endl;
    cout << "The sum of the array: " << Sum(arr) << endl;
    cout << "The sum of the array using recursive approach: " << RecursiveSum(arr, arr.A[arr.length - 1]) << endl;

    cout << "---- Reverse ----" << endl;
    Reverse(arr);
}
