// Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.
// Executable link : https://ide.geeksforgeeks.org/e3ce1154-9585-44aa-8f4b-d499dc64f9cc

#include <bits/stdc++.h>
using namespace std ;
int solve(string s1, string s2, int ans, int i = 0, int j = 0){
    if(i == s1.length() || j == s2.length()){
        return ans;
    }
    // Match case
    if(s1[i] == s2[j]){
        ans = 1 + solve(s1, s2,ans,i + 1, j+1);
    }

    // Not match
    else{
        ans = max(solve(s1, s2,ans,i, j+1), solve(s1, s2,ans,i + 1, j));
    }
    return ans;
}
int main()
{
    string s1 = "abcde";
    string s2 = "abcde";
    cout<< solve(s1, s2, 0)<<endl;
    return 0;
}
