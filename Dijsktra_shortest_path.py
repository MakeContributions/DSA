# Python implementation of Dijkstra's Shortest
# Path Algorithm. Dijkstra'a algorithm is an
# algoritm for finding the shortest path between
# nodes in a weighted graph, which may represent,
# for example, road networks. It was conceived
# by computer scientist Edgser Dijkstra in 1956
# and published three years later. For a given 
# source node in the graph, the algorithm finds
# the shortest path between that node and every
# other node. Dijkstra' algorithm can be used
# to find the shortest route between one city
# and all other cities. A widely used application
# is netowk routing protocols, most notably
# IS-IS and OSPF. When used with a mininum heap
# the time complexity is O(E * logV) where E
# is the number o edges and V is the number
# of vertices. Space complextiy is O(V). 


import heapq

# iPair ==> Integer Pair
iPair = tuple

# This class represents a directed graph using
# adjacency list representation
class Graph:
	def __init__(self, V: int): # Constructor
		self.V = V
		self.adj = [[] for _ in range(V)]

	def addEdge(self, u: int, v: int, w: int):
		self.adj[u].append((v, w))
		self.adj[v].append((u, w))

	# Prints shortest paths from src to all other vertices
	def shortestPath(self, src: int):
		# Create a priority queue to store vertices that
		# are being preprocessed
		pq = []
		heapq.heappush(pq, (0, src))

		# Create a vector for distances and initialize all
		# distances as infinite (INF)
		dist = [float('inf')] * self.V
		dist[src] = 0

		while pq:
			# The first vertex in pair is the minimum distance
			# vertex, extract it from priority queue.
			# vertex label is stored in second of pair
			d, u = heapq.heappop(pq)

			# 'i' is used to get all adjacent vertices of a
			# vertex
			for v, weight in self.adj[u]:
				# If there is shorted path to v through u.
				if dist[v] > dist[u] + weight:
					# Updating distance of v
					dist[v] = dist[u] + weight
					heapq.heappush(pq, (dist[v], v))

		# Print shortest distances stored in dist[]
		for i in range(self.V):
                       	print(f"{i} \t\t {dist[i]}")

# Driver's code
if __name__ == "__main__":
	# create the graph given in above figure
	V = 9
	g = Graph(V)

	# making above shown graph
	g.addEdge(0, 1, 4)
	g.addEdge(0, 7, 8)
	g.addEdge(1, 2, 8)
	g.addEdge(1, 7, 11)
	g.addEdge(2, 3, 7)
	g.addEdge(2, 8, 2)
	g.addEdge(2, 5, 4)
	g.addEdge(3, 4, 9)
	g.addEdge(3, 5, 14)
	g.addEdge(4, 5, 10)
	g.addEdge(5, 6, 2)
	g.addEdge(6, 7, 1)
	g.addEdge(6, 8, 6)
	g.addEdge(7, 8, 7)

	g.shortestPath(0)
