// Check if the given graph contains a Cycle
#include <bits/stdc++.h>
using namespace std;

class Graph{
	private:
		int V;
		vector<vector<int>> E;
	public:
		Graph(int v){
			this->V = v;
			E.resize(V);
		}

		void addEdge(int x,int y){
			E[x].push_back(y);
			return;
		}

		int getVertices(){
			return V;
		}

		vector<vector<int>> getEdges(){
			return E;
		}

		void printGraph(){
			for(int i=0;i<V;i++){
				cout<<i<<" --> ";
				for(auto edge:E[i]) cout<<edge<<" ";
				cout<<endl;
			}
			return;
		}
};

bool isCyclic(vector<vector<int>> &edges, vector<bool> &visited,vector<bool> inStack, int currentVertex){
	//If current vertex is already visited and is in Stack, then there is a cycle
	if(visited[currentVertex] && inStack[currentVertex]) return true;
	
	//Else push them in visited and stack
	visited[currentVertex] = true;
	inStack[currentVertex] = true;
	
	//Traverse the neighbours
	for(auto neighbour:edges[currentVertex]){
		bool cycle = isCyclic(edges,visited,inStack,neighbour);
		if(cycle) return true;
	}
	
	// Once we have traverse this Vertex it could be removed from the Stack.
	inStack[currentVertex] = false;
	return false;
}

//This function checks for Cycle
bool cycleInGraph(Graph g) {
	int n = g.getVertices();
	vector<vector<int>> E = g.getEdges();
	vector<bool> visited(n,false); //Visited vector holds the information for Vertices that are already visited
	vector<bool> inStack(n,false); //inStack Vector holds all the Vertices which are currently in Stack
	
	//Will check each Vertex for a cyclev and if already vivsted, it will be skipped
	for(int i=0;i<n;i++){
		if(visited[i]) continue;
		bool cycle = isCyclic(E,visited,inStack,i);
		if(cycle) return true;
	}
	
  return false;
}


int main(){
	int V = 5; // Number of vertices in graph
	Graph g(V);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(4,2);
	g.addEdge(1,3);
	g.addEdge(0,1);
	g.addEdge(3,1);
	g.printGraph();  //Prints Graph

	if(cycleInGraph(g)) cout<<"Graph contains a Cycle";
	else cout<<"No Cycle Found";

	return 0;
}