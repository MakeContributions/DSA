// Program to find sum of digits of an integer (Decimal Integer)
// Executable link: https://ide.geeksforgeeks.org/pHHmcxVNKZ

#include <iostream>

using namespace std;

// Replace 10 by 2 for binary numbers, 8 for octal numbers
int sum_of_digits(int n) {
    if (n == 0)
        return 0;
    return (n%10 + sum_of_digits(n/10));
}

int main() {
    int numb = 12345;
    cout << "Sum of digits of " << numb << " is " << sum_of_digits(numb);
    return 0;
}
