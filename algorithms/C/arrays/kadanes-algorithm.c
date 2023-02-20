/*
Kadane's Algorithm: Largest Sum Contiguous Subarray 

Task: Find the maximum sum of the contiguous subarray.

Example 1: 
    Size: 8
    Array: {-2, -3, 4, -1, -2, 1, 5, -3}

    Here the subarray {4, -1, -2, 1, 5} has the maximum sum of 7

Time Complexity: O(N)
*/


#include<stdio.h>
#include<stdlib.h>


int max_sub_array_sum(int *array,int size)
{
    int best_sum=0,sum=0;

    for(int i=0;i<size;i++)
    {
        sum=array[i]>sum+array[i]?array[i]:sum+array[i];
        best_sum=best_sum>sum?best_sum:sum;
    }
    return best_sum;
}

int main()
{
    int *array=NULL;
    int size=0;

    printf("Enter the size of the array: ");
    scanf("%d",&size);

    array=(int*)malloc(size*sizeof(int));

    printf("Enter array elements: ");
    for(int i=0;i<size;++i)
        scanf("%d",&array[i]);

    printf("Maximum contiguous sum is %d",max_sub_array_sum(array,size));

    return 0;
}

/*
Sample Input and Output

Enter the size of the array: 8
Enter array elements: -2 -3 4 -1 -2 1 5 -3
Maximum contiguous sum is 7

*/