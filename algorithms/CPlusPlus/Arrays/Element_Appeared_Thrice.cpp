#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    int res=-1;
    for(int i=0;i<n;i++)
    {
        if(mp[a[i]]==3)
        {
            res=a[i];
            break;
        }
    }
    cout<<res;
    return 0;
}