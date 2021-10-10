//Maximum difference between two elements such that larger element appears after the smaller number
//In this method we keep  track of the maximum difference found so far and the minimum value found so far.

#include <bits/stdc++.h>
using namespace std;

int maximumDifference(int a[], int n) {
	int minVal = a[0];							//Initialized minimum value with the first element of the array.
	int maxDiff = a[1] - a[0];					//Initialized maximum difference with the difference between first and second value
	for (int j = 1; j < n; ++j) {
		maxDiff = max(maxDiff, a[j] - minVal);  
		minVal = min(minVal, a[j]);
	}
	return maxDiff;
}	

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) 
		cin >> a[i];
	cout << maximumDifference(a, n);
	return 0;
}

//Time Complexity : O(n) 
//Auxiliary Space : O(1) 

//Example test case:
//Input: 2 3 10 6 4 8 1
//Output: 8
