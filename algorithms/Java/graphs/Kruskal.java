
import java.util.*;

class Edge {
    int src, dest, weight;

    Edge(int src, int dest, int weight) {
        this.src = src;
        this.dest = dest;
        this.weight = weight;
    }
}

class Kruskal {
    int V, E;
    Edge[] edges;

    Kruskal(int v, int e) {
        V = v;
        E = e;
        edges = new Edge[E];
        for (int i = 0; i < e; ++i)
            edges[i] = new Edge(0, 0, 0);
    }

    int find(int[] parent, int i) {
        if (parent[i] == i)
            return i;
        return find(parent, parent[i]);
    }

    void union(int[] parent, int x, int y) {
        int xRoot = find(parent, x);
        int yRoot = find(parent, y);
        parent[xRoot] = yRoot;
    }

    void kruskalMST() {
        Edge[] result = new Edge[V];
        int[] parent = new int[V];
        for (int i = 0; i < V; ++i)
            parent[i] = i;

        Arrays.sort(edges, Comparator.comparingInt(o -> o.weight));

        int e = 0;
        int i = 0;
        while (e < V - 1 && i < E) {
            Edge next_edge = edges[i++];
            int x = find(parent, next_edge.src);
            int y = find(parent, next_edge.dest);

            if (x != y) {
                result[e++] = next_edge;
                union(parent, x, y);
            }
        }

        System.out.println("Following are the edges in the constructed MST:");
        for (i = 0; i < e; ++i)
            System.out.println(result[i].src + " - " + result[i].dest + ": " + result[i].weight);
    }

    public static void main(String[] args) {

        /*
        SAMPLE INPUT AND OUTPUT
		___________________________

		Input:
		____________________________

        Please enter the number of nodes N. Vertices will be [0,N-1]
        6
        Please enter the number of edges
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
		____________________________

		Following are the edges in the constructed MST:
        1 - 4: 1
        3 - 5: 1
        1 - 3: 2
        0 - 1: 1
        2 - 4: 2

        */
        Scanner sc = new Scanner(System.in);

        System.out.println("Please enter the number of nodes N. Vertices will be [0,N-1]");
        int v = sc.nextInt();

        System.out.println("Please enter the number of edges");
        int e = sc.nextInt();

        Kruskal graph = new Kruskal(v, e);

        System.out.println("Please enter each edge in the sequence <starting node> <destination node> <weight>");
        for (int i = 0; i < e; ++i) {
            int src = sc.nextInt();
            int dest = sc.nextInt();
            int weight = sc.nextInt();
            graph.edges[i] = new Edge(src, dest, weight);
        }

        graph.kruskalMST();
    }
}