// Quick Sort Algorithm in C

#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* This function takes first element as pivot, places the pivot element at its correct position in sorted array, 
and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot.*/
int Partition(int a[], int low, int high)
{
    int pivot = a[low];
    int start = low;
    int end = high;

    while (start < end)
    {
        while (a[start] <= pivot)
            start++;
        while (a[end] > pivot)
            end--;
        if (start < end)
        {
            swap(&a[start], &a[end]);
        }
    }
    swap(&a[low], &a[end]);
    return end;
}

// Recursive function to sort an array using quick sort
void Quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot = Partition(a, low, high);
        Quicksort(a, low, pivot - 1);
        Quicksort(a, pivot + 1, high);
    }
}

int main()
{
    int a[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(a) / sizeof(a[0]);
    Quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}

/*
Output:
1 2 3 4 5 6
*/