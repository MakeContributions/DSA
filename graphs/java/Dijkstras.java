import java.util.*;

class AdjListNode
{
	int dest;
	int weight;
	AdjListNode(int dest,int weight)
	{
		this.dest=dest;
		this.weight=weight;
	}
}

class NodeComparator implements Comparator<AdjListNode>
{
	@Override
	public int compare(AdjListNode node1, AdjListNode node2) 
	{		
		if (node1.weight < node2.weight) 
            		return -1; 
        	if (node1.weight > node2.weight) 
            		return 1; 
        	return 0; 
	}
}

class Dijkstras
{
	public int[] dijkstras(List<List<AdjListNode>> adj_list,int source)
	{
		int[] distance = new int[adj_list.size()];
		Set<Integer> completed = new HashSet<Integer>();
		for(int i=0;i<distance.length;++i)
		{
			distance[i] = Integer.MAX_VALUE;
		}
		PriorityQueue<AdjListNode> pq = new PriorityQueue<>(adj_list.size(),new NodeComparator());
		AdjListNode source_node = new AdjListNode(source,0);
		for(int i=0;i<distance.length;++i)
		{
			pq.add(new AdjListNode(i,Integer.MAX_VALUE));
			
		}
		pq.add(source_node);
		distance[source]=0;
		while(!pq.isEmpty())
		{
			AdjListNode current = pq.remove();
			if(!completed.contains(current.dest))
			{
				completed.add(current.dest);
				for(AdjListNode n :adj_list.get(current.dest) )
				{
					if( distance[n.dest] > (distance[current.dest]+n.weight))
					{
						distance[n.dest] = distance[current.dest]+n.weight;
						pq.add(new AdjListNode(n.dest, distance[n.dest]));
					}
				}
			}
		}
		return distance;
	}

	public static void main(String args[])
	{
		/*
		  	SAMPLE INPUT AND OUTPUT
			___________________________

			Input:
			__________
			Please enter the number of nodes N. Vertices will be [0,N-1]
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
			Please enter source vertex
			0

			Output:
			___________
			Distances from source 0
			Node0--->0
			Node1--->1
			Node2--->3
			Node3--->3
			Node4--->2
			Node5--->4
		 */

		List<List<AdjListNode>> adj_list = new ArrayList<List<AdjListNode>>();
		System.out.println("Please enter the number of nodes N. Vertices will be [0,N-1]");
		Scanner sc = new Scanner(System.in);
		int v = sc.nextInt();
		for(int i=0;i<v;++i)
			adj_list.add(new ArrayList<AdjListNode>());
		
		System.out.println("Please enter the number of edges");
		int e = sc.nextInt();
		System.out.println("Please enter each edge in the sequence <starting node> <destination node> <weight>");
		// Sample Data: 0 2 5 (edge from 0 to 2 with weight 5)
		for(int i=0;i<e;++i)
		{
			int startnode = sc.nextInt();
			int destnode = sc.nextInt();
			int weight = sc.nextInt();
		       	adj_list.get(startnode).add(new AdjListNode(destnode,weight));
		}
		int source;
		System.out.println("Please enter source vertex");
		source = sc.nextInt();
		Dijkstras d = new Dijkstras();
		int[] distances  = d.dijkstras(adj_list, source);  //source vertex is taken as 0
		System.out.println("Distances from source "+source);
		for(int i=0;i<distances.length;++i)
		{
			if(distances[i]==Integer.MAX_VALUE)
				System.out.println("Node"+i+"--->"+"infinity");
			else
				System.out.println("Node"+i+"--->"+distances[i]);
		}
	}
}
