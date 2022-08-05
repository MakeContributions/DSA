/*
Description: Program to reverse integer using recursion
Time complexity: O(n) where n is the number of digits in the integer

*/

#include <iostream>
#include <math.h>
using namespace std;

int Rev(int n)
{
    // the following variable is static means that it is only applicable for the first call of a function.
    static long base = pow(10 , (int)log10(n) + 1); // Count how many units are there in the number.
    if(n < 10) 
        return n;
    base /= 10; // Divide the base by 10.
    return (n % 10) * base + Rev(n / 10);    // take the remainder a number and take to base units
    // Ex: 12345 will lead to 50000 in the first call.
    // and then reduce the number by 10.
}


int main(int argc, char const *argv[])
{   
    int integer = 13579;
    cout << Rev(integer);    
    return 0;
}
/*
Input: 13579
Output: 97531
*/
