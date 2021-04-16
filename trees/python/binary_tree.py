from collections import deque

class Node(object):
    def __init__(self,val):
        self.value = val
        self.leftchild = None
        self.rightchild = None

class BinaryTree(object):
    def __init__(self,root):
        self.root = Node(root)

    def PreOrderTraversal(self,v):
        if v!=None:
            print(v.value,end=" ")
            self.PreOrderTraversal(self,v.leftchild)
            self.PreOrderTraversal(self,v.rightchild)

        return

    def InOrderTraversal(self,v):
        if v!=None:
            self.InOrderTraversal(self,v.leftchild)
            print(v.value,end=" ")
            self.InOrderTraversal(self,v.rightchild)

        return 

    def PostOrderTraversal(self,v):
        if v!=None:
            self.PostOrderTraversal(self,v.leftchild)
            self.PostOrderTraversal(self,v.rightchild)
            print(v.value,end=" ")

        return

    def levelorderTraverse(self, v):
        q1 = deque()
        q1.append(v)
        while (len(q1)>0):
        	temp=q1.popleft()
        	print(temp.element,end=",")
        	if temp.leftchild!=None:
        		q1.append(temp.leftchild)
        	if temp.rightchild!=None:
        		q1.append(temp.rightchild)
        return

    def PrintTree(self,nlist):
        for i in range(len(nlist)):
            if (nlist[i] != None):
                print(nlist[i].element,end=" ")
            else:
                print(-1)

tree = BinaryTree(1)
tree.root.left = Node(2)
tree.root.right = Node(3)




