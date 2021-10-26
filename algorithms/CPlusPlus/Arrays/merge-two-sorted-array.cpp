//c++ program to merge two sorted array  without using  extra space.
//sample: input
//arr1[]= 1 4 7 8 10;
//arr2[]=2 3 9;
//sample output:
//arr1[]={1,2,3,4,7}
//arr2[]={8,9,10}
//Time complexity: O(n1*m1) ,n1 is for linear traversal and m1 is for reordering.
//space complexity:O(1)
#include<bits/stdc++.h>
using namespace std;
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) 
	{
        cout << arr[i] << " ";
    }
     
    cout << endl;
}
void merge_array(int arr1[],int arr2[],int n1,int n2)
{
	for(int i=0;i<n1;i++)
	{
		// we will check the condition if the element of array1 is greater than array2, if true ,simply swap them.
		if(arr1[i]>arr2[0])
		{
			int temp=arr1[i];       /* logic for swapping the elements */ 
			arr1[i]=arr2[0];
			arr2[0]=temp;
		/*	swap(arr1[i],arr2[0]); this is stl function to swap the element*/
		// after swapping the array element we need to sort the element of second array because array is sorted.
			int key,j;
			for(int i=1;i<n2;i++)
			{
				key=arr2[i];
				j=i-1;
		     while(j>=0 && arr2[j]>key)
		     {
		     	arr2[j+1]=arr2[j];
		     	j=j-1;
			 }
				
			arr2[j+1]=key;
			}
		
		}
	}
}

int main()
{  
    //declaring a array1 and array2, 
	int arr1[100],arr2[100];
	int n1,n2,i;
	cout<<"Enter the element number of  you want in array 1 and array2"<<" ";
	cin>>n1>>n2;
	//taking user input for the array1 element and array2 element.
	cout<<"enter the element of array1"<<" ";
	for(i=0;i<n1;i++)
	{
		cin>>arr1[i];
	}
	cout<<"enter the element of array2"<<" ";
	for(i=0;i<n2;i++)
	{
		cin>>arr2[i];
	}
	//calling the merge array function.
	merge_array(arr1,arr2,n1,n2);
	//for printing the final array element.
	cout << "arr1: "; printArray(arr1, n1);
    cout << "arr2: "; printArray(arr2, n2);
    return 0;
	
}

