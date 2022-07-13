# A dfs alorithm in Python

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