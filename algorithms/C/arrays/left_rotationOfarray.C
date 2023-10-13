/* PROBLEM: Given an array arr[] of integers, now make left rotation of the array according to the number given by user then print the updated array  */

#include <stdio.h>
#include<stdlib.h>
void reverse(int*arr,int start,int end)
{
    while(start<end)
    {
        int temp;
        temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}
int main()
{
    int size;
    printf("Enter size : "); // size is number of elements in the array
    scanf("%d", &size);
    int *arr;
    arr=(int*)malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    int no_of_rotation;
    printf("Enter No Of left rotation:");
    scanf("%d",&no_of_rotation);
    if(size==1){
       printf("%d",arr[0]);
    }
    else{
        no_of_rotation=no_of_rotation%size; //fix the no of rotation ,if rotation number is gretter than size , then so that the no of rotation dose not excede the size .
        reverse(arr,0,no_of_rotation-1);   //reverse the array 1st time toll the index of no_of_rotation-1
        reverse(arr,no_of_rotation,size-1); //reverse the array elements left after the 1st time reverse.
        reverse(arr,0,size-1);  //reverse the whole array once .
    }
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    
   return 0;
}

/*
Case 1:
Input: Enter size: 5
       1  2   3   4   5
       Enter no_of_rotation:4
Output:5 1 2 3 4
Case 2:
Input: Enter size: 6
        7  9  5  6  3  2
        Enter no_of_rotation:10
Output: 3 2 7 9 5 6
Time complexity: O(N) where N is the size of array
*/

