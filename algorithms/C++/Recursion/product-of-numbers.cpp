/*
Description: C++ program to find product of 2 numbers using Recursion.

Approach: Product of two numbers (x,y) can be defined as y times sum of x.
Calling the function recursively y times and adding x to it.

Time Complexity: O(n) where n is the value of y
*/

#include <bits/stdc++.h>
using namespace std;

// recursive function to calculate multiplication of two numbers
int product(int x, int y)
{
    // if x is less than
    // y swap the numbers
    if (x < y)
        return product(y, x);

    // iteratively calculate
    // y times sum of x
    else if (y != 0)
        return (x + product(x, y - 1));

    // if any of the two numbers is
    // zero return zero
    else
        return 0;
}

int main()
{
    int x = 5, y = 2;
    cout << product(x, y);
    return 0;
}

/*
Sample Input:
x=5, y=2

Output: 10

Sample Input:
x=6, y=7

Output: 42
*/