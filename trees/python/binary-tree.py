from collections import deque


class Node(object):
    def __init__(self,val):
        self.value = val
        self.leftchild = None
        self.rightchild = None

class BinaryTree(object):
    def __init__(self,root):
        self.root = Node(root)

    def PreOrderTraversal(self,nnode):
        if nnode!=None:
            print(nnode.value,end=" ")
            self.PreOrderTraversal(self,nnode.leftchild)
            self.PreOrderTraversal(self,nnode.rightchild)

        return

    def InOrderTraversal(self,nnode):
        if nnode!=None:
            self.InOrderTraversal(self,nnode.leftchild)
            print(nnode.value,end=" ")
            self.InOrderTraversal(self,nnode.rightchild)

        return 

    def PostOrderTraversal(self,nnode):
        if nnode!=None:
            self.PostOrderTraversal(self,nnode.leftchild)
            self.PostOrderTraversal(self,nnode.rightchild)
            print(nnode.value,end=" ")

        return

    def levelorderTraverse(self, nnode):
        q1 = deque()
        q1.append(nnode)
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
tree.root.left.left = Node(4)
tree.root.left.right = Node(5)
tree.root.right.left = Node(6)
tree.root.right.right = Node(7)




