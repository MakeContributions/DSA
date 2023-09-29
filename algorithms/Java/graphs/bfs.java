// Java progam to implement breadth first search(bfs) traversals
import java.util.*;

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
        Scanner sc = new Scanner(System.in);
        // number of nodes or vertices
        System.out.print("Enter number of nodes: ");
        int numberOfNodes = sc.nextInt();

        // To store connections of all nodes
        int adjacencyMatrix[][] = new int[numberOfNodes][numberOfNodes];

        // Sample input for 5 nodes
        // nodes   0 1 2 3 4
        //   0     0 1 0 1 0
        //   1     1 0 1 1 0
        //   2     0 1 0 0 1
        //   3     1 1 0 0 0
        //   4     0 0 1 0 0

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

