
class Graph {
    // defining vertex array and
    // adjacent list
    constructor(noOfVertices) {
        this.noOfVertices = noOfVertices;
        this.AdjList = new Map();
    }
    addVertex(v) {
        this.AdjList.set(v, []);
    }
    addEdge(v, w) {
        this.AdjList.get(v).push(w);
        this.AdjList.get(w).push(v);
    } 
}
 // Recursive function which process and explore
 // all the adjacent vertex of the vertex with which it is called

var depthFirstSearch =(g,curr_vertex, visited) =>{
    visited[curr_vertex] = true;
    console.log(curr_vertex);

    var get_neighbours = g.AdjList.get(curr_vertex);

    for (var i in get_neighbours) {
        var get_elem = get_neighbours[i];
        if (!visited[get_elem])
            depthFirstSearch(g,get_elem, visited);
    }
}

var g = new Graph(6);
var visited = {};
// adding vertices
for (var i = 1; i <= 6; i++) {
    g.addVertex(i);
}
g.addEdge(1, 2);
g.addEdge(2, 4);
g.addEdge(3, 1);
g.addEdge(1, 4);
g.addEdge(5, 3);
g.addEdge(6, 3);

depthFirstSearch(g,6,visited);
//for the given graph the output is as follow;
// output 6 3 1 2 4 5
