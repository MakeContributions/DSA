/*
Description: A program to segregate the array of 0s and 1s

Approach: Counting the number of 0s present in the array and saving it in variable z. For the first z indexes, putting 0 and for the remaining indexes putting 1.

Time complexity: O(n)
*/

#include <iostream>
using namespace std;

void segregate0and1(int arr[], int n) {
    
    int z=0;
    for(int i=0;i<n;i++){
      //counting the number of 0s and storing it the variable z
      if(arr[i]==0){
        z++;
      }
    }
    //for z indexes, putting 0 in the array
    //for remaining indexes putting 1 in the array
    for(int j=0;j<n;j++){
      if(j<z){
        arr[j]=0;
      }
      else{
        arr[j]=1;
      }
    }       
}
int main() {
    cout << "Enter number of elements in array: \n";
    int n;
    cin>>n;

    cout<<"Enter the array elements (only 0 and 1)\n";
    int arr[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    //calling the function
    segregate0and1(arr,n);
    cout<<"After segregating, the array is: \n";
    for(int j=0;j<n;j++){
      cout<<arr[j]<<" ";
    }
}
