//dfs traversal of undirected graph using stack approach
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;//enter the number of vertices and number of edges
    vector<vector<int>>adj(n+1,vector<int>());
    //create an adjacency list according to the edges given in input
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"The dfs traversal is \n";
    vector<int>v(n+1,0);
    stack<int>s;
    s.push(1);
    while(!s.empty())
    {
        int t=s.top();
        if(!v[t])
        {
           v[t]=1;//mark the vertex as visited
           cout<<t<<" ";//print the vertex you visited
        }   
        s.pop();
        for(int i=0;i<adj[t].size();i++)
        {
            if(!v[adj[t][i]])
            {
                s.push(adj[t][i]);//if a vertex is not visited push it in stack
            }
        }
    }
    return 0;
}
//INPUT
//6 5
//1 2 
//2 6 
//1 3 
//3 4 
//3 5 
//OUTPUT
//The dfs traversal is 
//1 3 5 4 2 6 
//TIME COMPLEXITY OF THE PROGRAM
//O(V+E)
//where V is number of vertices
//E is number of edges
