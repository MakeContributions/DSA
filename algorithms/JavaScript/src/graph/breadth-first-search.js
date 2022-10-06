// Program to print BFS traversal from a given
// source vertex. breadthFirstSearch(graph) traverses vertices
// reachable from s. for the implementation we need the queue data structure;

// Queue class
class Queue {
    // Array is used to implement a Queueƒ
    constructor() {
        this.items = [];
    }

    // enqueue function
    enqueue(element) {
        // adding element to the queue
        this.items.push(element);
    }
    // dequeue function
    dequeue() {
        // removing element from the queue
        // returns underflow when called
        // on empty queue
        if (this.isEmpty())
            return "Underflow";
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
    addVertex(v) {
        this.AdjList.set(v, []);
    }
    addEdge(v, w) {
        this.AdjList.get(v).push(w);
        this.AdjList.get(w).push(v);
    }

}
var breadthFirstSearch=(g,startingNode)=> {
    var visited = {};
    var q = new Queue();
    visited[startingNode] = true;
    q.enqueue(startingNode);
    while (!q.isEmpty()) {
        var getQueueElement = q.dequeue();
        console.log(getQueueElement);
        var get_List = g.AdjList.get(getQueueElement);
        for (var i in get_List) {
            var neigh = get_List[i];
            if (!visited[neigh]) {
                visited[neigh] = true;
                q.enqueue(neigh);
            }
        }
    }
}

var g = new Graph(6);
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

breadthFirstSearch(g,6);
//when we start bfs for the given graph from point 6 the output is as follow;
// output 6 3 1 5 2 4
