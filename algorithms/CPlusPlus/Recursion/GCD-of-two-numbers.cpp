// Program to find GCD of two numbers using recursion
// Executable link: https://ide.geeksforgeeks.org/0ie6920wBA

#include <iostream>

using namespace std;

// Also known as Euclidean algorithm
// There exists an inbuilt function for gcd also __gcd(T a, T b) with Template T
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

int main() {
    int n1 = 56, n2 = 65;
    cout << "GCD of " << n1 << " and " << n2 << " is " << gcd(n1, n2); 
	return 0;
}
