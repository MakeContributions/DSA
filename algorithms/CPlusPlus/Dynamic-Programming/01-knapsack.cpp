// 0/1 knapsack (Bottom Up or memorization) Dynamic Programming

#include <bits/stdc++.h>
using namespace std;

int dp[101][1001]; // table for storing the results of every sub-problem.

int knapsack(int wait[], int price[], int n, int capacity)
{
    // base condition - when the bag capacity is 0 and wait[] and price[] size is 0.
    if (n == 0 || capacity == 0)
        return 0;

    // for each call first check the table if value are present(not -1) then directly return
    if (dp[n][capacity] != -1)
        return dp[n][capacity];

    // two case here:
    //case 1: include (if wait of the element is less than the bag capacity).
    //case 2: else not include
    if (wait[n - 1] <= capacity)
    {
        return dp[n][capacity] = max(price[n - 1] + knapsack(wait, price, n - 1, capacity - wait[n - 1]),
                                     knapsack(wait, price, n - 1, capacity));
    }
    else
    {
        return dp[n][capacity] = knapsack(wait, price, n - 1, capacity);
    }
}

int main()
{
    // at first initialize the dp table with -1
    memset(dp, -1, sizeof(dp));

    int n;
    cin >> n;
    int wait[n];
    // input the wait array
    for (int i = 0; i < n; i++)
        cin >> wait[i];
    int price[n];
    // input the price array
    for (int i = 0; i < n; i++)
        cin >> price[i];
    // input bag capacity
    int capacity;
    cin >> capacity;

    int max_profit = knapsack(wait, price, n, capacity);
    cout << max_profit;

    return 0;
}

/*
Test case 1:
    input:
        4         -> No. of element
        1 3 4 5   -> wait[]
        1 4 5 7   -> price[]
        7         -> capacity of bag
    output:
        9         -> maximum profit
*/