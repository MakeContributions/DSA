#include <iostream>
using namespace std;

//function starts
bool isPowerOfTwo(const n)
{
    //declare a variable to know if n is a power of 2 or not
    long i = 1;
    //at every iteration it will calcalute power of 2 starting from 1
    while (i < n)
    {
        i = i * 2;
    }
    //if n is the power of 2, i and n value will be same
    //if they are same, it will return true, else it will return false
    return i == n;
}

//main starts
int main()
{
    int n;
    cin >> n;
    cout << isPowerOfTwo(n);
    return 0;
}

/*
Example 1:

Input: n = 1
Output:1 (true) 
Explanation: 20 = 1
Example 2:

Input: n = 16
Output:1 (true) 
Explanation: 24 = 16
Example 3:

Input: n = 3
Output: 0 (false)
*/
