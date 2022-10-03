#include <iostream>
using namespace std;

struct Array
{
    int A[10], size, length;
};

void Display(struct Array arr)
{
    cout << "Elements are" << endl;
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
}
// BINRAY SEARCH - ITERATIVE
int BinarySearch(Array arr, int key) // "arr" is passed by CALL BY VALUE because it is just searching the element and not modifying it.
{
    int l, mid, h;
    l = 0;
    h = arr.length - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
// BINRAY SEARCH - RECURSIVE
int RBinSearch(int a[], int l, int h, int key)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return RBinSearch(a, l, mid - 1, key);
        else
            return RBinSearch(a, mid + 1, h, key);
    }
    return -1; // If 'key' not found, return -1. -1 because it is not a valid index.
}
int main()
{
    Array arr = {{2,3,4,5,6,}, 10, 5}; // NOTE: For Binary Search the list must always be already sorted!!
    // cout<<BinarySearch(arr,22)<<endl; --> BinarySearch
    cout << RBinSearch(arr.A, 0, arr.length, 6) << endl;
    Display(arr);

    return 0;
}