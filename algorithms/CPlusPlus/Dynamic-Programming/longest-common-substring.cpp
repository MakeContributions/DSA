//Given two strings ‘s1’ and ‘s2’, find the length of the longest common substring.
//NOTE: A substring is a contiguous part of string.
// Input : X = “abcdxyz”, y = “xyzabcd” 
// Output : 4 
// Explanation: The longest common substring is “abcd” and is of length 4.

//Program using Dynamic Programming
//TIME COMPLEXITY: O(m*n) 
#include <iostream>
using namespace std;
int longestCommonSubstring(string s1,string s2,int n,int m)
{
  int ans=0;
  int T[n+1][m+1];
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=m;j++)
    {
      if(i==0 || j==0) // if length of any of the string is 0 then the length of longest common substring will be 0 
      T[i][j]=0;
      else
      if(s1[i-1]==s2[j-1]) // if characters are equal, add 1 and update the answer according to maximum length
      {
        T[i][j]=1+T[i-1][j-1];
        ans=max(ans,T[i][j]);
      }
      else//if characters are not equal, make the current value in the array as 0
      T[i][j]=0;
    }
  }
  return ans;
}
int main()
{
  string s1,s2;
  cout<<"Enter 1st string: "<<endl;
  cin>>s1;
  cout<<"Enter 2nd string: "<<endl;
  cin>>s2;
  int n=s1.length();
  int m=s2.length();
  cout<<"Length of longest common substring: "<<longestCommonSubstring(s1,s2,n,m);
  return 0;
}

// s1: abcde
// s2:abfce
// output: 2(ab)
