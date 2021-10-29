// Non-recursive Program to find GCD of two numbers 

#include <iostream>

using namespace std;

// Also known as Euclidean algorithm
// There exists an inbuilt function for gcd also __gcd(T a, T b) with Template T
int non_rec_gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
int main() {
    int n1 = 56, n2 = 65;
    cout << "GCD of " << n1 << " and " << n2 << " is " << non_rec_gcd(n1, n2); 
	return 0;
}

