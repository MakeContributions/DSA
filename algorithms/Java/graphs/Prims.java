/**
Approach-
It starts with an empty spanning tree. The idea is to maintain two sets of vertices. 
The first set contains the vertices already included in the MST, the other set contains the vertices not yet included. 
At every step, it considers all the edges that connect the two sets and picks the minimum weight edge from these edges. 
After picking the edge, it moves the other endpoint of the edge to the set containing MST. 
*/

/* 
Time complexity -
Time Complexity: O(V^2)
If the input graph is represented using an adjacency list, then the time complexity of Prim’s algorithm can be reduced to O(E log V) with the help of a binary heap.  
In this implementation, we are always considering the spanning tree to start from the root of the graph.

Auxiliary Space: O(V)
*/

import java.util.Scanner;
public class Prims{
	public static void main(String[] args) {
		int w[][]=new int[10][10];
		int min,mincost=0, u, v, flag=0;
		int sol[]=new int[10];
		System.out.println("Enter the number of vertices");
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		System.out.println("Enter the weighted graph");
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				w[i][j]=sc.nextInt();
		System.out.println("Enter the source vertex");
		int s=sc.nextInt();
		for(int i=1;i<=n;i++) // Initialise the solution matrix with 0
			sol[i]=0;
		sol[s]=1; // mark the source vertex
		int count=1;
		while (count<=n-1)
		{
			min=99; // If there is no edger between any two vertex its cost is assumed to be 99
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(sol[i]==1&&sol[j]==0) //this will check the edge if not already traversed will be considered
						if(i!=j && w[i][j]<min)
						{
							min=w[i][j]; //cost of the edge
							u=i;
							v=j;
						}
			sol[v]=1;
			mincost += min; //mincost of whole graph
			count++;
			System.out.println(u+"->"+v+"="+min);
		}

		for(i=1;i<=n;i++)
			if(sol[i]==0)
				flag=1;
		if(flag==1)
		System.out.println("No spanning tree");
		else
		System.out.println("The cost of minimum spanning tree is"+mincost);
		sc.close();
		}
}

/* Let us create the following graph
        2 3
        (0)--(1)--(2)
        | / \ |
        6| 8/ \5 |7
        | /     \ |
        (3)-------(4)
            9         
         { 
            { 99, 2, 99, 6, 99 },
            { 2, 99, 3, 8, 5 },
            { 99, 3, 99, 99, 7 },
            { 6, 8, 99, 99, 9 },
            { 99, 5, 7, 9, 99 } 
         };
*/
