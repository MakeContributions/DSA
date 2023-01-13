# this graph to check the algorithm
graph={
    'S':['B','D','A'],
    'A':['C'],
    'B':['D'],
    'C':['G','D'],
    'S':['G'],
}
#function of BFS
def BFS(graph,start,goal):
    Visited=[]
    queue=[[start]]
    while queue:
        path=queue.pop(0)
        node=path[-1]
        if node in Visited:
            continue
        Visited.append(node)
        if node==goal:
            return path
        else:
            adjecent_nodes=graph.get(node,[])
            for node2 in adjecent_nodes:
                new_path=path.copy()
                new_path.append(node2)
                queue.append(new_path)




Solution=BFS(graph,'S','G')
print('Solution is ',Solution)                
