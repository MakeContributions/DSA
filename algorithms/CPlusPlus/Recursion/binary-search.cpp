/*
Description: Binary search using recursion

Approach: To use recursion, for updating start and end variables.

Time Complexity: O(log n)
*/

#include <iostream>
using namespace std;

//function starts
int search(int arr[], int n, int start, int end, int target)
{
    //base case
    //if start is greater than end, it means we haven't found our target element
    //return -1
    if (start > end)
    {
        return -1;
    }
    //calculating mind element
    int mid = start + (end - start) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }
    if (arr[mid] > target)
    {
        //end = mid-1;
        return search(arr, n, start, mid - 1, target);
    }
    else
    {
        //start=mid+1;
        return search(arr, n, mid + 1, end, target);
    }
}

//main starts
int main()
{
    // Write C++ code here
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 6;
    int start = 0;
    int end = n - 1;
    int ind = search(arr, n, start, end, target);
    cout << "Element found at index: " << ind;
    return 0;
}

/*
Sample input:
arr=[1,2,3,4,5,6]
target=6;

Output:
Element found at index: 5
*/