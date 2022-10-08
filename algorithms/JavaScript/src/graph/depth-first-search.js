class Graph {
  // defining vertex array and
  // adjacent list
  constructor(noOfVertices) {
    this.noOfVertices = noOfVertices;
    this.AdjList = new Map();
  }
  // add the requeired vertex in the graph
  addVertex(v) {
    this.AdjList.set(v, []);
  }
  // addition of edges in the graph as the added edge are bidirectional
  addEdge(v, w) {
    this.AdjList.get(v).push(w);
    this.AdjList.get(w).push(v);
  }
}

// Recursive function which process and explore
// all the adjacent vertex of the vertex with which it is called

const depthFirstSearch = (g, currVertex, visited) => {
  visited[currVertex] = true;
  console.log(currVertex);

  const getNeighbours = g.AdjList.get(currVertex);
  // Recursive call for the non visited vertex
  for (let i = 0; i < getNeighbours.length; i++) {
    const getElement = getNeighbours[i];
    if (!visited[getElement]) {
      depthFirstSearch(g, getElement, visited);
    }
  }
};

const g = new Graph(6);
const visited = {};
// adding vertices
for (let i = 1; i <= 6; i++) {
  g.addVertex(i);
}
g.addEdge(1, 2);
g.addEdge(2, 4);
g.addEdge(3, 1);
g.addEdge(1, 4);
g.addEdge(5, 3);
g.addEdge(6, 3);

depthFirstSearch(g, 6, visited);
// for the given graph when we explore it from vertex 6 the output is as follow;
// output 6 3 1 2 4 5

// TIME COMPLEXITY OF THE PROGRAM
// O(V+E)
// where V is number of vertices
// and E is number of edges
