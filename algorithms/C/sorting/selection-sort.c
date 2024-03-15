
#include <stdio.h>

// Function to swap two elements
void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

// Function to perform selection sort
void selectionSort(int a[], int n)
{
   int i, j;
   for (i=0;i<n-1;i++){
       for (j=i+1;j<n;j++){
           if(a[i]>a[j]){
               swap(&a[i], &a[j]);
           }
       }
   }    
}

// Function to print an array
void printArray(int a[], int size)
{
    int i;
    for (i=0; i < size; i++){
        printf("%d ", a[i]);
    }
}

// Main function
int main()
{
    int a[] = {64, 25, 25, 12, 22, 11, 90};
    int n = sizeof(a)/sizeof(a[0]);
    printf("Initial array: \n");
    printArray(a, n);
    selectionSort(a, n);
    printf("\nSorted array: \n");
    printArray(a, n);
    return 0;
}

/*
Output:
Initial array:
64 25 25 12 22 11 90
Sorted array:
11 12 22 25 25 64 90

Complexity:
Worst case time complexity = Best case time complexity = Average case time complexity = O(n^2)
*/
