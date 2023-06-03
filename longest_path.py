# Python program to find the longest distance between
# a source vertex,s, and all other vertices in a weighted
# directed acylic graph (DAG). The algorithm used Kahn's
# topological sorting algoritm for DAGs to sort the vertices
# in linear order. The longest path problem is not as easy
# as the shortest path because it doesn't have the optimal
# substructure property. The longest path problem, in fact,
# is NP-hard for a general graph. But it has a linear solution
# for a DAG. Time complexity is the same as for topological
# sorting, since that is the bulk of the algorith. But space
# complexity is O(V + E) because vertices and edges need to be
# stored in arrays.


def topologicalSortUtil(v):
	global Stack, visited, adj
	visited[v] = True

	# Recur for all the vertices adjacent to this vertex
	# list<AdjListNode>::iterator i
	for i in adj[v]:
		if (not visited[i[0]]):
			topologicalSortUtil(i[0])

	# Push current vertex to stack which stores topological
	# sort
	Stack.append(v)

# The function to find longest distances from a given vertex.
# It uses recursive topologicalSortUtil() to get topological
# sorting.
def longestPath(s):
	global Stack, visited, adj, V
	dist = [-10**9 for i in range(V)]

	# Call the recursive helper function to store Topological
	# Sort starting from all vertices one by one
	for i in range(V):
		if (visited[i] == False):
			topologicalSortUtil(i)
	# print(Stack)

	# Initialize distances to all vertices as infinite and
	# distance to source as 0
	dist[s] = 0
	# Stack.append(1)

	# Process vertices in topological order
	while (len(Stack) > 0):
	
		# Get the next vertex from topological order
		u = Stack[-1]
		del Stack[-1]
		#print(u)

		# Update distances of all adjacent vertices
		# list<AdjListNode>::iterator i
		if (dist[u] != 10**9):
			for i in adj[u]:
				# print(u, i)
				if (dist[i[0]] < dist[u] + i[1]):
					dist[i[0]] = dist[u] + i[1]

	# Print calculated longest distances
	# print(dist)
	for i in range(V):
		print("INF ",end="") if (dist[i] == -10**9) else print(dist[i],end=" ")

# Driver code
if __name__ == '__main__':
	V, Stack, visited = 6, [], [False for i in range(7)]
	adj = [[] for i in range(7)]
	
	# Create a graph given in the above diagram.
	# Here vertex numbers are 0, 1, 2, 3, 4, 5 with
	# following mappings:
	# 0=r, 1=s, 2=t, 3=x, 4=y, 5=z
	adj[0].append([1, 5])
	adj[0].append([2, 3])
	adj[1].append([3, 6])
	adj[1].append([2, 2])
	adj[2].append([4, 4])
	adj[2].append([5, 2])
	adj[2].append([3, 7])
	adj[3].append([5, 1])
	adj[3].append([4, -1])
	adj[4].append([5, -2])

	s = 1
	print("The following are the longest distances from source vertex ",s)
	longestPath(s)


