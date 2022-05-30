/*
Coin Change Problem
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. 
You need to figure out the total number of ways W, in which you can make a change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.
W can be pretty large so output the answer % mod(10^9 + 7)

Input Format
Line 1 : Integer n i.e. total number of denominations
Line 2 : N integers i.e. n denomination values
Line 3 : Value V

Output Format
For each test case print the number of ways (W) % mod(10^9 +7) in new line.

Constraints:
1 <= N <= 10
1 <= V <= 5000

Approach:
1)sort the coins, this will reduce the time complexity.
2)Using every coin count the number of ways of making total value V.

Time Complexity: O(NV)
Space Complexity: O(V)

Input:
3
1 2 3
9

Output:
12
*/

#include<iostream>
#include<algorithm>
using namespace std;

const int mod = (int)1e9 + 7;

int main() {

    cout<<"Enter the total number of coin denominations: ";
    int n;
    cin >> n;
    int *coins = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    sort(coins, coins + n);

    cout<<"Enter the target value: ";
    int V;
    cin >> V;

    int dp[V + 1];
    for (int i = 0; i <= V; i++)dp[i] = 0;

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= V; j++) {
            dp[j] = (dp[j] + dp[j - coins[i]]) % mod;
        }
    }
    cout << "Total number of ways to make target value are: " << dp[V] << endl;

    return 0;
}

