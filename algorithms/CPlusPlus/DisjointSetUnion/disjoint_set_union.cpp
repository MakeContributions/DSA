#include<bits/stdc++.h>
using namespace std;

const int N=1e3;
vector<int>P(N),S(N);

// create new node
void create(int u){
    P[u]=u;S[u]=1;
}
// find parent of node
int find(int u){
    if(u==P[u])return u;
    return P[u]=find(P[u]);
}
// merge 2 nodes
void merge(int u,int v){
    u=find(u);
    v=find(v);
    if(u!=v){
        if(S[u]<S[v]){
            P[u]=v;
            S[v]+=S[u];
        }else{
            P[v]=u;
            S[u]+=S[v];
        }
    }
}
