//Second largest element in the array

#include<stdio.h>
#include<stdlib.h>

int second(int arr[],int size)
{
    int max1=arr[0],max2;
    for(int i=0;i<size;i++)
    {
        if(arr[i]>max1) //Find largest element in the array
        {
            max2=max1;
            max1=arr[i];
        }
        else if (arr[i]>max2 && arr[i]<max1) // Find second largest element in the array
        {
            max2=arr[i];
        }
    }
        printf("%d %d",max1,max2); // Print both first and second largest element in the array
}

int main()
{
    int arr[]={2,5,1,12,18,88,23,45,4}; // Initialize array
    int size=sizeof(arr)/sizeof(int); // Calculate array size
    second(arr,size);
    return 0;
}

/*
----------------Sample Output----------------
> 88 45

Time Compexity: O(n)
Space compexity: O(1)
*/
