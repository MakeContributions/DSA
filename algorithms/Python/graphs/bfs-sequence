"""
BFS graph using Adjecency List
"""
class Graph:
    queue=[] #keeps order of BFS tree
    visited=[] #keeps visited node 
    # front and rear for accessing queue
    front=0
    rear=0
    # stores Adjecency List as dictionary
    Adj_Dict={}
    def graph(Adj_Mtx): #converts Adj_MTX into Adj_Dict
        for i in Adj_Mtx:
            if i[0] not in Graph.Adj_Dict:
                Graph.Adj_Dict[i[0]]=[i[1]]
            else:
                Graph.Adj_Dict[i[0]].append(i[1])
    def ShowGraph(): #displays graph
        for i in Graph.Adj_Dict:
            print(i,"->",Graph.Adj_Dict[i])
    def Display_BFS(curr): # displays BFS sequence
        print(curr,end=" ")
        if curr in Graph.Adj_Dict :
            if curr not in Graph.visited: 
                Graph.visited.append(curr) 
                Graph.queue.append(curr) 
                Graph.rear+=1
            for i in Graph.Adj_Dict[curr]: # iterate over all neighbours of curr
                if i not in Graph.visited: 
                    Graph.queue.append(i)
                    Graph.visited.append(i)
                    Graph.rear+=1            
        Graph.queue[Graph.front]=-1 # all nodes adjecent to curr are visited
        Graph.front+=1
        if Graph.front==Graph.rear: # no new node to visit
            return
        else:
            Graph.Display_BFS(Graph.queue[Graph.front]) # go to next node
        return

#__main__
#Dry Run
g=[[1,2],[1,4],[2,4],[2,5],[4,7],[4,5],[5,3],[5,1],[5,6],[6,8],[6,3],[8,7]] # this is directed graph
# for undirected graph each edge has to be given twice
# Eg:- edge from 1-2 input as [[1,2],[2,1]]
Graph.graph(g) #create graph
print("Display Graph")
Graph.ShowGraph()
print("BFS Sequence")
Graph.Display_BFS(1) #passing start node
