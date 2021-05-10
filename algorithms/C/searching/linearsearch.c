/* Program to search data in given array using linear search */
#include<stdio.h>
int main()
{
    int len;
    printf("Enter the lenght of array");
    scanf("%d",&len); //scanning the legth of array
}
int arr[len];  //created an array of size 'len'.
printf("Enter the element of array:\n");
for(int i=0;i<len;i++)
{
    scanf("%d",&arr[i]);  //storing all elments in array
}
int search;
printf("Enter the element to be searched:");
scanf("%d",&search);    //scan the searching element

//now we will compare searching value to all elements of array
 for(int i=0;i<len;i++)
{   /*comparing element*/
    if(arr[i]==search)
        printf("Element foung and the index of elelent is %d",i);
    // freq++;
    else
    {
        printf("Element not found");
    }
}
