// 0/1 knapsack (Bottom Up or memorization) Dynamic Programming
#include <bits/stdc++.h>
using namespace std;

int knapsack(int wait[], int price[], int n, int capacity, vector<vector<int>> dp)
{
    // base condition - when the bag capacity is 0 and wait[] and price[] size is 0.
    if (n == 0 || capacity == 0)
        return 0;

    // for each call first check the table if value are present(not -1) then directly return
    if (dp[n][capacity] != -1)
        return dp[n][capacity];

    /*
    * two case here:
    * case 1: include (if wait of the element is less than the bag capacity).
    * case 2: else not include
    */
    if (wait[n - 1] <= capacity)
    {
        dp[n][capacity] = max(price[n - 1] + knapsack(wait, price, n - 1, capacity - wait[n - 1], dp),
                              knapsack(wait, price, n - 1, capacity, dp));
    }
    else
    {
        dp[n][capacity] = knapsack(wait, price, n - 1, capacity, dp);
    }

    return dp[n][capacity];
}

int main()
{
    // dp table initialized with -1
    vector<vector<int>> dp(1001, vector<int>(1001, -1));

    int n;
    cout << "Enter the no. of items" << endl;
    cin >> n;

    int wait[n];
    cout << "Enter the Wait of every items" << endl;
    for (int i = 0; i < n; i++)
        cin >> wait[i];

    int price[n];
    cout << "Enter the Price of every items" << endl;
    for (int i = 0; i < n; i++)
        cin >> price[i];

    cout << "Enter the Capacity of Knapsack" << endl;
    int capacity;
    cin >> capacity;

    // knapsack function return the maximum profit
    int max_profit = knapsack(wait, price, n, capacity, dp);
    cout << "Maximum Profit = " << max_profit << endl;

    return 0;
}

/*
Complexity Analysis:
    Time:  O(n*capacity)
    Space: O(n*capacity)
The use of 2D vector data structure for storing results of intermediate states

Test case 1:
    input:
        3           -> No. of items
        10 20 30    -> wait[]
        60 100 120  -> price[]
        50          -> capacity of knapsack
    output:
        220         -> maximum profit
*/
