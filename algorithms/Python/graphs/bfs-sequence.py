"""
BFS graph using Adjecency List
-----------------------------------------------------------------------------------------
-In Breadth First Search Sequence of any graph all childs of a parent node 
 is visited first and the children of all these childs are stored in the QUEUE array and 
 VISITED array.
-Children of nodes in QUEUE are visited one by one and stored in the QUEUE and 
 VISITED as well.
-When all children of a node is visited that node is removed from the QUEUE.
-These steps are repeated till all nodes in QUEUE are exhausted.
-----------------------------------------------------------------------------------------
-VISITED array is required to check if a node is already in BFS sequence or not.
-QUEUE array is important for ensuring that all nodes and edges are visited.
------------------------------------------------------------------------------------------
The sequence of nodes printed in every recursion is the BFS-SEQUENCE
------------------------------------------------------------------------------------------
"""
class Graph:
    queue=[] #keeps order of BFS tree
    visited=[] #keeps visited node 
    # front and rear for accessing queue
    front=0
    rear=0
    def ShowGraph(Adj_Dict): #displays graph
        for i in Adj_Dict:
            print(i,"->",Adj_Dict[i])
    def Display_BFS(curr,Adj_Dict): # displays BFS sequence
        print(curr,end=" ")
        if curr in Adj_Dict :
            if curr not in Graph.visited: 
                Graph.visited.append(curr) 
                Graph.queue.append(curr) 
                Graph.rear+=1
            for i in Adj_Dict[curr]: # iterate over all neighbours of curr
                if i not in Graph.visited: 
                    Graph.queue.append(i)
                    Graph.visited.append(i)
                    Graph.rear+=1            
        Graph.queue[Graph.front]=-1 # all nodes adjecent to curr are visited
        Graph.front+=1
        if Graph.front==Graph.rear: # no new node to visit
            return
        else:
            Graph.Display_BFS(Graph.queue[Graph.front],Adj_Dict) # go to next node
        return

#__main__
#Dry Run
#g is an adjecency list in form of dictionary
g={1:[2,4],2:[4,5],4:[7,5],5:[1,3,6],6:[3,8],8:[7]} # this is directed graph
# for undirected graph each edge has to be given twice
# Eg:- edge from 1-2 input as {1:[2]}
Graph.ShowGraph(g)
print("BFS Sequence")
Graph.Display_BFS(1,g) #passing start node
'''
---------------------------------
OUTPUT:-
Display Graph
1 -> [2, 4]
2 -> [4, 5]
4 -> [7, 5]
5 -> [3, 1, 6]
6 -> [8, 3]
8 -> [7]
BFS Sequence
1 2 4 5 7 3 6 8 
----------------------------------
TIME COMPLEXITY:
-O(V+E) where V and E are number
 of vertices and egdes in graph 
 respectively.
-For Adjecency List Only!
----------------------------------
'''
