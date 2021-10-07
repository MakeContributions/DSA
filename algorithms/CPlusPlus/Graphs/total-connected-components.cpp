//find total number of Connected Components in a graph
//implementation of dsu
#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
ll find(ll x,vector<ll>&p)
{
    if(p[x]==x)
    return x;
    else
    return p[x]=find(p[x],p);
}
void merge(ll a,ll b,vector<ll>&r,vector<ll>&p)
{
    ll s1=find(a,p);
    ll s2=find(b,p);
    if(s1!=s2)
    {
        if(r[s1]<r[s2])
        {
            p[s1]=s2;
            r[s2]+=r[s1];
        }
        else
        {
            p[s2]=s1;
            r[s1]+=r[s2];
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;//enter the number of vertices and number of edges
    vector<ll>r(n,0);
    vector<ll>p;
    for(int i=0;i<n;i++)
    {
        p.push_back(i);
    }
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        merge(u,v,r,p);
    }
    map<ll,ll>mp;
    for(int i=0;i<n;i++)
    {
       ll x=find(i,p);
        mp[x]++;
    }
    cout<<"Total Number of Connected Components are - ";
    cout<<mp.size();
    return 0;
}
//INPUT
//5 3
//1 2
//2 3
//4 5
//OUTPUT
//Total Number of Connected Components are - 2
//TIME COMPLEXITY OF THE PROGRAM
//O(V+E)
//where V is number of vertices
//E is number of edges
