/*
Problem: Search data using Binary Search
Binary Search: It is a way to search data in efficient time.It
works by repeatedly dividing in half the portion of the
list that could contain the item, until you have narrowed down
the possible locations to just one.
*/

#include <stdio.h>
#include <stdlib.h>

//Function to search data using binary search
int binary_search(int *arr,int size,int to_search)
{
    //initialize start as 0 and end as size-1
    int start=0,end=size-1,mid;
    //until start is less than or equal to end run the loop
    while(start<=end)
    {
       //every time assign start+((end-start)/2)(middle element of the current array) in mid
       mid=start+((end-start)/2);
       // if the data found in middle of the array then return the index
       if(arr[mid]==to_search)
            return mid;
        /* if the middle index value of array is greater than to search
         the data to search is less than middle element of current element so end should be
         assign less than middle means mid-1 */
        else if(arr[mid]>to_search)
            end=mid-1;
        /* if else condition runs that means the data is greater than the middle element of
        current array so the start variable should have mid+1 index number */
        else
            start=mid+1;
    }
    // if the data not found till the loop run that means data is not present in given array
    return -1;
}
//driver code
int main()
{
    int size,*arr,i,to_search,result;
    printf("Enter size: ");
    //taking size
    scanf("%d",&size);
    //dynamically allocating memory and assigning the base address in arr
    arr=(int*)malloc(sizeof(int)*size);
    for(i=0;i<size;i++)
    scanf("%d",&arr[i]);
    printf("Enter a number to search: ");
    //taking the data to search
    scanf("%d",&to_search);
    // calling binary_search to find the element index or -1 if not present and assign it to result
    result=binary_search(arr,size,to_search);
    if(result==-1)
        printf("Data Not Found");
    else
        printf("Data Found at index no: %d",result);
    return 0;
}
/*
Case 1:
Input: Enter size: 5
       1  2   3   4   5
       Enter a number to search: -1
Output: Data Not Found

Case 2:
Input: Enter size: 5
       2  5   9   110   112
       Enter a number to search: 110
Output: Data Found at index no: 3

Time complexity: O(log N) where N is the size of array
*/
