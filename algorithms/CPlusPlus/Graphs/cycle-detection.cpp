// Program to detect whether a graph contains a cycle. The vertices of the graph are
// placed in disjoint sets. As each edge is iterated through, the subset of the two
// vertices is determined. If the subsets are the same, then a cycle is found.
// Otherwise, the algorithm will join the two subsets together and repeat the process
// until each edge is iterated through or a cycle is found.
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
    int findSet(std::vector<int>& parent, int i);
    void unionSet(std::vector<int>& parent, int x, int y);                                          
};

void Graph::insertEdge(int from, int to)
{
    edgeList.push_back(std::make_pair(from, to));
    uniqueVertices.insert(from);
    uniqueVertices.insert(to);
}

bool Graph::isCycle()
{
    // Initialize parent vector as disjoint sets
    std::vector<int> parent(uniqueVertices.size(), -1);
    
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

    return false;
}

int Graph::findSet(std::vector<int>& parent, int i)
{
    if (parent[i] == -1)
    {
        return i;
    }
    return findSet(parent, parent[i]);
}

void Graph::unionSet(std::vector<int>& parent, int x, int y)
{
    parent[x] = y;
}

// Sample test case
// Time complexity is O(E) where E is the number of edges
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
