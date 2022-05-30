/*
Description: A program to get product of digits using recursion

TIme Complexity: O(n) where n is the number of digits present in the number 
*/

#include <iostream>
using namespace std;

//function starts
int dp(int n)
{
    //base case
    //where n is a one-digit number
    if (n % 10 == n)
    {
        return n;
    }
    //recursive function call
    //at every recursive call, dividing the number by 10
    return (n % 10) * dp(n / 10);
}

//main starts
int main()
{
    int n = 333;
    cout << dp(n);
    return 0;
}

/*
Sample Input:
n=333

Output: 27

Sample Input:
n=412

Output: 8
*/