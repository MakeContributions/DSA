/**
Approach-
It starts by initializing three arrays, parent, key, and inMST.
The parent array is used to store the parent of each vertex in the MST.
The key array is used to store the minimum weight edge required to reach that vertex.
The inMST array is used to keep track of whether a vertex is in the MST or not.
A priority queue (pq) is used to keep track of vertices and their key values. The priority queue is ordered based on the key values of the vertices.
The algorithm starts with an arbitrary node (vertex 0 in this case) and adds it to the priority queue with key value 0.
The main loop continues until the pririty queue is empty, and in each iteration, the algo extracts the vertex with the minimum key value from the priority queue.
For each neighbor of the extracted vertex that is not yet in the MST and has lower key value, the algo updates its key value and parent in the parent array.
*/

/* 
Time complexity -
Time Complexity: O(E log V)
The main operations contributing to the time complexity are the priority queue operations inside the main loop
In the worst case, each edge is considered once, and the priority queue operations take O(log V) time, where V is the number of vertices

Auxiliary Space: O(V + V + V + V) = O(V)
*/

import java.util.*;

public class Prims {
	public int[] prims(List<List<Node>> adjList) {
		int[] parent = new int[adjList.size()];
		int[] key = new int[adjList.size()];
		boolean[] inMST = new boolean[adjList.size()];

		Arrays.fill(key, Integer.MAX_VALUE);
		Arrays.fill(inMST, false);

		PriorityQueue<Node> pq = new PriorityQueue<>(adjList.size(), new NodeComparator());
		pq.add(new Node(0, 0));
		key[0] = 0;	// starting vertex

		while (!pq.isEmpty()) {
			Node curr = pq.poll(); // current nde
			inMST[curr.vertex] = true;

			for (Node n : adjList.get(curr.vertex)) {
				if (!inMST[n.vertex] && key[n.vertex] > n.key) {
					parent[n.vertex] = curr.vertex;
					key[n.vertex] = n.key;
					pq.add(new Node(n.vertex, n.key));
				}
			}
		}

		return parent;
	}

	public static void main(String[] args) {
        /*
           SAMPLE INPUT AND OUTPUT
           ___________________________

           Input:
           __________
           Please enter the number of nodes N. Vertices will be [0, N-1]
           6
           Please Enter the number of Edges
           9
           Please enter each edge in the sequence <starting node> <destination node> <weight>
           0 1 1
           0 2 5
           1 2 2
           1 4 1
           1 3 2
           2 4 2
           3 5 1
           3 4 3
           4 5 2
           Output:
           _____________
           Minimum Spanning Tree:
           Edge: 0 - 1, Weight: 1
           Edge: 1 - 4, Weight: 1
           Edge: 2 - 1, Weight: 2
           Edge: 3 - 5, Weight: 1
           Edge: 4 - 2, Weight: 2
         */

		 List<List<Node>> adjList = new ArrayList<>();

		 System.out.println("Please enter the number of nodes N. Vertices will be [0, N-1]");
		 Scanner sc = new Scanner(System.in);
		 int N = sc.nextInt();

		 for (int i = 0; i < N; i++) {
			adjList.add(new ArrayList<>());
		 }

		 System.out.println("Please Enter the number of Edges");
		 int E = sc.nextInt();

		 System.out.println("Please enter each edge in the sequence <starting node> <destination node> <weight>");
		 for (int i = 0; i < E; i++) {
			int u = sc.nextInt();	// source
			int v = sc.nextInt();	// destination
			int weight = sc.nextInt();

			adjList.get(u).add(new Node(v, weight));
			adjList.get(v).add(new Node(u, weight));
		 }
		 sc.close();
		 Prims prims = new Prims();
		 int[] parent = prims.prims(adjList);

		 System.out.println("Minimum Spanning Tree: " + parent.length);
		 for (int i = 1; i < N; i++) {
			System.out.println("Edge: " + parent[i] + " - " + i + ", Weight: " + adjList.get(i-1).get(parent[i]).key);
		 }
	}
}

class Node {
	int vertex;
	int key;

	Node(int vertex, int key) {
		this.vertex = vertex;
		this.key = key;
	}
}

class NodeComparator implements Comparator<Node> {
	@Override
	public int compare (Node node1, Node node2) {
		if (node1.key < node2.key)
			return -1;
		if (node1.key > node2.key)
			return 1;
		return 0;
	}
}

