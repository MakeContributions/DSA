from collections import deque


class Node(object):
    def __init__(self,val):
        self.value = val
        self.leftchild = None
        self.rightchild = None

class BinaryTree(object):
    def __init__(self,root):
        self.root = Node(root)

    def pre_order_traversal(self,nnode):
        if nnode!=None:
            print(nnode.value,end=" ")
            self.PreOrderTraversal(self,nnode.leftchild)
            self.PreOrderTraversal(self,nnode.rightchild)

        return

    def in_order_traversal(self,nnode):
        if nnode!=None:
            self.InOrderTraversal(self,nnode.leftchild)
            print(nnode.value,end=" ")
            self.InOrderTraversal(self,nnode.rightchild)

        return 

    def post_order_traversal(self,nnode):
        if nnode!=None:
            self.PostOrderTraversal(self,nnode.leftchild)
            self.PostOrderTraversal(self,nnode.rightchild)
            print(nnode.value,end=" ")

        return

    def level_order_traversal(self, nnode):
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
        for item in range(len(nlist)):
            if (nlist[item] != None):
                print(nlist[item].element,end=" ")
            else:
                print(-1)

tree = BinaryTree(1)
tree.root.left = Node(2)
tree.root.right = Node(3)
tree.root.left.left = Node(4)
tree.root.left.right = Node(5)
tree.root.right.left = Node(6)
tree.root.right.right = Node(7)

tree.pre_order_traversal(tree.root)
tree.in_order_traversal(tree.root)
tree.post_order_traversal(tree.root)
tree.level_order_traversal(tree.root)





