#include <stdio.h>

// Shell Sort
void ShellSort(int a[], int n)
{
    int i, j, k, temp;
    // Rearrange elements at each n/2, n/4, n/8, ... intervals
    for (i = n / 2; i > 0; i /= 2)
    {
        for (j = i; j < n; j++)
        {
            temp = a[j];
            for (k = j; k >= i && a[k - i] > temp; k -= i)
            {
                a[k] = a[k - i];
            }
            a[k] = temp;
        }
    }
}

// Prints the array
void printArray(int a[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", a[i]);
    }
}

int main()
{
    int a[] = {64, 25, 12, 22, 11, 90};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Array before sorting:\n");
    printArray(a, n);
    ShellSort(a, n);
    printf("\nArray after sorting:\n");
    printArray(a, n);
    return 0;
}

/*
Output:
Array before sorting:
64 25 12 22 11 90
Array after sorting:
11 12 22 25 64 90

Time Complexity: O(n log n)
*/
