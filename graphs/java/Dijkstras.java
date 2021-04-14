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






class NodeComparator implements Comparator<AdjListNode>{
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







	

	public static List<List<AdjListNode>> createGraph()
	{
		List<List<AdjListNode>> adj_list = new ArrayList<List<AdjListNode>>();
		
		for(int i=0;i<6;++i)
		{
			adj_list.add(new ArrayList<AdjListNode>());

		}
		
		adj_list.get(0).add(new AdjListNode(1, 1));
		adj_list.get(0).add(new AdjListNode(2, 5));
		adj_list.get(1).add(new AdjListNode(2, 2));
		adj_list.get(1).add(new AdjListNode(3, 2));
		adj_list.get(1).add(new AdjListNode(4, 1));
		adj_list.get(2).add(new AdjListNode(4, 2));
		adj_list.get(3).add(new AdjListNode(4, 3));
		adj_list.get(3).add(new AdjListNode(5, 1));
		adj_list.get(4).add(new AdjListNode(5, 2));


		
		return adj_list;


	}





	public static void main(String args[])
	{
	
		List<List<AdjListNode>> adj_list = createGraph(); // sample graph You can  write custom I/O to get adjacency list
		Dijkstras d = new Dijkstras();
		int[] distances  = d.dijkstras(adj_list, 0);  //source vertex is taken as 0
		
		System.out.println("Distances from source 0");
		for(int i=0;i<distances.length;++i)
		{
			if(distances[i]==Integer.MAX_VALUE)
				System.out.println("Node"+i+"--->"+"infinity");
			else
				System.out.println("Node"+i+"--->"+distances[i]);
		}

	}
}
