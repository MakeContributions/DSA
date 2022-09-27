import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
class g {
    private int ver;
    private LinkedList<Integer> arr[];
    private Queue<Integer> queue = new LinkedList();
    public g(int node) {
        this.ver = node; // number of vertices in the graph
        arr = new LinkedList[node];
        for (int i = 0; i < node; i++) {
            arr[i] = new LinkedList<>();
        }
    }
    void add(int node, int val) {
        arr[node].add(val);
    }

    void bfs(int i) {
        int visited[] = new int[ver];
        visited[i] = 1;
        int nod;
        queue.add(i);
        while (queue.size() != 0) {
            nod = queue.poll();
            System.out.print(nod+"-->");
            Iterator<Integer> j = arr[nod].listIterator();
            while (j.hasNext()) {
                int k = j.next();
                if (visited[k] != 1) {
                    visited[k] = 1;
                    queue.add(k);
                }
            }
        }
    }
}
public class breadth_first_search{
    public static void main(String[] args) {
        System.out.println("Breadth First Search");
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of Vertices ");
        int n=sc.nextInt();
        g a = new g(n);
        System.out.println("Enter the number of Edges");
        int edge=sc.nextInt();
        System.out.println("Enter Source and Destination of edges ");
        for (int i = 0; i < edge; i++) {
            int source =sc.nextInt();
            int destination = sc.nextInt();
            a.add(source,destination);
        }
        System.out.println("Enter Start Point ");
        int start=sc.nextInt();
        System.out.println("Path");
        a.bfs(start);

    }
}
/*
graph a = new graph(4);
 a.add(0, 1);
 a.add(0, 2);
 a.add(1, 2);
 a.add(2, 0);
 a.add(2, 3);
 a.add(3, 3);
 a.bfs(0);
*/
