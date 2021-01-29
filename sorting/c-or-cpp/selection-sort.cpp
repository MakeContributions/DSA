#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{   // length of array
	cout<<"Enter the length of array"<<endl;
	int n,temp;
	cin>>n;
	int arr[n];
	// Getting elements of array
	cout<<"Enter the elements of array"<<endl;
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		for(int j = i; j<n; j++)
		{   // comparing elements of array
			if(arr[j]<arr[i])
			{
				temp = arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}