'''
	QUESTION : We have to find the sum of the node of the Generic Tree.
'''


import sys
import queue

class TreeNode :
    def __init__(self, data) :
        self.data = data
        self.children = list()

'''
	We will take the tree input levelwise :
				5
			      /  \
			     3    6
			    / \    \
			   2   7    9
			   
		The levelwise input we have to give for this tree will be : 
	5 2(representing number of childrens) 3 6 2(number of children) 2 7 1(number of children) 9 0 0 0
'''

def inputLevelWise(li) :
    i = 0
    data = li[i] 
    i += 1
    if data == -1 :
        return None
    root = TreeNode(data) 
    q = queue.Queue()
    q.put(root)
    while (not q.empty()) :
        frontNode = q.get()
        noOfChildren = li[i]
        i += 1
        childrenArray = li[i : i+noOfChildren]
        for childData in childrenArray :
            childNode = TreeNode(childData)
            frontNode.children.append(childNode)
            q.put(childNode)
        i = i+noOfChildren
    return root
        
        
 # finding sum of all nodes in a generic tree by using recursion : 
 
def sumOfAllNodes(root) :
    if root is None:
        return 0
    sum = root.data
    for child in root.children:
        sum = sum + sumOfAllNodes(child)

    return sum
    
#main
sys.setrecursionlimit(10**6)
li = [int(elem) for elem in list(input().strip().split())]
root = inputLevelWise(li)
print(sumOfAllNodes(root))
