//bubble sort 
# include <iostream>
using namespace std;

int main()
{
	cout<<"Enter the length of array"<<endl;
	int m, temp,n;
	cin>>n;
	int arr[n];
	cout<<"Enter the elements of array"<<endl;
	for (int i = 0; i < n; i++)
	{    //array elements input
		cin>>arr[i];
	}
	bool swap;
	for (int i = 0; i < n; i++)
	{
		swap = false;
		for (int j= 0; j< n-1; j++)
		{    //comparing adjecent elements of array
			if (arr[j]>arr[j+1])
			{   // swapping array elements
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				swap = true;
			}
		}

		// break if no swap takes place in inner loop
		// it means the array is sorted 
		if(!swap){ break; }
	}
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
