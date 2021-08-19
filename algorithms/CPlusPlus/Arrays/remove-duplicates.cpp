/*CPP program to remove the duplicates elements from the array in place
  without using any extra space with o(1) extra memory 
  Its impossible to resize the array in c++,(The only way possible is to allocate 
  a new array copy the required values and delete the first one. and the requirement of given problem
  was not to use any extra space so we are just displaying array upto which last element
  is stored(virtually) after removing those duplicate elements.
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