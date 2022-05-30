//Description : This program reverses array elements using two pointer method.
//Time Complexity : O(n), where n is the array size
//Auxiliary Space : O(1)
#include<bits/stdc++.h>
using namespace std ;
void reverse_array(vector<int> arr){
// Here we will use two pointer approach
int low = 0 ;     //First pointer at the beginning of the array
int high = arr.size()-1;  //Second pointer at the end of the array

while(low < high){
  //Swapping array items at the low and high index
  swap(arr[low],arr[high]);
  low++;  //Incrementing the low pointer
  high--; //Decrementing the high pointer
}

  for(int i = 0; i < arr.size() ; i++){
  cout<<arr[i]<<" ";
  }
}
int main(){
  int n ; //Size of the array
  cin>>n;
  int item ;
  std::vector<int> arr ;
  while(n--){
  cin>>item;
  arr.push_back(item); 
  }
  reverse_array(arr) ; //Function call
  return 0;
}
