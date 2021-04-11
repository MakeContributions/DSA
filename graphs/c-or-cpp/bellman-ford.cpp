//Bellman Ford Algorithm
#include<bits/stdc++.h>
using namespace std;


bool bellman_ford(vector<tuple<int,int,int>>graph,int V,int s,vector<int>&dist)
{

	//no. of edges
	int n = graph.size();
	for(int i=0;i<V;i++)
	{
		dist.push_back(INT_MAX);
	}

	dist[s] = 0;

	//V-1 times relaxation of all edges is done
	for(int i=0;i<V-1;i++)
	{
		for(int j=0;j<n;j++)
		{
			int src = get<0>(graph[j]);
			int dest = get<1>(graph[j]);
			int weight = get<2>(graph[j]);

			if(dist[src]!=INT_MAX && dist[dest]>dist[src]+weight)
			{
				dist[dest] = dist[src]+weight;
			}
		}
	}

	//The algorithm works fine with negative edges but does not work with negative weight cycles
	//thus checking for any negative weight cycles...

	for(int i=0;i<n;i++)
	{
			int src = get<0>(graph[i]);
			int dest = get<1>(graph[i]);
			int weight = get<2>(graph[i]);

			if(dist[src]!=INT_MAX && dist[dest]>dist[src]+weight)
			{
				cout<<"Negative weight cycle detected..\n";
				return false;
			}
	}

	return true;

}


int main()
{
	//no. of vertices(V) & source(s)
	int V = 6, s=0;

	//graph containing all the weighted edges..
	vector<tuple<int,int,int>>graph;

	//inserting an edge with :
	//src = 0
	//dest = 1
	// weight = 10
	graph.push_back(make_tuple(0,1,10));
	graph.push_back(make_tuple(0,2,8));
	graph.push_back(make_tuple(1,4,2));
	graph.push_back(make_tuple(2,3,1));
	graph.push_back(make_tuple(3,1,-4));
	graph.push_back(make_tuple(3,4,-1));
	graph.push_back(make_tuple(4,5,-2));
	graph.push_back(make_tuple(5,1,1));

	//vector to store distances of all vertices from source(s)
	vector<int>dist;
	bool neg = bellman_ford(graph,V,s,dist);

	//if no negative weigt cycle is found...
	if(neg)
	{
		cout<<"vertex		Dist from Source\n";
		for(int i=0;i<dist.size();i++)
		{
			cout<<i<<"\t\t\t"<<dist[i]<<"\n";
		}
	}


	return 0;
}
