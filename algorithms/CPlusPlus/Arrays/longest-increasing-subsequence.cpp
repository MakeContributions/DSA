// Given int array, return length of longest increasing subsequence
//     Ex. nums = [10,9,2,5,3,7,101,18] -> 4, [2,3,7,101]
//    Time: O(n^2)
//     Space: O(n)
#include <bits/stdc++.h>

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        
        int result = 1;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(result, dp[i]);
        }
        
        return result;
    }
};
