class Graph:
    queue=[]
    visited=[]
    front=0
    rear=0
    Adj_Dict={}
    def graph(Adj_Mtx):
        for i in Adj_Mtx:
            if i[0] not in Graph.Adj_Dict:
                Graph.Adj_Dict[i[0]]=[i[1]]
            else:
                Graph.Adj_Dict[i[0]].append(i[1])
    def ShowGraph():
        for i in Graph.Adj_Dict:
            print(i,"->",Graph.Adj_Dict[i])
    def Display_BFS(curr):
        print(curr,end=" ")
        if curr in Graph.Adj_Dict :
            if curr not in Graph.visited:
                Graph.visited.append(curr) 
                Graph.queue.append(curr) 
                Graph.rear+=1
            for i in Graph.Adj_Dict[curr]:
                if i not in Graph.visited:
                    Graph.queue.append(i)
                    Graph.visited.append(i)
                    Graph.rear+=1            
        Graph.queue[Graph.front]=-1
        Graph.front+=1
        if Graph.front==Graph.rear:
            return
        else:
            Graph.Display_BFS(Graph.queue[Graph.front])
        return
    

g=[[1,2],[1,4],[2,4],[2,5],[4,7],[4,5],[5,3],[5,1],[5,6],[6,8],[6,3],[8,7]]
Graph.graph(g)
print("Graph")
Graph.ShowGraph()
print("BFS")
Graph.Display_BFS(1)
