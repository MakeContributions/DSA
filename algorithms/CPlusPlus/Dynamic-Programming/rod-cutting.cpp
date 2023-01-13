// Rod Cutting Problem
// Given a rod of length n and a list of rod prices of length i, where 1 <= i <= n, find the optimal way to cut the rod into smaller rods to maximize profit.

// Rod Cutting Optimal Approach
//     We will solve this problem in a bottom-up manner. (iteratively)  
//     In the bottom-up approach, we solve smaller subproblems first, then move on to larger subproblems.  
//     The following bottom-up approach computes dp[i], which stores maximum profit achieved from the rod of length i from 1 to len. 
//     It uses the value of smaller values i already computed.

// Space complexity: O(n)
// Time complexity: O(n^n)


// Solution
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the maximum revenue from cutting a rod of length (len)
// where the rod of length (i) has cost (prices[i - 1])
int RodCutting(vector<int> &prices, int len)
{
    // (dp) stores the maximum revenue achieved from cutting a rod of length (from 1 to len)
    vector<int> dp(len + 1, 0);
    // If the rod length is negative (invalid) or zero there's no revenue from it
    if (len <= 0)
    {
        return 0;
    }
    // Cut a rod of length (i)
    for (int i = 1; i <= len; i++)
    {
        // divide the rod of length (i) into two rods of lengths (j) and (i - j)
        // and store the maximum revenue
        for (int j = 0; j < i; j++)
        {
            // (dp[i]) stores the maximum revenue achieved from cutting a rod of length (i)
            dp[i] = max(dp[i], prices[j] + dp[i - j - 1]);
        }
    }
    // (dp[len]) contains the maximum revenue from cutting a rod of length (len)
    return dp[len];
}

int main()
{
    int len;
    cout << "Enter the rod length :";
    cin >> len;

    vector<int> prices(len);
    for (int i = 1; i <= len; i++)
    {
        cout << "Enter the price of the rod of length " << i << " :";
        cin >> prices[i - 1];
    }

    cout << "Maximum revenue = " << RodCutting(prices, len);
    return 0;
}


// Input and output:
// 1. prices[] = [1, 5, 8, 9, 10, 17, 17, 20]  
//        rod length = 4  
//        Best: Cut the rod into two pieces of length 2 each to gain revenue of 5 + 5 = 10
       
//     2. prices[] = [1, 5, 8, 9, 10, 17, 17, 20]
//        rod length = 8
//        Best: Cut the rod into two pieces of length 2 and 6 to gain revenue of 5 + 17 = 22
       
//     3. prices[] = [3, 5, 8, 9, 10, 17, 17, 20]
//        rod length = 8
//        Best: Cut the rod into eight pieces of length 1 to gain revenue of 8 * 3 = 24
