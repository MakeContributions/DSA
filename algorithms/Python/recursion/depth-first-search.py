# A dfs alorithm in Python

"""
Refer the following example for output
Graph: https://cdn.programiz.com/sites/tutorial2program/files/graph-dfs-step-0.png
Output:
Enter number of nodes: 5    
Enter nodes connected to node 0: 
1 2 3
Enter nodes connected to node 1: 
1 2
Enter nodes connected to node 2: 
0 1 4
Enter nodes connected to node 3: 
0
Enter nodes connected to node 4: 
2
DFS is:
0 1 2 4 3

"""

n = int(input("Enter number of nodes: "))
vis = []
for i in range(0,n):
	vis.append(0)

def dfs(edges, node):
	if(vis[node]!=1):
		vis[node] = 1
		print(node, end = " ")
	
	for i in edges[node]:
		if(vis[i]!=1):
			dfs(edges, i)


edges = []

for i in range(0,n):
	print(f"Enter nodes connected to node {i}: ")
	destinations = list(map(int, input().split()))
	edges.append(destinations)

print("DFS is:")
dfs(edges, 0)