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
