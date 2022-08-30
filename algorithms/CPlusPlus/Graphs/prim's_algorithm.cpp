/*
  PREREQUISITE --> 
    1. GRAPH
    2. PRIORITY QUEUE
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> graph;
vector<bool> vis;

int primAlgorithm(){
  int totalCost = 0;
  // totalCost will store the minimum spanning tree 
  set<pair<int,int>> pq; 
  /*
    here pq -> priority queue ( it sorts all elements )
    it takes two value 
      1. weight 
      2. vertex

    Here, priority queue will be sorted according to weight     
  */


  pq.insert({0,1});
  /*
    initialising the priority queue with {0,1}
    Since, vertex 1 is the first vertex so we don't have to travel through a
    edge to reach vertex 1
  */

  while( !pq.empty() ){
    // taking the values of first elements from priority queue
    int wt = (*pq.begin()).first; // weight of first vertex in priority queue
    int v = (*pq.begin()).second; // first vertex
    pq.erase(pq.begin());

    if( vis[v] ) continue;
    // if the vertex 'v' is visited then continue and don't proceed
    vis[v] = true;
    totalCost += wt;
    // if the vertex is not visited then mark it visited
    // and add the weight to total cost


    // traverse all the child of vertex 'v'
    for( auto elem : graph[v] ){
      
      if( vis[elem.first] ) continue;

      // if child is visited then don't insert in priority queue
      // else insert in priority queue
      pq.insert({elem.second,elem.first});
    }
  }

  graph.clear(); // clearing all values in graph
  return totalCost;
}

int main()
{
  int n,e; cin>>n>>e;
  // n -> number of vertex in graph
  // e -> number of edges in graph

  // initialising the graph
  graph = vector<vector<pair<int,int>>> (n+1);

  // initialising the visited vector to false 
  // it represent if the vertex is visited or not
  vis = vector<bool>(n+1,false);


  // taking the input of 'e' edges
  for(int i=0; i<e; i++)
  {
    int a,b,wt; cin>>a>>b>>wt;
    /*
      a,b -> vertexs of graph
      wt -> weight of edge between vertex 'a' and 'b'
    */

    graph[a].push_back({b,wt});
    graph[b].push_back({a,wt});
    // it creates adjcency list by pushing all
    // the vertexs(with weight) which are directly connected by edges.
    
  }

  cout<<primAlgorithm();
    
  return 0;
}