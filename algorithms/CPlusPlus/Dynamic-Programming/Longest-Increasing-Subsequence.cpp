//We are given an array arr[] , we have to find the longest increasing subsequecne ,
//Subsequence is descirbed as all elements of the subsequence are in increaseing order
// ex. arr[]=[4,6,2,8]  lis= 3 (4,6,8)
//brute force: generate all the subsequence and return the longest such subsequence
//time complexity . 2^n
//optimal approach is Dynamic Programming  time complexity O(N*N) where N is the lenght of the array
//space complexity is O(N*N)+O(N)
// code..

#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int ind, int prev,vector<vector<int>>&dp){
    if(ind==n){
        return 0;
    }
    if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];
    int nottake=0+solve(arr,n,ind+1,prev,dp);
    int take=0;
    if(prev==-1||arr[ind]>arr[prev]){
        take=1+solve(arr,n,ind+1,ind,dp);
    }
    return dp[ind][prev+1]=max(nottake,take);

}
int lis(int arr[],int n){
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    return solve(arr,n,0,-1,dp);
}
int main(){
    int arr[]={11,24,9,4,0,22,29};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"the length of longest increase subsequence is "<<lis(arr,n);
    return 0;
}
