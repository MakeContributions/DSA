#include <stdio.h>

int insert(int *arr, int n, int key, int pos)
{
    for (int i = n - 1; i >= pos; i--) // inserting by shifting
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = key;
}

int printArray(int *arr, int n) // printing elements of array
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int a[] = {10, 20, 30, 80, 90, 40};
    int n = sizeof(a) / sizeof(a[0]);
    printf("BEFORE INSERTION\n");
    printArray(a, n);
    int key = 50, pos = 2;
    insert(a, n, key, pos);
    n++;
    printf("AFTER INSERTION\n");
    printArray(a, n);

    return 0;
}