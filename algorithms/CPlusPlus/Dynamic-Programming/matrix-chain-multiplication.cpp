// Matrix Chain Multiplicatin - Memorization-Approuch

#include <bits/stdc++.h>
using namespace std;

// Function for matrix chain multiplication
int matrixChainMulti(vector<int> &arr, const int i, const int j, vector<vector<int>> &dp)
{
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int countMin = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp_ans = matrixChainMulti(arr, i, k, dp) + matrixChainMulti(arr, k + 1, j, dp) + (arr[i - 1] * arr[k] * arr[j]);
        if (temp_ans < countMin)
            countMin = temp_ans;
    }
    return dp[i][j] = countMin;
}

// Driver Code
int main()
{
    // dp table initialized with -1
    vector<vector<int>> dp(1001, vector<int>(1001, -1));

    int n;
    cout << "Enter the array size." << endl;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter all the array elements." << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Minimum number of multiplications is" << endl;
    cout << matrixChainMulti(arr, 1, n - 1, dp) << endl;
}

/*
 * Time Complexity: O(N^3)
 * Auxiliary Space: O(N^2)

 * Input:
 *  n = 4
 *  arr = {10, 30, 5, 60}
 *  Output: 4500
 * Explanation: The matrices have dimensions 
 * 10*30, 30*5, 5*60. Say the matrices are A, B 
 * and C. Out of all possible combinations,the
 * most efficient way is (A*B)*C. The 
 * number of multiplications are: 10*30*5 + 10*5*60 = 4500.
 */
