/*
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.
Example 1:
Input: N = 4, arr = {1, 5, 11, 5} 
Output: YES 
Explaination: The two parts are {1, 5, 5} and {11}.
*/
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i = 0 ; i < N ; i++)
            sum += arr[i];
        if(sum % 2)
            return 0;
        sum /= 2;
        bool dp[N+1][sum+1];
        for(int i = 0 ; i <= N ; i++)
        {
            for(int j = 0 ; j <= sum ; j++)
            {
                if(j == 0)
                    dp[i][j] = 1;
                else if(i == 0)
                    dp[i][j] = 0;
                else if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[N][sum];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
