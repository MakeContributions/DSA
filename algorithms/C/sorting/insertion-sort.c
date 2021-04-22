/*
Program to Print the array in sorted order using Insertion Sort
Insertion Sort: It is a algorithm to sort array like you play cards.
*/

#include<stdio.h>
#include<stdlib.h>

//Function to sort array using insertion sort
void insertion_sort(int a[],int size)
{
     int round,i,shift=0;
     // assign 1 to round until the round is less than size run the loop and increment round by 1
     for(round=1;round<=size-1;round++)
     {
         // take a[round] value in shift
         shift=a[round];
         // now assign round to i and until i is greater than 0 run the loop
         for(i=round;i>=1;i--)
         {
             // check whether the a[i-1] is less than the shift variable value if yes then break
             if(a[i-1]<shift)
             break;
             // assign a[i-1] data in a[i]
             else
             {
                a[i]=a[i-1];
             }
         }
         // assign shift to a[i]
         a[i]=shift;
     }
          // Print the sorted array
          printf("After Insertion sorting: ");
          for(i=0;i<size;i++)
          printf("%d ",a[i]);
          printf("\n");
}
//driver code
int main()
{
    int size,*arr,i;
    printf("Enter the size: ");
    //taking size of array from user
    scanf("%d",&size);
    // allocating dynamically memory and putting the base address in arr
    arr=(int*)malloc(sizeof(int)*size);
    printf("Enter %d numbers: ",size);
    // until i is less than size run the loop
    for(i=0;i<size;i++)
    // taking arr[i]th index value
    scanf("%d",&arr[i]);
    //calling insertion sort to sort the array
    insertion_sort(arr,size);
    return 0;
 
}
/*
Input: Enter Size: 5
       Enter 5 numbers: 50 40 30 20 10
Output: After Insertion sorting: 10 20 30 40 50

Time complexity: O(N^2)
*/
