/*CPP program to remove the duplicate elements from the array in place
  without using any extra space.
  
  The time complexity of the algorithm is: O(n)
Sample Example:
Input array size: 6
Input array: 1 1 2 3 4 4
output : 1 2 3 4
*/

#include <bits/stdc++.h>
using namespace std;

// method to remove duplicate elements from array
void removeDuplicates(int arr[],int size){
	 
int newsize=size; // variable to keep the track of size of array.

for(int i=0,j=i+1;j<size;j++){

     if(arr[i]==arr[j]){
            newsize--;
        }else{
               i++;
    	       arr[i]=arr[j];
              }

        }
  // displaying the array after removing the duplicate elements.
    cout<<"The Array after removing duplicate elements are:"<<endl;
        for(int i=0;i<newsize;i++){
               cout<<arr[i]<<endl;
            }

   }


// driver program to test above methods
int main(){
	// get the size of the array
   int size;
   cout<<"Enter the size of the array"<<endl;
   cin>>size;
   // declare the array
   int arr[size];
  // storing the minimum integer value for checking of array is sorted or not
int max=-2147483647;

   // get the  sorted array from the user
   cout<<"Enter the sorted array"<<endl;
 
   for(int i=0;i<size;i++){
   	cin>>arr[i];
   	// checking if input array is sorted or not
   	if(arr[i]<max){
   		cout<<"Array not sorted";
   		return 0;
	   }else{
	   	max=arr[i];
	   }
   }
    removeDuplicates(arr,size);

}
