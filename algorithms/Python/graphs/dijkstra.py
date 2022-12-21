import heapq
INF = 10**9

# make graph, set start node
V, E = map(int, input().split())
graph = [[]for _ in range(V)] # adjlist
start = int(input())

# make edges
for _ in range(E):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))    

# make list of distance from start to des, visit status, priority queue
dist = [INF] * (V)
visit = [False] * (V)
PQ = [(0, start)] # cost, vertice

# djikstra algorithm
while PQ:
    cost, node = heapq.heappop(PQ)
    if visit[node]: continue
    
    visit[node] = True
    dist[node] = cost
    for v, w in graph[node]:
      alt = cost + w
      heapq.heappush(PQ, (alt, v))

"""
SAMPLE INPUT AND OUTPUT
	___________________________
	Input:
	__________
	<Vertices> <Edges>
	5 6
	<start node>
    0
	<src node> <des node> <weight>
	4 0 1
    0 1 2
    0 2 3
    1 2 4
    1 3 5
    2 3 6
			
	Output:
	___________
	Distances from start node 0
	0
    2
    3
    7
    INF
"""

for i in dist:
  if i == INF: print("INF") 
  else: print(i)