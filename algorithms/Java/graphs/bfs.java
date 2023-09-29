// Java progam to implement breadth first search(bfs) traversals
// Approach 
// Graph is represented in the form of adjacencyMatrix
// In BFS source node is explored and all its  unvisited neighbour nodes are added to queue
// Now the first node in Queue is explored and all its unvisited neighbour nodes are added to queue
// This process is continued untill all the nodes are visited.

import java.util.*;
import java.util.Queue;

public class bfs {

    public static void bfsAlgorithm(int adjacencyMatrix[][], boolean visited[], int src) {
        int n = adjacencyMatrix.length;
        Queue<Integer> q = new LinkedList<>();
        visited[src] = true;
        q.add(src);

        while(!q.isEmpty()) {
            int cur = q.remove();
            System.out.print(cur + " ");
            for(int i = 0; i < n; i++) {
                if(!visited[i] && adjacencyMatrix[cur][i] == 1) {
                    visited[i] = true;
                    q.add(i);
                }
            }
        }
    }

    //Main method
    public static void main(String[] args) {
        // graph
        // nodes   0 1 2 3 4
        //   0     0 1 0 1 0
        //   1     1 0 1 1 0
        //   2     0 1 0 0 1
        //   3     1 1 0 0 0
        //   4     0 0 1 0 0

        // Sample input
        // Enter number of nodes: 5
        // Enter 1 if edge is present else 0, with 0 and all other nodes: 0 1 0 1 0
        // Enter 1 if edge is present else 0, with 1 and all other nodes: 1 0 1 1 0
        // Enter 1 if edge is present else 0, with 2 and all other nodes: 0 1 0 0 1
        // Enter 1 if edge is present else 0, with 3 and all other nodes: 1 1 0 0 0
        // Enter 1 if edge is present else 0, with 4 and all other nodes: 0 0 1 0 0
        // Enter source node: 0

        // Sample output
        // BFS traversal: 0 1 3 2 4


        Scanner sc = new Scanner(System.in);
        // number of nodes or vertices
        System.out.print("Enter number of nodes: ");
        int numberOfNodes = sc.nextInt();

        // To store connections of all nodes
        int adjacencyMatrix[][] = new int[numberOfNodes][numberOfNodes];
        for(int i = 0; i < numberOfNodes; i++) {
            System.out.print("Enter 1 if edge is present else 0, with " + i + " and all other nodes: ");
            for(int j = 0; j < numberOfNodes; j++) {
                adjacencyMatrix[i][j] = sc.nextInt();
            }
        }

        // Source node to start traversal
        System.out.print("Enter source node: ");
        int src = sc.nextInt();

        boolean visited[] = new boolean[numberOfNodes];
        System.out.print("BFS traversal: ");
        for(int i = 0; i < numberOfNodes; i++) {
            if(!visited[i]) {
                bfsAlgorithm(adjacencyMatrix, visited, src);
            }
        }
        System.out.println();
        sc.close();
    }
}

