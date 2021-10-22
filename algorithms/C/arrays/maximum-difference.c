/* PROBLEM: Given an array arr[] of integers, find out the maximum difference between any two elements such that larger element appears after the smaller number.  */

#include <stdio.h>

/* The function assumes that there are at least two
elements in array.
The function returns a negative value if the array is
sorted in decreasing order.
Returns 0 if elements are equal */
int maxDiff(int arr[], int arr_size)
{
    int max_diff = arr[1] - arr[0];
    int min_element = arr[0];
    int i;
    for (i = 1; i < arr_size; i++)
    {
        if (arr[i] - min_element > max_diff)
            max_diff = arr[i] - min_element;
        if (arr[i] < min_element)
            min_element = arr[i];
    }
    return max_diff;
}

int main()
{
    int n;
    printf("Enter n : "); // n is number of elements in the array
    scanf("%d", &n);
    int arr[n];
    if(n<2){
        printf("Invalid Input!!!");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Maximum difference is %d\n", maxDiff(arr, n));
    getchar();
    return 0;
}

/*
Case 1:
Input: Enter size: 5
       1  2   3   4   5
Output: Maximum difference is 4

Case 2:
Input: Enter size: 6
        7  9  5  6  3  2
Output: Maximum  difference is 5

Time complexity: O(N) where N is the size of array
*/
