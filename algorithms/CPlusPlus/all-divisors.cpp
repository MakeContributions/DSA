//all-divisors
//The following code takes a positive integer a an input and prints all of its divisors.
//This code makes use of the fact that all the divisors are present in pairs. This fact could speed up the program significantly.

#include <bits/stdc++.h>
using namespace std;

void printDivisors(int n) {
	for (int i = 1; i * i < n; ++i) {
		if (n % i == 0)				
			cout << i << " ";	    
	}
	for (int i = sqrt(n); i >= 1; --i) {
		if (n % i == 0)				
			cout << n / i << " ";
	}
}

int main() {
	int n;
	cin >> n;
	printDivisors(n);
	return 0;
}

//Time Complexity: O(sqrt(n))
//Auxiliary Space: O(1)

//Example Test Case:
//Input: 10
//Output: 1 2 5 10
