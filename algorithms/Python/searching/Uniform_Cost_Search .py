# this graph to check the algorithm
graph={
  'S':[('A',2),('B',3),('D',5)],
  'A':[('C',4)],
  'B':[('D',4)],
  'C':[('D',1),('G',2)],
  'D':[('G',5)],
  'G':[],
    }

#to calculate the total cost of path
def path_cost(path):
    total_cost=0
    for (node, cost) in path:
        total_cost+=cost
    return total_cost , path[-1][0]
# well sort queue items based on total path
#if two items have the same total_cost then sort by node name (alphabetically)

# uniform cost search
def UCS(graph, start, goal):
    visited=[]
    queue=[[(start,0)]]
    while queue:
        queue.sort(key=path_cost)#sorting by cost
        path=queue.pop(0)#choosing least cost
        node=path[-1][0]
        if node in visited:
            continue
        visited.append(node)
        if node==goal:
            return path
        else:
            adjacent_nodes=graph.get(node,[])
            for(node2,cost)in adjacent_nodes:
                new_path=path.copy()
                new_path.append((node2,cost))
                queue.append(new_path)


solution= UCS(graph,'S','G')
print('solution is ' , solution)
print ('cost of solution is ',path_cost(solution)[0])
                
