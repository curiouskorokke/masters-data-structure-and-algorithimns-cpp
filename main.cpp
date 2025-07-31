#include<iostream>
#include<cstdlib>

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
        Swap(&arr, i, j);
        i++;
        j--;
    }

    Display(arr);
}

void InsertSorted(struct Array* arr, int value)
{
    if (arr->length >= arr->size)
    {
        cout << "Size exceeded" << endl;
        return;
    }

    int i = arr->length - 1;

    while (arr->A[i] > value)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }

    arr->A[i + 1] = value;
    arr->length++;
}

bool IsSorted(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            return false;
        }
    }
    return true;;
}

void SortNegativeToPositive(struct Array* arr)
{
    int i = 0;
    int j = arr->length - 1;

    while (i < j)
    {
        while (arr->A[i] < 0)
        {
            i++;
        }

        while (arr->A[j] >= 0)
        {
            j--;
        }

        if (i < j)
        {
            Swap(arr, i, j);
        }
    }
}

/*
 * Merge Sorted
 * Condition:
 * 1. Both arrays merging must be sorted.
 */
Array MergeSorted(struct Array* targetArray, struct Array addArray)
{
    int newArrayLength = targetArray->length + addArray.length;
    int* arr = new int[newArrayLength];
    int i = 0;
    int j = 0;


    while (i < targetArray->length && j < addArray.length )
    {
        if (targetArray->A[i] < addArray.A[j])
        {
            arr[i + j] = targetArray->A[i];
            i++;
        }
        else
        {
            arr[i + j] = addArray.A[j];
            j++;
        }
    }

    while (i < targetArray->length)
    {
        arr[i + j] = targetArray->A[i];
        i++;
    }

    while (j < addArray.length)
    {
        arr[i + j] = addArray.A[j];
        j++;
    }

    struct Array newArr = {arr, newArrayLength, newArrayLength};

    return newArr;
}

int main()
{
    // struct Array arr;

    // cout << "Enter array size:" << endl;
    // cin >> arr.size;
    //
    // arr.A = new int[arr.size];
    //
    // cout << "Enter array length:" << endl;
    // cin >> arr.length;
    //
    // for (int i = 0; i < arr.length; i++)
    // {
    //     cout << "Enter value of element: ";
    //     cout << endl;
    //     cin >> arr.A[i];
    // }
    //
    // cout << "----- Display -----" << endl;
    // Display(arr);

    // cout << "----- Append 10 -----" << endl;
    // Append(&arr, 10);
    // Display(arr);

    // cout << "----- Insert value: 23 at index: 3 -----" << endl;
    // Insert(&arr, 23, 0);
    // Display(arr);

    // cout << "----- Delete at index: 3 -----" << endl;
    // cout << Delete(&arr, 3) << " is deleted." << endl;
    // Display(arr);
    //
    // cout << "----- Linear Search of value: 2 -----" << endl;
    // cout << "Found at index " << LinearSearch(&arr, 2) << endl;
    // cout << "After moving found value to head: " << endl;
    // Display(arr);
    //
    // cout << "----- Binary Search of value: 3 -----" << endl;
    // // Make sure to comment line 167 - 185
    // cout << "Found at index " << BinarySearch(&arr, 3) << endl;
    //
    // cout << "----- Get of index: 3 -----" << endl;
    // cout << "Value at index 3: " << Get(arr, 3) << endl;
    //
    // cout << "----- Set index 3 to value 100 -----" << endl;
    // cout << "Value at index 3: " << Set(&arr, 3, 100) << endl;
    // Display(arr);
    //
    // cout << "----- Max -----" << endl;
    // cout << "Maximum value of the array: " << Max(arr) << endl;
    //
    // cout << "----- Min -----" << endl;
    // cout << "Minimum value of the array: " << Min(arr) << endl;
    //
    // cout << "----- Sum -----" << endl;
    // cout << "The sum of the array: " << Sum(arr) << endl;
    // cout << "The sum of the array using recursive approach: " << RecursiveSum(arr, arr.A[arr.length - 1]) << endl;
    //
    // cout << "---- Reverse ----" << endl;
    // Reverse(arr);

    // cout << "----- Inserting in a sorted array -----" << endl;
    // struct Array arr2 = {new int(5), 10, 5};
    // for (int i = 0; i < arr2.length; i++)
    // {
    //     arr2.A[i] = i * 2;
    // }
    //
    // InsertSorted(&arr2, 5);
    // Display(arr2);
    //
    // cout << "----- Is Sorted -----" << endl;
    // struct Array arr3 = {new int(5), 10, 5};
    // for (int i = 0; i < arr3.length; i++)
    // {
    //     arr3.A[i] = i * 2;
    // }
    // Display(arr3);
    // cout << "Array is 1: Sorted, 0: Not sorted: " << IsSorted(arr3) << endl;
    //
    // cout << "----- Rearrange -----" << endl;
    // struct Array arr4 = {new int(10), 10, 10};
    // for (int i = 0; i < arr4.length; i++)
    // {
    //     int sign = rand() % 2 ? -1 : 1;
    //     arr4.A[i] = sign * i * 3;
    // }
    // Display(arr4);
    // SortNegativeToPositive(&arr4);
    // cout << "Sorted: ";
    // Display(arr4);


    cout << "----- Merging Arrays -----" << endl;
    struct Array arr5 = {{new int[5]}, 5, 5};
    struct Array arr6 = {new int[5], 5, 5};

    for (int i = 0; i < arr5.length; i++)
    {
        arr5.A[i] = i * 10;
    }

    for (int i = 0; i < arr6.length; i++)
    {
        arr6.A[i] = i * 2 + 1;
    }

    cout << "Array 5: ";
    Display(arr5);
    cout << "Array 6: ";
    Display(arr6);
    Display(MergeSorted(&arr5, arr6));
}
