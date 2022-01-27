#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <vector>

// Edge list implementation of unweighted, undirected graph
class Graph
{
    private:
    std::vector<std::pair<int, int>> edgeList;
    std::unordered_set<int> uniqueVertices;  // Keep track of the number of unique vertices
    
    public:                                                                                
    void insertEdge(int from, int to);
    bool isCycle();
    int findSet(int parent[], int i);
    int unionSet(int parent[], int x, int y);                                          
};

void Graph::insertEdge(int from, int to)
{
    edgeList.push_back(std::make_pair(from, to));
    uniqueVertices.insert(from);
    uniqueVertices.insert(to);
}

bool Graph::isCycle()
{
    // Initialize parent array as disjoint sets
    int* parent = new int[uniqueVertices.size()];
    std::fill(parent, parent + uniqueVertices.size(), -1);
    
    // Iterate through all graph edges
    for (auto i : edgeList)
    {
        // Find the subset of both vertices of an edge
        int x = findSet(parent, i.first);
        int y = findSet(parent, i.second);

        // If the subsets are the same, then there is a cycle in the graph
        if (x == y)
        {
            return true;
        }

        unionSet(parent, x, y);
    }
    
    delete parent;
    return false;
}

int Graph::findSet(int parent[], int i)
{
    if (parent[i] == -1)
    {
        return i;
    }
    return findSet(parent, parent[i]);
}

int Graph::unionSet(int parent[], int x, int y)
{
    parent[x] = y;
}

int main()
{
    Graph graph;
    graph.insertEdge(0, 1);
    graph.insertEdge(0, 2);
    graph.insertEdge(1, 2);
    if (graph.isCycle())
    {
        std::cout << "Graph contains a cycle" << std::endl;
    }
    else{
        std::cout << "Graph does not contain a cycle" << std::endl;
    }
    return 0;
}
