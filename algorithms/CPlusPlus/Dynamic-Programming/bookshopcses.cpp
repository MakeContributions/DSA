#include<bits/stdc++.h>
using namespace std;
 
//bottom_up approach
 
void solve()
{
    int n,x;
    cin>>n>>x;
    vector<int>(price)(n+1);
    vector<int>(pages)(n+1);
   for(int i=1;i<n+1;i++) cin>>price[i];
   for(int i=1;i<n+1;i++) cin>>pages[i];
   int dp[n+1][x+1];
    for(int j=0;j<x+1;j++)
    {
        dp[0][j]=0;
    }
    for(int i=0;i<n+1;i++)
    {
        dp[i][0]=0;
    }
   for(int i=1;i<n+1;i++)
   {
   for(int j=1;j<x+1;j++)
   {
        if(price[i]<=j)
        {
            dp[i][j]=max(pages[i]+dp[i-1][j-price[i]],dp[i-1][j]);
        }
        else dp[i][j]=dp[i-1][j];
   }
    }
   cout<<dp[n][x];
}
int main()
{
    int t;
    t=1;
    while(t--)
    {
        solve();
        cout<<"\n";
    }
}