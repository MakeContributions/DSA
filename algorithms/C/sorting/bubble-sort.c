//bubble sort
#include <stdio.h>
#include <stdlib.h>

void swap(int *value1, int *value2);


//time complexity: O(n^2)
void bubble_sort(int array[], int array_size)
{
    for(int i = 0; i < array_size; i++)
    {
        for(int j = 0; j < array_size - 1; j++)
        {
            if(array[j] > array[j+1])
            {
                swap(&array[j], &array[j+1]);
            }
        }
    }
}

void swap(int *value1, int *value2)
{
    int temp = *value1;
    *value1 = *value2;
    *value2 = temp;
}

int main()
{
    int array_size;
    do{
        printf("Input the size of the array: ");
        scanf("%d", &array_size);
    }while(array_size <= 1);
    
    int *array = (int*)malloc(sizeof(int)*array_size);
    for(int i = 0; i < array_size; i++)
    {
        printf("Input an integer: ");
        scanf("%d", &array[i]);
    }
    
    bubble_sort(array, array_size);
    
    printf("Sorted array: [ ");
    for(int i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("]\n");
    return 0;
}
