/*
Description: A program to find sum of n natural numbers using recursion.

Time Complexity: O(n)
*/

#include <iostream>
using namespace std;

//function starts
int sumofN(int n)
{
    //base case
    if (n <= 1)
    {
        return n;
    }
    //recursive function call
    int res = sumofN(n - 1);
    //return sum
    return n + res;
}

// Driver code
int main()
{
    int n = 5;
    cout << sumofN(n);
    return 0;
}

/*
Sample Input: 5
Output: 15

Sample Input: 3
Output: 6
*/