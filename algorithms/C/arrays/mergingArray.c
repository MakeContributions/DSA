/******************************************************************************
           Program to print the merged array without using third array
******************************************************************************/

#include<stdio.h>
#define maxSize 100

int main()
{
    int arrayOne[maxSize], sizeOne;
    int arrayTwo[maxSize], sizeTwo;
    int temp;

    // Scanning the size of the array I
    printf("Enter the size of the array I: ");
    scanf("%d",&sizeOne);

    // Scanning the array I of sizeOne
    printf("Enter the %d elements of array I: \n",sizeOne);
    for(int i=0; i<sizeOne; i++)
    {
        printf("Element [%d]: ",i);
        scanf("%d",&arrayOne[i]);
    }

    // Scanning the size of the array II
    printf("Enter the size of the array II: ");
    scanf("%d",&sizeTwo);

    // Scanning the array II of sizeTwo
    printf("Enter the %d elements of array II: \n",sizeTwo);
    for(int i=0; i<sizeTwo; i++)
    {
        printf("Element [%d]: ",i);
        scanf("%d",&arrayTwo[i]);
    }

    // Assingning the last element of I array to the temp variable
    temp = arrayOne[sizeOne];

    // Size of array I is converted as follows
    sizeOne += sizeTwo;

    // Merging the array I and array II in array I
    for(int i=0; i<sizeOne; i++)
    {
        if(arrayOne[i] == temp)
        {
            for(int j=0; j<sizeTwo; j++)
            {
                arrayOne[i++] = arrayTwo[j];      
            }
        }
    }

    // Printing the merged array
    printf("Merged Array: \n");
    for(int i=0; i<sizeOne; i++)
    {
        printf("%d ",arrayOne[i]);
    }

    return 0;
}


/*
OUTPUT

Enter the size of the array I: 3
Enter the 3 elements of array I: 
Element [0]: 1
Element [1]: 2
Element [2]: 3
Enter the size of the array II: 3
Enter the 3 elements of array II: 
Element [0]: 4
Element [1]: 5
Element [2]: 6
Merged Array: 
1 2 3 4 5 6
*/
