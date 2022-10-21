// Counting sort is a stable Sorting Algorithm
#include<stdio.h>
 
void countSort(int a[],int n,int key)
{
     int count[50]={0};  // assigning all elements as zero
     int i,j;
    
     for(i=0;i<n;++i)
      count[a[i]]=count[a[i]]+1;  // increasing value of index(elements of array given) of count array

     printf("Sorted elements after applying Counting sort:");
    
     for(i=0;i<=key;++i)
      for(j=1;j<=count[i];++j)
       printf("%d ",i);
}
 
int main()
{
    int a[40],n,i,key=0;
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("\nEnter elements in array:");
       // finding the masimum elements from the array 
       // to declare it as size of count array
    for(i=0;i<n;++i)
    {
     scanf("%d",&a[i]);
     if(a[i]>key)
      key=a[i];
    }
    // calling counting sort
    countSort(a,n, key);
    return 0;
}
