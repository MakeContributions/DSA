/*
Description: Program to reverse integer using recursion
Time complexity: O(n) where n is the number of digits in the integer
*/

#include <cmath>
#include <iostream>
using namespace std;

int Helper(int n ,int base , int ans)
{
    if(n < 1)
        return ans;
    ans = ans * base + (n % 10);    // Update the ans for every digit
    return Helper(n / 10, base , ans);    
}

int Rev(int n)
{
    return Helper(n , 10, 0);
}


int main(int argc, char const *argv[])
{   
    cout << Rev(13579);

    return 0;
}
/*
Input: 13579
Output: 97531
*/

