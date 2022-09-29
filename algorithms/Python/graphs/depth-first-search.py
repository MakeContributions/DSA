# A dfs algorithm in Python
# This is an algorithm for traversing a graph in depth first search manner
# It is commonly used in tree/graph traversals
# Time Complexity: O(V+E)
# Space Complexity: O(V)
# V is number of vertices and E is number of edges

"""
Refer the following example for output
Graph 1: https://cdn.programiz.com/sites/tutorial2program/files/graph-dfs-step-0.png
Graph 2: https://static.javatpoint.com/ds/images/depth-first-search-algorithm2.png

"""

def dfs(edges, vis, node):
	if(vis[node]!=1):
		vis[node] = 1
		print(node, end = " ")
	
	for i in edges[node]:
		if(vis[i]!=1):
			dfs(edges, vis, i)


def main():
	""" Main Function """

	#First example

	graph1 = []
	graph1.append([1,2,3])
	graph1.append([0,2])
	graph1.append([0,1,4])
	graph1.append([0])
	graph1.append([2])	

	vis = []
	for i in range(0,10):
		vis.append(0)

	print("DFS for Graph 1 is:")
	dfs(graph1, vis, 0)

	#Making visited list elements 0 for second graph
	for i in range(0,10):
		vis[i] = 0

	graph2 = []
	graph2.append([1, 2, 3])
	graph2.append([3])
	graph2.append([4])
	graph2.append([5, 6])
	graph2.append([5, 7])
	graph2.append([2])
	graph2.append([])
	graph2.append([])

	print("\n\nDFS for Graph 2 is:")
	dfs(graph2, vis, 0)

if __name__=="__main__":
	main()