// CPP program for implementation of "Quick-select" method based on Quick-sort or partition algorithm
//The Question here is to find the kth smallest element in an array.
//if array = {10 20 30 40 50 60} and k=2 then k'th smallest element will be : 20

#include <bits/stdc++.h>
using namespace std;

// Standard partition process of QuickSort().
// It considers the last element as pivot
// and moves all smaller element to left of
// it and greater elements to right
int partition(int arr[], int left, int right)
{
    int x = arr[right], i = left;
    for (int j = left; j <= right - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[right]);
    return i;
}

// This function returns k'th smallest
// element in arr[l..r] using QuickSort
// based method. ASSUMPTION: ALL ELEMENTS
// IN ARR[] ARE DISTINCT
int kthSmallest(int arr[], int left, int right, int k)
{
    // If k is smaller than number of
    // elements in array
    if (k > 0 && k <= right - left + 1)
    {

        // Partition the array around last
        // element and get position of pivot
        // element in sorted array
        int index = partition(arr, left, right);

        // If position is same as k
        if (index - left == k - 1)
            return arr[index];

        // If position is more, recur
        // for left subarray
        if (index - left > k - 1)
            return kthSmallest(arr, left, index - 1, k);

        // Else recur for right subarray
        return kthSmallest(arr, index + 1, right,
                           k - index + left - 1);
    }

    // If k is more than number of
    // elements in array
    return INT_MAX;
}

// Driver program to test above methods
int main()
{
    int size;
    cout << "Enter the size" << endl;
    cin >> size;

    int arr[size];
    cout << "Enter the array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the value of k (must be less than size)" << endl;
    cin >> k;
    cout << "K-th smallest element is "
         << kthSmallest(arr, 0, size - 1, k);
    return 0;
}
