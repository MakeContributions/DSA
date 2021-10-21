/*PROBLEM:Given an array, of size n, reverse it. */

#include <stdio.h>

/* Function to reverse arr[] from start to end*/
void rvereseArray(int arr[], int start, int end)
{
    int temp;
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

/* Function to print out an array on a line */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main()
{
    int n;
    printf("Enter n : "); //n is number of elements in the array
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    rvereseArray(arr, 0, n - 1);
    printf("Reversed array is \n");
    printArray(arr, n);
    return 0;
}

/*
Case 1:
Input: Enter size: 5
       1  2   3   4   5
Output: Reversed array is
       5  4   3   2   1

Case 2:
Input: Enter size: 7
       1  13  15  20  12  13  2 
Output: Reversed array is
       2  13  12  20  15  13  1 

Time complexity: O(N) where N is the size of array
*/
