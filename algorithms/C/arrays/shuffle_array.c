/*
[PROBLEM]: Given an array, of size n, shuffle it.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) // Swap values between *a and *b
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void shuffle(int *array, int size) // Randomly shuffles given array
{
    for (int i = 0; i < size; i++) {
        swap(array + i, array + (rand() % size));
    }
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
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    printf("Before shuffling:\n");
    print_array(array, 15);

    shuffle(array, 15);
    printf("After shuffling:\n");
    print_array(array, 15);

    return 0;
}
