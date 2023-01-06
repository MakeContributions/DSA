#include <stdio.h>

int linearSearch(int *arr, int n, int key) // searching element
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}
int Delete(int *arr, int n, int key) // after searching , deleting process
{
    int pos = linearSearch(arr, n, key);
    if (pos == -1)
    {
        printf("Element not found\n");
        return n;
    }
    for (int i = pos; i < n; i++)
    {
        arr[i] = arr[i + 1];
        return (n - 1);
    }
}

int printArray(int *arr, int n)
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
    printf("BEFORE DELETION\n");
    printArray(a, n);
    int key = 20;
    n = Delete(a, n, key);
    printf("AFTER DELETION\n");
    printArray(a, n);

    return 0;
}