// Given an Array which represents a linear arrangement of houses on a street ,The Integers represent the amount of money in every house.
// A Thief is planning on robbing the entire street but he can only loot houses that are not adjacent.
// Find the maximum amount of money that can be looted from the street.

#include<bits/stdc++.h>
using namespace std;
int loot(int arr[],int n){
    if(n==1) return arr[0];
    int dp[n]; //DP table to keep track of maximum amount lootable until a point
    dp[0]=arr[0];//Base case 1: at 0th index the only way to choose houses is the one house available
    dp[1]=max(arr[0],arr[1]); //Base case 2: at 1st index you can either choose the first or the second house out of the two houses
  
  for(int i=2;i<n;i++){
    //Reccurence Relation
    dp[i]=max(dp[i-1],dp[i-2]+arr[i]); //Either choose the current house to loot and add up the max loot possible until i-2nd house 
    // or consider the previous loot and discard the current house
  }
  return dp[n-1];
}
int main(){
  int n;
  cout<<"Enter the number of houses"<<endl;
  cin>>n;
  int arr[n];
  cout<<"Input the amount of loot for every house"<<endl;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout<<"The maximum possible loot"<<endl;
  cout<<loot(arr,n)<<endl;
}
