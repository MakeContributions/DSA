// Program to print BFS traversal from a given source vertex s.
// breadthFirstSearch(graph, source) traverses vertices reachable from source.
// for the implementation we need the queue data structure;

// Queue class
class Queue {
  // Array is used to implement a Queue
  constructor() {
    this.items = [];
  }

  // enqueue function
  enqueue(element) {
    // adding element to the queue
    this.items.push(element);
  }
  // dequeue function
  // removing element from the queue
  // returns underflow when called
  // on empty queue
  dequeue() {
    if (this.isEmpty()) {
      return 'Underflow';
    }
    return this.items.shift();
  }
  // isEmpty function
  isEmpty() {
    // return true if the queue is empty.
    return this.items.length == 0;
  }
}


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
const breadthFirstSearch = (g, source) => {
  const visited = {};
  const q = new Queue();
  visited[source] = true;
  q.enqueue(source);

  while (!q.isEmpty()) {
    // Dequeue a vertex from queue and print it
    const getQueueElement = q.dequeue();
    console.log(getQueueElement);
    const getList = g.AdjList.get(getQueueElement);
    // Get all adjacent vertices of the dequeued
    // vertex s. If a adjacent has not been visited,
    // then mark it visited and enqueue it
    for (let i = 0; i < getList.length; i++) {
      const neigh = getList[i];
      if (!visited[neigh]) {
        visited[neigh] = true;
        q.enqueue(neigh);
      }
    }
  }
};

const g = new Graph(6);
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

breadthFirstSearch(g, 6);
// when we start bfs for the given graph from point 6 the output is as follow;
// output 6 3 1 5 2 4

// Time complexity: O(n), where n is the number of vertices in graph
// Space complexity: O(n), where n is the number of vertices in graph
