// Program to find GCD of two numbers using recursion
// Executable link: https://ide.geeksforgeeks.org/wixyiKNFMi

#include <iostream>

using namespace std;

// Also known as Euclidean algorithm
// There exists an inbuilt function for gcd also __gcd(T a, T b) with Template T
int euclidean_gcd(int a, int b) {
    if (b == 0)
        return a;
    return euclidean_gcd(b, a%b);
}

int main() {
    int n1 = 56, n2 = 65;
    cout << "GCD of " << n1 << " and " << n2 << " is " << euclidean_gcd(n1, n2); 
	return 0;
}
