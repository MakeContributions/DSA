//Given an integer array nums, return the length of the longest strictly increasing subsequence
//NOTE: A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
// Input : 8 [10,9,2,5,3,7,101,18]
// Output : 4 
// Explanation: The longest increasing subsqeuence is of length 4.
//Program using Dynamic Programming
//TIME COMPLEXITY: O(N^2) 
//Complete Explanation : "https://www.youtube.com/watch?v=cjWnW0hdF1Y"
#include <bits/stdc++.h>
int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        int ans=0;
        for(int i=0;i<n;i++){
           //Base case LIS is of length 1 for every element
           dp[i]=1;
           for(int j=0;j<i;j++){
            //We check previous elements and check if its smaller if it is we use its dp value
               if(nums[j]<nums[i]){
                    //We compare the Lis upto previous jth element and save it if its bigger
                   dp[i]=max(dp[i],dp[j]+1);
               }
           }
           ans=max(ans,dp[i]);
       }
       return ans;
    }
int main(){
    int len;
    cout << "Enter the array length :";
    cin >> len;
    //Taking inputs and making array/vecor
    vector<int> nums(len);
    for (int i = 1; i <= len; i++)
    {
        cout << "Enter next number " << i << " :";
        cin >> prices[i - 1];
    }

    cout << "longest increasing subsqeuence is of length = " << lengthOfLIS(nums);
    return 0;

}