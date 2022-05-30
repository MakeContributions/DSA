//Dijkstra's algorithm
//implemented in the context of a directed graph
#include <bits/stdc++.h>
using namespace std;

int dijkstra(vector<vector<pair<int,int>>>& graph, int start, int end){
    //return value(-1 if endpoint is unreachable)
    int ret=-1;

    //storing cost(distance) of each vertex, set initial value as -1
    vector<int> dist(graph.size(),-1);

    //priority queue to store traversing vertices and cost values
    //data will be stored in the format of: {cost, current vertex}
    //entry with minimum cost will always be on top
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});

    while(!pq.empty()){
        int cVertex, cCost;
        tie(cCost,cVertex) = pq.top();
        pq.pop();

        //vertex already visited with lower cost -> continue
        if(dist[cVertex]!=-1&&dist[cVertex]<=cCost)continue;
        //otherwise we update our current cost(distance)
        dist[cVertex]=cCost;

        if(cVertex==end){
            ret=cCost;
            break;
        }

        for(pair<int,int> nPair : graph[cVertex]){
            int nVertex, nCost;
            tie(nVertex,nCost) = nPair;
            if(dist[nVertex]!=-1&&dist[nVertex]<=cCost+nCost){
                //the next vertex has already been traversed with lower cost
                continue;
            }
            //otherwise we add a new entry to the priority queue
            pq.push({nCost+cCost,nVertex});
        }
    }
    return ret;
}

int main(){
    //number of vertices(V) and edges(E)
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    cout << "Enter each edge information in the format of: \n";
    cout << "(Source vertex number) (Destination vertex number) (cost)\n";
    //Adjacency list
    //data will be stored in the format of: {destination,cost}
    //with the first index as the source
    vector<vector<pair<int,int>>> graph(V+1,vector<pair<int,int>>());
    while(E--){
        int source, dest, cost;
        cin >> source >> dest >> cost;
        graph[source].push_back({dest,cost});
    }
    //starting point(start), ending point(end)
    int start, end;
    cout << "Enter the starting point: ";
    cin >> start;
    cout << "Enter the ending point: ";
    cin >> end;
    int answer = dijkstra(graph,start,end);
    if(answer==-1){
        cout << "Shortest path from " << start << " to " << end << " does not exist." << endl;
    }
    else
        cout << "The minimum cost for the shortest path is: " << answer << endl;
}
//Time complexity: O(ElogV)
//Space complexity: O(V+E)

/*
Sample Input
5
8
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
1
5

Output(minimum cost)
4
*/