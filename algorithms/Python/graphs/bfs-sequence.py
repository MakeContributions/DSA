"""
BFS graph using Adjecency List
-----------------------------------------------------------------------------------------
-In Breadth First Search Sequence of any graph all children of a parent node 
 is visited first and the children are stored in the QUEUE array and 
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
def ShowGraph(Adj_Dict: dict[int, list[int]])->None :  #displays graph
   for i in Adj_Dict:
       print(i,"->",Adj_Dict[i])
   return
def Display_BFS(curr:int ,Adj_Dict: dict[int, list[int]]) -> None: # displays BFS sequence
   global rear
   global front
   print(curr,end=" ")
   if curr in Adj_Dict :
       if curr not in visited: 
           visited.append(curr) 
           queue.append(curr) 
           rear+=1
       for i in Adj_Dict[curr]: # iterate over all neighbours of curr
           if i not in visited: 
               queue.append(i)
               visited.append(i)
               rear+=1            
   queue[front]=-1 # all nodes adjecent to curr are visited
   front+=1
   if front==rear: # no new node to visit
       return
   else:
       Display_BFS(queue[front],Adj_Dict) # go to next node
   return

#__main__
#Dry Run
queue: list[int]=[]#: list[int]=[] #keeps order of BFS tree
visited: list[int]=[] #: list[int]=[] #keeps visited node 
# front and rear for accessing queue
front=0
rear=0
#g is an adjecency list in form of dictionary
g={1:[2,4],2:[4,5],4:[7,5],5:[1,3,6],6:[3,8],8:[7]} # this is directed graph
# for undirected graph each edge has to be given twice
# Eg:- edge from 1-2 input as {1:[2]}
print("Display Graph")
ShowGraph(g)
print("BFS Sequence")
Display_BFS(1,g) #passing start node
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
 of vertices and edges in graph 
 respectively.
-For Adjecency List Only!
----------------------------------
'''
