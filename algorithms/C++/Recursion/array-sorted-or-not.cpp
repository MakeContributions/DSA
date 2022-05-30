/*
Description: A program to check if array is sorted or not using recursion

Approach: To compare last (n-1) element with the second last (n-2) element.
And decrementing the value of n at each recursive call, so that
we can search the entire array.

Time complexity: O(n)
*/

#include <iostream>
using namespace std;

//function starts
bool sorted(int arr[], int n)
{
    //base case
    if (n == 1 || n == 0)
    {
        return true;
    }

    if (arr[n - 1] > arr[n - 2])
    {
        //recursive function call
        return sorted(arr, n - 1);
    }
    //if the element at (n-1) index is not greater than (n-2) element
    //return false directly, which means array is not sorted
    return false;
}

//main starts
int main()
{
    int arr[] = {8, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << sorted(arr, n);
    return 0;
}

/*
Sample Input:
arr=[8, 2, 3, 4, 5, 6]
n=6

Output: 0

Sample Input:
arr=[1,2,3]
n=3

Output: 1
*/