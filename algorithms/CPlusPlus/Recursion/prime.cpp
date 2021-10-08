/*
Problem: Check if a given number is prime or not, using Recursion
*/

#include <bits/stdc++.h>
using namespace std;
 
// primeCheck is function that check whether the given number is prime or not and,
// return true if prime else 
// return false  

bool primeCheck(int n, int i)
{
    // Base cases
    if(n <= 2){ 
        // 2 is a prime
        if(n == 2){
            return true;
        }

        // 0 and 1 are not prime
        return false;
    }

    // if i divides n then n is not prime
    if(n % i == 0){
        return false;
    }

    if(i * i > n){
        return true;
    }
 
    // Check for next possible divisor
    return primeCheck(n, i + 1);
}
 
// Main
int main()
{
    int n;
    cin >> n;

    //check and output
    if (primeCheck(n, 2))
        cout << "YES" <<endl;
    else
        cout << "NO" <<endl;
 
    return 0;
}

/*
Time Complexity : O(sqrt(n))
*/

/*
Input
5
Output
YES

Input 
10
Output
NO

Input 
33
Output
NO
*/