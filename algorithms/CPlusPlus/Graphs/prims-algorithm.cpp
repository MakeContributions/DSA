/*
APPROACH: We will have 3 arrays(key, mst and parent). 

    Significance of all three arrays:-
    -> Key : This array holds the weight/ cost of the MST.
    -> MST : This is a boolean array which indicates whether a node is already a part of MST or not.
    -> Parent :  This indicates the parent of a particular node in the MST(initialized to -1)

STEPS:-
    -> Assuming we start with node 0, the index 0 in the key array is initialized to zero(because it is the first node in the MST).
       We find the index/node in the key array which has the minimum weight. We then find all its adjacent edges and pickup the the 
       one with minimum weight. 

    -> Also at the same time we mark this node as true(indicating that it is now a part of the MST) and also set it’s parent as node ‘0’. 

    -> After this, we would continue to find the one with minimum weight in the key array that is not a part of the MST(Notice that 
       this is where we ensure that we pickup the node with minimum weight and we do not choose an edge that might cause a cycle)

    -> We continue this process until all nodes become a part of the MST
*/

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