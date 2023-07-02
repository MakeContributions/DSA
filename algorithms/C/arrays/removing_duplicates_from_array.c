//This code removes duplicates from a sorted array
//For example we enter the array -:5 6 6 7 8 8
//The the output will be -: 5 6 7 8


#include <stdio.h>

void removeDuplicates(int arr[], int size){
    
    int newsize = size;//keeping track of array size
    
    for(int i=0,j=i+1;j<size;j++){
        if(arr[i]==arr[j]){
            newsize--;
        }else{
               i++;
    	       arr[i]=arr[j];
              }

        
    }
    
    printf("Array after removing the duplicate elements\n");
    for(int i=0;i<newsize;i++){
        printf("%d \n",arr[i]);
    }
}

//Driver Code
int main()
{
    int size;
    printf("Enter size of the Array \n");
    scanf("%d",&size);
    
    int arr[size];
    
    
    
    printf("Enter the sorted Array \n");
    
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
        //checking if input Array is sorted or not
        if(i!=0){
            if(arr[i]<arr[i-1]){
            printf("Array is not sorted");
            return 0;
            
        }
        else{
            printf("Sorted Array is entered");
        }
        }
    }

    removeDuplicates(arr,size);
}
