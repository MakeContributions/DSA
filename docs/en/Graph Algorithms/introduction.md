
# Graph Algorithms:

## Introduction:

**Graph** is non-linear data structure consisting of nodes and edges. It is network of nodes(vertices) connected by edges. These edges shows relationship between the edges. Graph is used to solve real life problems.

Edges in graph can be directed edge or undirected edge.

- **Directed Edge** – In graph theory, a directional edge, also known as a directed edge or an arc, is an edge that has a direction associated with it. The direction of the edge indicates a one-way relationship between the nodes. If there is a directed edge from node A to node B, it means that there is a connection or relationship from A to B, but not necessarily from B to A. The concept of directional edges is fundamental in directed graphs, which are graphs where edges have a specific direction.

- **Undirected Edge** – An undirected edge in a graph is a connection between two nodes that does not have a specified direction. Unlike a directed edge, which has a distinct starting and ending node, an undirected edge simply represents a connection between two nodes without indicating any specific direction. In an undirected graph, the edges are typically drawn as lines connecting pairs of nodes, and the relationship between the nodes is symmetric. This means that if there is an undirected edge between nodes A and B, it implies that there is a connection from A to B as well as from B to A. The lack of directionality in undirected edges is suitable for representing symmetric relationships or connections where the order of the nodes does not matter.


Nodes/Vertices in Graph is also of two type.

- **Weighted Edge** – A weighted edge in a graph is an edge that has an associated numerical value called a “weight” or “cost”. The weights on edges can represent various metrics, depending on the application. Some reasons for weight are –
    * Time
    * Distance
    * Cost… etc
- **Unweighted Graph** – An unweighted graph in a graph is an edge that has no numerical value associated with it. So, it means there is no cost in moving from one node to another. In unweighted graph, sometimes the weight of each edge is taken 1 so sake of simplicity in calculation.

# Representations of graphs

Representations of graph is the stroing of graph data structure in physical memory (RAM) to use it.

## Graph Representation Methods

- **Adjacency List:** 
- **Adjacency Matrix:**
- **Edge List:**

# Graph Representation using Adjacency List

class Graph{
    private:
    int v;
    list<int> *l;

    public:
    Graph(int v){
        this.v = v;
        l = new list<int>[this.v];
    }

    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void printAdjacencyList{
        for(int i=0;i<v;i++){
            cout<<i<<"-->";
            for(auto nbr:l[i]){
                cout<<nbr<<",";
            }
        }
    }
}

