//Maximum difference between two elements such that larger element appears after the smaller number
//In this method we keep  track of the maximum difference found so far and the minimum value found so far.

#include <bits/stdc++.h>
using namespace std;

int maximumDifference(int a[], int n) {
	int minVal = INT_MAX;							//Initialized minimum value with the max no
	int ans = INT_MIN;					//Initialized maximum difference with min value
	for (int j = 0; j < n; ++j) {
		//maxDiff = max(maxDiff, a[j] - minVal);  
		minVal = min(minVal, a[j]); // extracting the min value upto index j
		ans = max(ans , a[j] - minVal); // max difference with each passing index
	}
	return ans;
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
