//Description : This program reverses array elements using two pointer method.
//Time Complexity : O(n), where n is the array size
//Auxiliary Space : O(1)
#include<bits/stdc++.h>
using namespace std ;
void reverse_array(int *arr, int n){
// Here we will use two pointer approach
int low = 0 ;     //First pointer at the beginning of the array
int high = n-1;  //Second pointer at the end of the array

while(low < high){
  //Swapping array items at the low and high index
  swap(arr[low],arr[high]);
  low++;  //Incrementing the low pointer
  high--; //Decrementing the high pointer
}

  for(int i = 0; i < n ; i++){
  cout<<arr[i]<<" ";
  }
}
int main(){
  int n ; //Size of the array
  cin>>n;
  int arr[n]; //Array of size n
  for(int i = 0 ; i < n ; i++){ //Take input from the user
   cin>>arr[i];
  }
  reverse_array(arr,n) ; //Function call
  return 0;
}
