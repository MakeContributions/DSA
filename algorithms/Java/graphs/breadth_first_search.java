/*Here we have initialised a adjacency matrix.We have initialised a "visited" array to 0 to keep track of the vertices that have
 * alreadt been visited.Breadth first search uses "queue" data structure."n" is the number of vertices in the graph.we have to be 
 * careful to not visit the same vertex multiple times so we use the check in line 45.
*/

/*The time complexity of the above implementation of breadth-first search (BFS) is O(V+E), where V is the number of vertices and E is the number of edges in the graph.
In the BFS algorithm, we visit each vertex at most once, and each time we visit a vertex, we also add its neighbors to the queue. Therefore, the time 
complexity is O(V) for visiting all the vertices. Additionally, we also check the edges between the vertices, which takes O(E) time. Therefore, the 
overall time complexity is O(V+E). */


/*The space complexity of the above implementation of BFS is O(V), where V is the number of vertices in the graph.
In this implementation, we use an array "visited" to keep track of which vertices have been visited, and we use a queue to store the vertices
as we visit them. The size of the "visited" array is equal to the number of vertices, and the size of the queue is also equal to the number of 
vertices, as at any point in time, the queue will contain all the vertices that have been visited but not yet processed (that is, had all their
neighbors added to the queue). Therefore, the space complexity is O(V). */



import java.util.*;
class Breadth_First_Search{
    static int visited[]=new int[7];
    int rear=-1;
    int front=-1;
    int queue[]=new int[8];
    
    int count(){
        return rear-front+1;
    }
    
    void AddElement(int n){
        if(front==-1){
            front=rear=1;
        }
        else{
            rear=rear+1;
        }
        queue[rear]=n;
    }
    
    int RemoveElement(){
        int k=front;
        front=front+1;
        return queue[k];
    }
    
    void bfs(int a[][],int i,int n){
        int r,c;
        System.out.println(i);
        visited[i]=1;
        AddElement(i);
        
        while(count()!=0){
            r=RemoveElement();
            for(c=1;c<n;c++){
                if(a[r][c]==1 && visited[c]==0){
                    System.out.println(c);
                    visited[c]=1;
                    AddElement(c);
                }
            }
        }
    }
    
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        Breadth_First_Search obj=new Breadth_First_Search();
        
        //initialising "visited" array to zero.
        for(int i=0;i<7;i++){
            visited[i]=0;
        }
        
        int a[][]={
		{0,1,1,1,0,0,0},
		{1,0,1,0,0,0,0},
		{1,1,0,1,1,0,0},
		{1,0,1,0,1,0,0},
		{0,0,1,1,0,1,1},
		{0,0,0,0,1,0,0},
		{0,0,0,0,1,0,0}
	   };
	   int i,n=7;//"n" is the number of vertices
	   int start_node=1;
	   i=start_node;
	   obj.bfs(a,i,n);
        
    }
}