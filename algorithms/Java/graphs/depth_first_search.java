
import java.util.Scanner;
public class depth_first_search {
    public static void dfs(int source,int[][] graph,boolean[] visited){
        visited[source]=true;
        System.out.print(source+" --> ");
        for (int i = 0; i < graph[source].length ; i++) {
            if(visited[i]==false && graph[source][i]==1 ){
                source=i;
                dfs(source,graph,visited);
            }
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Depth First Search");
        System.out.println("Enter The number of Vertices");
        int n=sc.nextInt();
        System.out.println("Enter the Adjacency Matrix of n X n : ");
        int graph[][]=new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j]=sc.nextInt();
            }
        }
        boolean[] visited = new boolean[graph.length];
        dfs(1,graph,visited);
    }
}
