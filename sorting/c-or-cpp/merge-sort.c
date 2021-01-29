#include <stdio.h>
#include <stdlib.h>
void merging(int a[], int l, int m, int r);
void mergeSort(int a[], int l, int r);

// Driver code
int main()
{
    int n;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Given array is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    mergeSort(a, 0, n - 1);
    printf("\nSorted array is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}

// Merges two subarrays of a[].
// First subarray is a[l..m]
// Second subarray is a[m+1..r]
void merging(int a[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int Left[n1], Right[n2]; // Creating temporary arrays

    // Copy data to temp arrays Left[] and Right[]
    for (int i = 0; i < n1; i++)
        Left[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        Right[j] = a[m + 1 + j];

    int p = 0, q = 0, k = l;
    while (p < n1 && q < n2)
    {
        if (Left[p] <= Right[q])
        {
            a[k] = Left[p];
            p++;
        }
        else
        {
            a[k] = Right[q];
            q++;
        }
        k++;
    }

    // Copy the remaining elements of
    // Left[], if there are any
    while (p < n1)
    {
        a[k] = Left[p];
        p++;
        k++;
    }

    // Copy the remaining elements of
    // Right[], if there are any
    while (q < n2)
    {
        a[k] = Right[q];
        q++;
        k++;
    }
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted
void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merging(a, l, m, r);
    }
}
