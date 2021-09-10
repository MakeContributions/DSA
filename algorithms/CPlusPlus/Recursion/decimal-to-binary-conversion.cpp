// Program to convert Decimal to Binary
// Negative numbers are expressed here as Signed magnitude representation
// Executable link: https://ide.geeksforgeeks.org/Cubhhp1jIl

#include <iostream>

using namespace std;

// Trap: Remember the limit of int in C++
// if a binary of a number exceed the limit of int, it will overflow
// Tip: Use long long (and unsigned long long) instead
unsigned long long decimalToBinary (int decimal_number) {
    if (decimal_number == 0)
        return 0;
    else
        return (decimal_number%2 + 10*decimalToBinary(decimal_number/2));
}

int main() {
    int numb = 5;
    int signed_bit = 0;
    if(numb < 0)
        signed_bit = 1;
    cout << "Binary of " << numb << " is " << signed_bit << decimalToBinary(numb);
    return 0;
}
