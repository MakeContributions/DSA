/*
Description - To print all subsets/power set of an array using bit manipulation

Approach - 	Iterate from 0 to (2^n)-1
			For each iteration, we will check the postion of set bits in its binary form  
			if i-th bit in that number is set,then we print i-th element in the array

Time complexity - O(2^n) exponential
*/

#include<iostream>
using namespace std;

// Function to print the subsets
void printallsubsets(int* arr,int n){
	int total_length = 1<<n;               //To find total number of subsets,bit left shift is used to find power of 2.
	for (int i=0;i<total_length;i++){

		int j = i;
		int p = 0;                        //This is used to track the position of set bits in the number
		while (j!=0){

			if (j&1<<0) cout<<arr[p];      //Check if last bit is set, we print the element if it is set.  
			
			j = j>>1;                     //Bit right shift 
			p++;                          
		}
		cout<<"\n";

	}

}

int main(){
									               
	int length_of_the_array = 3;	
	int arr[] = {1,2,3};                         //Integer array is used
	printallsubsets(arr,length_of_the_array);
}

/* 
Sample input-
	array = {1,2,3}
Output-
		
	1
	2
	12
	3
	13
	23
	123

*Note  - one subset is empty subset
*/

