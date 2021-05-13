// linear search
#include <stdio.h>
#include <stdlib.h>
//function prototype
int linearSearch(int a[], int query, int size);

int main()
{
   int *data,i,temp,searchQuery,size;
   printf("Enter size:");
   scanf("%d",&size);
   data=(int*)malloc(sizeof(int)*size);

   //generate some data
   for (i = 0; i < size; ++i)
   {
      scanf("%d",&data[i]);
   }

   printf("Enter integer to search for: ");
   scanf("%d", &searchQuery);

   //finding searchQuery in array data
   temp = linearSearch(data, searchQuery, size);

   //condition for displaying result
   if ( temp != -1)
      printf("Value found at index no:%d", temp);
   else
      printf("Value not found");

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
       1,2,3,4,5,6,7,8,50,10
       Enter the data to search: 11
Output: Data not Found

Case 2:

Input: Enter size: 10
       1,2,3,4,5,6,7,8,9,10
       Enter the data to search: 7
Output: Data Found at index: 6

Time complexity: O(n)  //where n is the size of array

*/