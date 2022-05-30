// C++ code to print leaders in an array
// Description: If an element is greater than all the elements to its right, the element is a leader
// Method: From right to left in the array, scan all elements and record the maximum element until now. When the maximum element changes, print it
// Time Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

void findLeader(int a[], int len)
{
	int rmax = a[len - 1];
	cout << rmax; // The rightmost element is always a leader
	cout << endl;
	for (int i = len - 2; i >= 0; i--)
	{
		if (rmax < a[i])
		{
			rmax = a[i];
			cout << rmax;
			cout << endl;
		}
	}
}
int main()
{
	int n;
	cin >> n; // Take the size of the array as input from the user
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i]; // Take the elements of the array as input from the user
	}
	findLeader(a, n);
	return 0;
}