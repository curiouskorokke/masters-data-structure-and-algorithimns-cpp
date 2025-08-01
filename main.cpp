#include<iostream>
using namespace std;

/*
 * Array (Abstract Datatype - ADT)
 */

class Array
{
private:
    int* A;
    int size;
    int length;

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }

    explicit Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }

    ~Array()
    {
        delete []A;
    }

    void Display();
    void Append(int value);
};


void Array::Display()
{
    for (int i = 0; i < length; i++) // O(n)
    {
        cout << A[i] << " "; // O(1)
    }
    cout << endl;
} // Time Complexity: n + 1 = O(n)

void Array::Append(int value)
{
    if (length < size) // O(1)
    {
        A[length] = value; // O(1)
        length++; // O(1)
    }
    else
    {
        cout << "Array size is at it's capacity." << endl;
    }
} // Time Complexity: O(1)

// void Insert(struct Array* arr, int value, int index)
// {
//     if (arr->length == arr->size) // O(1)
//     {
//         cout << "Array size is at it's capacity." << endl;
//         return;
//     }
//
//     if (index > arr->length && index < 0) // O(1)
//     {
//         cout << "Invalid index." << endl;
//         return;
//     }
//
//     for (int i = arr->length; i >= 0; i--) // Best: O(1), Worst: O(n)
//     {
//         arr->A[i + 1] = arr->A[i]; // O(1)
//
//         if (i == index) // O(1)
//         {
//             arr->A[index] = value; // O(1)
//             break;
//         }
//     }
//
//     arr->length++; // O(1)
// } // Time Complexity: O(n +5) = O(n)
//
// int Delete(struct Array* arr, int index)
// {
//     int x = arr->A[index]; // O(1)
//     if (index < arr->length - 1 && index >= 0) // O(1)
//     {
//         for (int i = index; i < arr->length; i++) // Best: O(1), Worst: O(n)
//         {
//             arr->A[i] = arr->A[i + 1]; // O(1)
//         }
//
//         arr->length--; // O(1)
//         return x;
//     }
//     else
//     {
//         cout << "Invalid index." << endl;
//         return -1;
//     }
// } // Time Complexity: O(n + 4) = O(n)
//
// int LinearSearch(struct Array* arr, int value)
// {
//     for (int i = 0; i < arr->length; i++) // Worst: O(n), Best O(1)
//     {
//         if (arr->A[i] == value) // O(1)
//         {
//             // There are generally two ways to improve the next search
//             // 1. Transportation
//             // Swap(arr, i-1, i);
//             // 2. Move to Head
//             Swap(arr, 0, i);
//             return i;
//         }
//     }
//
//     return -1;
// } // Time complexity: O(n + 1) = O(n)
//
// /*
//  * Condition
//  * 1. Array must be sorted
//  */
// int BinarySearch(struct Array* arr, int value)
// {
//     int lowIndex, midIndex, highIndex;
//
//     lowIndex = 0;
//     highIndex = arr->length - 1;
//
//     while (lowIndex <= highIndex)
//     {
//         midIndex = (lowIndex + highIndex) / 2;
//
//         int mid = arr->A[midIndex];
//
//         if (mid == value)
//         {
//             return midIndex;
//         }
//
//         if (value < mid)
//         {
//             highIndex = midIndex - 1;
//         }
//         else
//         {
//             lowIndex = midIndex + 1;
//         }
//     }
//
//     return -1;
// }
//
// int Get(struct Array arr, int index)
// {
//     if (index >= 0 && index < arr.length)
//     {
//         return arr.A[index];
//     }
//     return index;
// }
//
// int Set(struct Array* arr, int index, int value)
// {
//     if (index >= 0 && index < arr->length)
//     {
//         arr->A[index] = value;
//     }
//
//     return arr->A[index];
// }
//
// int Max(struct Array arr)
// {
//     int max = arr.A[0];
//     for (int i = 1; i < arr.length; i++) // O(n-1)
//     {
//         if (arr.A[i] > max)
//         {
//             max = arr.A[i];
//         }
//     }
//
//     return max;
// } // Time complexity: O(n)
//
// int Min(struct Array arr)
// {
//     int min = arr.A[0];
//     for (int i = 1; i < arr.length; i++) // O(n-1)
//     {
//         if (arr.A[i] < min)
//         {
//             min = arr.A[i];
//         }
//     }
//
//     return min;
// } // Time complexity: O(n)
//
// int Sum(struct Array arr)
// {
//     int sum = arr.A[0]; // O(1)
//     for (int i = 1; i < arr.length; i++) // O(n)
//     {
//         sum += arr.A[i]; // O(1)
//     }
//
//     return sum;
// } // Time Complexity: O(n);
//
// int RecursiveSum(struct Array arr, int index)
// {
//     if (index < 0)
//     {
//         return 0;
//     }
//
//     return RecursiveSum(arr, index - 1) + arr.A[index];
// } // This approach is generally not preferred as it uses "stack"
//
// int Reverse(struct Array arr)
// {
//     int i = 0;
//     int j = arr.length - 1;
//
//     while (i < j)
//     {
//         Swap(&arr, i, j);
//         i++;
//         j--;
//     }
//
//     Display(arr);
// }
//
// void InsertSorted(struct Array* arr, int value)
// {
//     if (arr->length >= arr->size)
//     {
//         cout << "Size exceeded" << endl;
//         return;
//     }
//
//     int i = arr->length - 1;
//
//     while (arr->A[i] > value)
//     {
//         arr->A[i + 1] = arr->A[i];
//         i--;
//     }
//
//     arr->A[i + 1] = value;
//     arr->length++;
// }
//
// bool IsSorted(struct Array arr)
// {
//     for (int i = 0; i < arr.length - 1; i++)
//     {
//         if (arr.A[i] > arr.A[i + 1])
//         {
//             return false;
//         }
//     }
//     return true;;
// }
//
// void SortNegativeToPositive(struct Array* arr)
// {
//     int i = 0;
//     int j = arr->length - 1;
//
//     while (i < j)
//     {
//         while (arr->A[i] < 0)
//         {
//             i++;
//         }
//
//         while (arr->A[j] >= 0)
//         {
//             j--;
//         }
//
//         if (i < j)
//         {
//             Swap(arr, i, j);
//         }
//     }
// }
//
// /*
//  * Merge Sorted
//  * Condition:
//  * 1. Both arrays merging must be sorted.
//  */
// Array MergeSorted(struct Array* targetArray, struct Array addArray)
// {
//     int newArrayLength = targetArray->length + addArray.length;
//     int* arr = (int*)malloc(newArrayLength * (sizeof(int)));
//     int i = 0;
//     int j = 0;
//
//
//     while (i < targetArray->length && j < addArray.length) // O(m + n)
//     {
//         if (targetArray->A[i] < addArray.A[j])
//         {
//             arr[i + j] = targetArray->A[i];
//             i++;
//         }
//         else
//         {
//             arr[i + j] = addArray.A[j];
//             j++;
//         }
//     }
//
//     while (i < targetArray->length) // O(m)
//     {
//         arr[i + j] = targetArray->A[i];
//         i++;
//     }
//
//     while (j < addArray.length) // O(n)
//     {
//         arr[i + j] = addArray.A[j];
//         j++;
//     }
//
//     struct Array newArr = {arr, newArrayLength, newArrayLength};
//
//     return newArr;
// } // Time complexity: O(2m+2n) => O(4n) => O(n)
//
// Array UnsortedUnion(struct Array arrA, struct Array arrB)
// {
//     int size = arrA.size + arrB.size;
//     int* arr = (int*)malloc(size * sizeof(int));
//     int l = 0;
//
//     for (int i = 0; i < arrA.length; i++) // O(n)
//     {
//         arr[l] = arrA.A[i];
//         l++;
//     }
//
//     for (int j = 0; j < arrB.length; j++) // O(n)
//     {
//         int curr = arrB.A[j];
//
//         int k = 0;
//         while (k < arrA.length) // O(n)
//         {
//             if (arrA.A[k] == curr)
//             {
//                 break;
//             }
//
//             k++;
//         }
//
//         if (k == arrA.length)
//         {
//             arr[l] = curr;
//             l++;
//         }
//     }
//
//     struct Array arrC{arr, size, l};
//     return arrC;
// } // Time complexity: O(n + n*n) = O(n^2);
//
// Array SortedUnion(struct Array arrC, struct Array arrD)
// {
//     int size = arrC.size + arrD.size;
//     int* arr = (int*)malloc(size * sizeof(int));
//     int i = 0;
//     int j = 0;
//     int k = 0;
//
//     while (i < arrC.length && j < arrD.length)
//     {
//         if (arrC.A[i] > arrD.A[j])
//         {
//             arr[k++] = arrD.A[j++];
//         }
//         else if (arrC.A[i] < arrD.A[j])
//         {
//             arr[k++] = arrC.A[i++];
//         }
//         else
//         {
//             arr[k++] = arrD.A[j++];
//             i++;
//         }
//     }
//
//     for (; i < arrC.length; i++)
//     {
//         arr[k++] = arrC.A[i];
//     }
//
//     for (; j < arrD.length; j++)
//     {
//         arr[k++] = arrD.A[j];
//     }
//
//     struct Array newArr = {arr, size, k};
//
//     return newArr;
// }
//
// Array UnsortedIntersection(struct Array arrE, struct Array arrF)
// {
//     int size = arrE.size + arrF.size;
//     int* arr = (int*)malloc(size * sizeof(int));
//
//     int k = 0;
//     for (int i = 0; i < arrE.length; i++)
//     {
//         int curr = arrE.A[i];
//
//         int j = 0;
//         while (j < arrF.length)
//         {
//             if (arrF.A[j] == curr)
//             {
//                 arr[k] = curr;
//                 k++;
//                 break;
//             }
//             j++;
//         }
//     }
//
//     struct Array arrG{arr, size, k};
//
//     return arrG;
// }
//
// Array SortedIntersection(struct Array arrE, struct Array arrF)
// {
//     int size = arrE.size + arrF.size;
//     int i = 0;
//     int j = 0;
//     int k = 0;
//     int* arr = (int*)malloc(size * sizeof(int));
//
//     while (i < arrE.length && j < arrF.length)
//     {
//         if (arrE.A[i] < arrF.A[j])
//         {
//             i++;
//         }
//         else if (arrE.A[i] > arrF.A[j])
//         {
//             j++;
//         }
//         else
//         {
//             arr[k] = arrE.A[i];
//             k++;
//             i++;
//         }
//     }
//
//     struct Array arrG = {arr, size, k};
//
//     return arrG;
// }
//
// Array UnsortedDifference(struct Array arrI, struct Array arrJ)
// {
//     int size = arrI.size + arrJ.size;
//     int* arr = (int*)malloc(size * sizeof(int));
//     int k = 0;
//
//     for (int i = 0; i < arrI.length; i++)
//     {
//         int curr = arrI.A[i];
//         int j = 0;
//         bool unique = true;
//         while (j < arrJ.length)
//         {
//             if (curr == arrJ.A[j])
//             {
//                 unique = false;
//             }
//             j++;
//         }
//
//         if (unique)
//         {
//             arr[k] = curr;
//             k++;
//         }
//     }
//
//     struct Array newArr = {arr, size, k};
//
//     return newArr;
// }
//
// Array SortedDifference(struct Array arrK, struct Array arrL)
// {
//     int size = arrK.size + arrL.size;
//     int* arr = (int*)malloc(size * sizeof(int));
//     int i = 0;
//     int j = 0;
//     int k = 0;
//
//     while (i < arrK.length && j < arrL.length)
//     {
//         if (arrK.A[i] < arrL.A[j])
//         {
//             arr[k++] = arrK.A[i++];
//         }
//         else if (arrK.A[i] > arrL.A[j])
//         {
//             j++;
//         }
//         else
//         {
//             i++;
//             j++;
//         }
//     }
//
//     for (; i < arrK.length; i++)
//     {
//         arr[k++] = arrK.A[i];
//     }
//
//     struct Array newArr = {arr, size, k};
//     return newArr;
// }

int main()
{
    Array arr;
    int choice, value;

    do
    {
        cout << "1. Display" << endl;
        cout << "2. Append" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an operation to perform: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            arr.Display();
            cout<<"----------"<<endl;
            break;
        case 2:
            cout << "Provide value: ";
            cin >> value;
            arr.Append(value);
            break;
        }
    }
    while (choice != 0);


    return 0;
}
