/* Problem Statement: You are given a read-only array of N
integers with values also in the range [1, N] both inclusive.
Each integer appears exactly once except A which appears twice and B which is missing.
The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

Example 1:

Input Format:  array[] = {3,1,2,5,3}

Result: {3,4)

Explanation: A = 3 , B = 4
Since 3 is appearing twice and 4 is missing

Example 2:

Input Format: array[] = {3,1,2,5,4,6,7,5}

Result: {5,8)

Explanation: A = 5 , B = 8
Since 5 is appearing twice and 8 is missing

Approach:
Since the numbers are from 1 to N in the array arr[]
Take a substitute array of size N+1 and initalize it with 0.
Traverse the given array and increase the value of substitute[arr[i]] by one .
Then again traverse the substitute array starting from index 1 to N.
If you find any index value greater than 1 that is repeating element A.
If you find any index value = 0 then that is the missing element B.

Time Complexity: O(N)
Space Complexity: O(N)

*/

#include <bits/stdc++.h>
using namespace std;

void find_dup_miss(int a[], int n)
{
    int miss, dup;
    int temp[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        temp[a[i]] += 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (temp[i] == 0)
        {
            miss = i;
        }
        if (temp[i] > 1)
        {
            dup = i;
        }
    }
    cout << "duplicate element is " << dup << " and missing number is " << miss;
}

int main()
{
    cout << "enter the value of n: ";
    int n;
    cin >> n;
    cout << "enter the array: ";
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    find_dup_miss(a, n);
    return 0;
}