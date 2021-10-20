/* 
Binary Exponentiation 

Approach:

a^n     =   1 , if n==0
        =   (a^(n/2))^2, if n is even
        =   (a*(a^(n-1/2))^2), if n is odd

*/

#include <iostream>
using namespace std;

// implementation

long long pow(long long a, long long n)
{
    //base case
    if (n == 0) // n is zero then any positive number raised to zero is equal to 1
    {
        return 1;
    }
    // storing the sub-case
    long long p = pow(a, n / 2);

    //recursive case
    if (n % 2 == 0) // n is even so n can be represented as (n/2)*2
    {
        return p * p;
    }
    // n is odd so taking out the one a results in n to be even now using the same previous info
    else
    {
        return p * p * a;
    }
}

int main()
{
    long long a, n; // defining two intergers
    cin >> a >> n;  // taking input from the user

    cout << pow(a, n); // printing the result by calling the function
    return 0;
}
/* 
Time Complexity : O(log n)

Sample Input : 2 32
Sample Output : 4294967296
*/