#include <iostream>
using namespace std;

// function starts
bool isPowerOfTwo(const int n)
{
    // declare a variable to know if n is a power of 2 or not
    long i = 1;
    // at every iteration it will calcalute power of 2 starting from 1
    while (i < n)
    {
        i = i * 2;
    }
    // if n is the power of 2, i and n value will be same
    // if they are same, it will return true, else it will return false
    return i == n;
}

// Binary Method to check number is in power of two or not.
// Time Complexity of this method is O(1)
bool ispoweroftwo(const int n)
{
    // if number is in power of two it will give 0, otherwise it will not zero.
    return n != 0 && (n & (n - 1)) == 0;
}

// main starts
int main()
{
    int n;
    cin >> n;
    cout << isPowerOfTwo(n) << endl;
    // Check using Binary Method
    cout << ispoweroftwo(n) << endl;
    return 0;
}

/*
Example 1:

Input: n = 1
Output:1 (true)
Explanation: 2^0 = 1

Example 2:

Input: n = 16
Output:1 (true)
Explanation: 2^4 = 16

Example 3:

Input: n = 3
Output: 0 (false)
*/
