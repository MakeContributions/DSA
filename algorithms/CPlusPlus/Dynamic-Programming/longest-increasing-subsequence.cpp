/*Longest Increasing Subsequence

 Description:
 Given an integer array nums, return the length of the longest strictly increasing subsequence.
 A subsequence is a sequence that can be derived from an array by deleting some or no elements
 without changing the order of the remaining elements.

 For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].


Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

*/

#include <bits/stdc++.h> //importing all necessary header files
using namespace std;

int lengthOfLIS(vector<int> &nums) // function returning the length of LIS.
{
    int n = nums.size();
    vector<int> dp(n, 1);

    for (int i = 0; i < n; ++i) // iterating i for all the index from 0 to the n-1.
    {
        for (int j = 0; j < i; ++j) // iterating j to all values less than i
        {
            if (nums[i] > nums[j]) // if the value at j is less than value at i
            {
                dp[i] = max(dp[i], 1 + dp[j]); // then store the max of value of dp[i] and 1+dp[j]
            }
        }
    }
    return *max_element(dp.begin(), dp.end()); // using max_element stl function to return max value
                                               //  in the dp vector and finallly returning it.
}

int main()
{
    int n;
    cout << "Enter the total number of elements : " << endl;
    cin >> n; // Taking the input for size of array
    cout << endl;

    vector<int> nums(n); // Created a vector of size n

    cout << "Enter the elements : " << endl;
    for (int i = 0; i < n; i++)
        cin >> nums[i]; // Taking the input for vector;
    
    cout<<endl;
    cout << "The Length of Longest Increasing Subsequence in the given array is :" << endl;
    cout << lengthOfLIS(nums) << endl; // Calling the function lengthOfLIS and passing nums as arguement.

    return 0;
}



//Time Complexity : O(n^2)