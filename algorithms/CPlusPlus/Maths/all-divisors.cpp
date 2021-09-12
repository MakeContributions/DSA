//This program takes a positive integer as an input and prints all the divisors of that integer.
//The code makes use of the fact that all divisors exist in pairs.

#include <bits/stdc++.h> 
using namespace std;

void printDivisors(int n) {
	for (int i = 1; i * i < n; ++i) {
		if (n % i == 0)
			cout << i  <<  " ";
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
