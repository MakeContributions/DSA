/*
Description: To find minimum and maximum element in array using recursion

Time Complexity: O(n)
*/

#include <iostream>
using namespace std;

//function to find minimum element in the array
int findmin(int arr[], int n)
{
    //base case
    //if there is only 1 element in array, it will be the minimum element
    if (n == 1)
    {
        return arr[0];
    }
    //recursive function call
    int mm = findmin(arr, n - 1);
    //return minimum element from every recursive call to the function
    return min(arr[n - 1], mm);
}

//function to find maximum element in the array
int findmax(int arr[], int n)
{
    //base case
    //if there is only 1 element in array, it will be the maximum element
    if (n == 1)
    {
        return arr[0];
    }
    //recursive function call
    int mm = findmax(arr, n - 1);
    //return maximum element from every recursive call to the function
    return max(arr[n - 1], mm);
}

//main starts
int main()
{
    int arr[] = {-1, -2, 3, 4, 5, 6};
    int n = 6;
    cout << "Minimum element in array: " << findmin(arr, n) << endl;
    cout << "Maximum element in array: " << findmax(arr, n);
    return 0;
}

/*
Sample Input:
arr=[-1,-2,3,4,5,6]

Output:
Minimum element in array: -2
Maximum element in array: 6
*/