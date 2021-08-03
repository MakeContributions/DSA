// CPP program for implementation of "Quick-select" method based on Quick-sort or partition algorithm
//The Question here is to find the kth smallest element in an array.
//if array = {10 20 30 40 50 60} and k=2 then k'th smallest element will be : 20

#include <bits/stdc++.h>
using namespace std;

// Standard partition process of QuickSort().
// It considers the last element as pivot
// and moves all smaller element to left of
// it and greater elements to right
int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[r]);
    return i;
}

// This function returns k'th smallest
// element in arr[l..r] using QuickSort
// based method. ASSUMPTION: ALL ELEMENTS
// IN ARR[] ARE DISTINCT
int kthSmallest(int arr[], int l, int r, int k)
{
    // If k is smaller than number of
    // elements in array
    if (k > 0 && k <= r - l + 1)
    {

        // Partition the array around last
        // element and get position of pivot
        // element in sorted array
        int index = partition(arr, l, r);

        // If position is same as k
        if (index - l == k - 1)
            return arr[index];

        // If position is more, recur
        // for left subarray
        if (index - l > k - 1)
            return kthSmallest(arr, l, index - 1, k);

        // Else recur for right subarray
        return kthSmallest(arr, index + 1, r,
                           k - index + l - 1);
    }

    // If k is more than number of
    // elements in array
    return INT_MAX;
}

// Driver program to test above methods
int main()
{
    int arr[] = {7, 6, 10, 8, 3, 1, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << "K-th smallest element is "
         << kthSmallest(arr, 0, n - 1, k);
    return 0;
}
