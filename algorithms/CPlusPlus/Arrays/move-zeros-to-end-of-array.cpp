//Given an array of random numbers, Push all the zero’s of a given array to the end of the array.
//For example, if the given arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be changed to {1, 9, 8, 4, 2, 7, 6, 0, 0, 0, 0}.
//The order of all other elements should be same.

#include <bits/stdc++.h>
using namespace std;


void movetoend(int arr[], int n)
{
	int cnt = 0;

	// Traverse the array. If element encountered is non-zero,
    // then replace the element at index cnt
    // with this element
	for (int i = 0 ; i < n; i++)
		if (arr[i] != 0)
			arr[cnt++] = arr[i];
		
	while (cnt < n)
		arr[cnt++] = 0;

	// Now all non-zero elements have been shifted to left
	// and all zero to the right to the right
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

}


int main()
{
	int n;
	cout << "Enter the size" << endl;
	cin >> n;

	int arr[n];
	cout << "Enter the array" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int k;
	cout << "Array after moving all zeros to end is :" << endl;
	movetoend(arr, n);
	return 0;
}

/*

Sample Input:

	Enter the size
	4
	Enter the array
	1 0 9 0
	Array after moving all zeros to end is :
	1 9 0 0

**Time Complexity: O(n), n is the size of the array
**Space Complexity: O(1)

*/