//Using Reminder-divident method via Recursion
//Time Complexity : O(logn)
//Space Complexity : O(logn) [Rcursive stack is counted]
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// function starts
bool isPowerOfTwo(int n) {
       if(n==0) return false;
        return ((n==1) || (n%2==0 && isPowerOfTwo(n/2)));//using recursive approach to check power
    }
// main starts
int main()
{
    int n;
    cin >> n;
    if(isPowerOfTwo(n)){
        return 1;
    }
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
