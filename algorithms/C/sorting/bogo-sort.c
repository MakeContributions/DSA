/*
[ALGORITHM]: Bogo sort - one of the most inefficient sorting algorithm 

[PROBLEM]: Given an array, of size n, sort it.

[TIME COMPLEXITY]: O(N * N!)

[SAMPLE OF OUTPUT]:

Before sorting:
8 3 7 4 6 2 1 9 5 10 
After sorting:
1 2 3 4 5 6 7 8 9 10
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void swap(int *a, int *b) // Swap values between *a and *b
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void shuffle(int *array, int size) // Randomly shuffles given array for further info check DSA/algorithms/C/arrays/shuffle_array.c
{
    for (int i = 0; i < size; i++) {
        swap(array + i, array + (rand() % size));
    }
}

bool is_sorted(int *array, int size) // If array is sorted (by non-reduction) return true, else false
{
    for (int i = 1; i < size; i++) {
        if (array[i] < array[i - 1])
            return false;
    }
    return true;
}

void bogo_sort(int *array, int size) // Until array is sorted randomly shuffles an array.
{
    while (!is_sorted(array, size))
        shuffle(array, size);
}

void print_array(int *array, int size) // Printing array
{
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    putchar('\n');
}

int main()
{
    srand(time(NULL)); // Setup of random seed for random generation
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    /*
    Be accurate with size of array, sorting an array with 15 (for example) elements could
    take unexpected amount of time.

    For example:
    Sorting 15 elements is 36036 times longer than sorting 10 elements.
    So, if sorting 10 elements take half a second,
    then sorting 15 elements approximately take 5 hours (in real could longer).
    */

    shuffle(array, 10); // Shuffling an array before sorting

    printf("Before sorting:\n");
    print_array(array, 10);

    bogo_sort(array, 10);
    printf("After sorting:\n");
    print_array(array, 10);

    return 0;
}

