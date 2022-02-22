#include <stdio.h>
#include <stdlib.h>


struct Node{
     int data ;
     struct Node* next ;
};

int get_max(int arr[], int n){
     int myMax = -10000 ;
     for(int i=0; i<n; i++){
          if(arr[i] > myMax){
               myMax = arr[i] ;
          }
     }
}

void swap(int *first, int *second ){
    int temp = *first ;
    *first = *second ;
    *second = temp ;
}

void insertion_sort( int arr[] , int n){

    for( int i=1 ; i<n ; i++ ){

        int j = i ;
        while( j>0 && arr[j]<arr[j-1]){
            swap( &arr[j] , &arr[j-1] ) ;
            --j ;
        }
    }
}

void bucket_sort(int arr[], int n){

     int max = get_max(arr, n) ;
     int bucket[max] ;

     for(int i=0; i<max; i++)bucket[i] = 0 ;

     for(int i=0; i<n; i++){
          bucket[arr[i]]++ ;
     }
     int j = 0 ;
     for(int i=0; i<max; i++){
          while(bucket[arr[i]]--){
               arr[j++] = i ;
          }
     }
}

int main(){

    int arr[] = {374, 42, 6, 920,825} ;
    int n = sizeof(arr)/sizeof(int) ;

    printf("Before sorting : ") ;
    for(int i=0; i<n; i++){
        printf("%d",arr[i] );
        printf(" ") ;
    }

    insertion_sort(arr, n) ;

    printf("\n\nAfter sorting : ") ;
    for(int i=0; i<n; i++){
        printf("%d",arr[i] );
        printf(" ") ;
    }

    return 0;
}
