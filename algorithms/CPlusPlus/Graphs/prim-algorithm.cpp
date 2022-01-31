#define MAXNUMVERTICES 25
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <limits.h>
using namespace std;

struct Edge
{
    int from, to, weight;
    Edge();
    Edge(int source, int dest, int wt) : from(source), to(dest), weight(wt) {};
};

class Graph
{
private:
    int graphMatrix[MAXNUMVERTICES][MAXNUMVERTICES] = { 0 };
    set<int> vertices;
    Edge findMinEdge(set<int>& s, set<int>& v_s);

public:
    Graph() {};
    void insertEdge(int from, int to, int weight);
    void primMST();

};

void Graph::insertEdge(int from, int to, int weight)
{
    graphMatrix[to][from] = weight;
    graphMatrix[from][to] = weight;
    vertices.insert(from);
    vertices.insert(to);
}

Edge Graph::findMinEdge(set<int>& s, set<int>& v_s)
{
    Edge minEdge(-1, -1, INT_MAX);

    //Start from the vertices already in the MST
    //Find all edges that include these vertices and connect to vertices not yet in the MST
    //Out of these edges, find the one with the lowest weight (if it's 0, that means it's not in the graph at all, so don't include those 'edges')
    for (int vertex : s)
    {
        for (int i = 0; i < MAXNUMVERTICES; i++)
        {
            if (v_s.count(i) && graphMatrix[vertex][i] != 0 && graphMatrix[vertex][i] < minEdge.weight)
            {
                minEdge = Edge(vertex, i, graphMatrix[vertex][i]);
            }
        }
    }
    return minEdge;
}

void Graph::primMST()
{
    //Initialize a set s for vetices already in the MST
    //Initialize a set v_s for vertices not yet in the MST.
    //Initialize a set to keep track of the edges included in the MST
    set<int> s;
    set<int> v_s = vertices;
    set<pair<int, int>> MST;

    //Pick a source vertex to start with and move it from v_s to s
    int source = *vertices.begin();
    s.insert(source);
    v_s.erase(source);

    //While there are still vertices not included in the MST, keep adding to it.
    while (!v_s.empty())
    {
        //Find the connecting edge between v_s and s with the lowest weight
        Edge minEdge = findMinEdge(s, v_s);

        //Move the node from the minEdge from v_s to s
        //Then add that edge to the MST.
        v_s.erase(minEdge.to);
        s.insert(minEdge.to);
        MST.insert(make_pair(minEdge.from, minEdge.to));

    }

    //Print the MST
    for (pair<int, int> edge : MST)
    {
        cout << edge.first << " " << edge.second << endl;
    }

}

int main()
{
    Graph myGraph;

    int numEdges;
    cout << "Enter number of edges: ";
    cin >> numEdges;

    cout << "Enter each edge on its own line in this format" << endl;
    cout << "(from) (to) (weight)" << endl;
    while (numEdges > 0)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        myGraph.insertEdge(from, to, weight);
        numEdges--;
    }

    cout << "\nMinimum Spanning Tree (Prim's Algorithm): " << endl;
    myGraph.primMST();

}

//E is the number of edges, V is the number of vertices
//Time complexity: O(E*V)
//Space complexity: O(V) {just for the functions involved in the algorithm}

/*
Sample Input
1 2 5
1 3 25
1 4 30
1 5 10
1 6 75
2 6 50
5 2 40
4 6 10
5 6 1

Output
1 2
1 3
1 5
5 6
6 4

*/