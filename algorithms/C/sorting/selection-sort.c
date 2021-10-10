
#include <stdio.h>
 
void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}
 
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
 
void printArray(int a[], int size)
{
    int i;
    for (i=0; i < size; i++){
        printf("%d ", a[i]);
    }
}

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
