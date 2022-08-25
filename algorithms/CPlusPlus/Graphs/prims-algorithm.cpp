#include <bits/stdc++.h>
using namespace std;

void prims(vector<pair<int,int>> adj[], vector<int> &key, vector<int> &parent, vector<bool> &mst, int V, int E, int &ans)
{
    key[0] = 0;
    for(int count=0; count<V; count++)
    {
        int min = INT_MAX, u;
        //to find the minimum weight of edge from the key array
        for(int i=0;i<V;i++){
            if(!mst[i] && key[i] < min){
                min = key[i];
                u = i;
            }
        }
        mst[u] = true;
        ans += key[u];

        for(auto it: adj[u]){
            int v = it.first;
            int w = it.second;

            if(!mst[v] && w < key[v]){
                key[v] = w;
                parent[v] = u;
            }
        }
    }
}

int main(){
    int V,E;
    cout<<"no of vertex:"; cin>>V;
    cout<<"no of edges:"; cin>>E;

    vector<pair<int,int>> adj[V];

    int u,v,wt;
    for(int i=0; i<E; i++){
        cin>> u >> v >> wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    vector<int> key(V,INT_MAX);
    vector<int> parent(V,-1);
    vector<bool> mst(V,false);
    int ans=0;

    prims(adj,key,parent,mst,V,E,ans);
    
    cout<<ans<<endl;
    for(int i=1; i<V; i++){
        cout<<parent[i] << "-" << i << endl;
    }

    return 0;
}