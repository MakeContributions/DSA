// linear search
#include <stdio.h>
#define SIZE 100  //change according to question

//function prototype
int linearSearch(int a[], int query, int size);

int main()
{
   int data[ SIZE ], i, temp;
   int searchQuery; //value to search in the array

   //generate some data
   for (i = 0; i < SIZE; ++i)
   {
      data[ i ] = 2 * i;
   }

   printf("Enter integer to search for: ");
   scanf("%d", &searchQuery);

   //finding searchQuery in array data
   temp = linearSearch(data, searchQuery, SIZE);

   //condition for displaying result
   if ( temp != -1)
      printf("Found value in element %d.", temp);
   else
      printf("Value not found.");

   return 0;
}

//Linear search function

int linearSearch(int a[], int query, int size)
{
   int j; //counter variable

   //loop through array
   for (j = 0; j < size; ++j)
   {
      if ( a[ j ] == query)
      {
         return j; //return location of value
      }
   }

   return -1; //value not found
}
/*
Case 1:
Input: Enter size: 10
       1,2,3,4,5,6,7,8,9,10
       Enter the data to search: 11
Output: Data not Found

Case 2:

Input: Enter size: 10
       1,2,3,4,5,6,7,8,9,10
       Enter the data to search: 7
Output: Data Found at index: 6

Time complexity: O(n)  //where n is the size of array

*/