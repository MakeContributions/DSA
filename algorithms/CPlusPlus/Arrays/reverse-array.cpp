#include<iostream>
using namespace std ;
int reverse_array(int *arr, int n){
  
// Here we will use two pointer approach
int low = 0 ;     //First pointer at the beginning of the array
int high = n-1;  //Second pointer at the end of the array

while(low < high){
  //Swapping array items at the low and high index
  int temp = arr[low] ;
  arr[low] = arr[high];
  arr[high] =temp ;
  low++;  //Incrementing the low pointer
  high--; //Decrementing the high pointer
}
  
  for(int i = 0; i < n ; i++){
  cout<<arr[i]<<" ";
  }
  return 0 ;
}
int main(){
  int arr[]={10,5,8,20};
  reverse_array(arr,4) ; //Function call
  //Output
  // 20 8 5 10
  return 0;
}
