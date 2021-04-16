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
            self.pre_order_traversal(nnode.leftchild)
            self.pre_order_traversal(nnode.rightchild)

        return

    def in_order_traversal(self,nnode):
        if nnode!=None:
            self.in_order_traversal(nnode.leftchild)
            print(nnode.value,end=" ")
            self.in_order_traversal(nnode.rightchild)

        return 

    def post_order_traversal(self,nnode):
        if nnode!=None:
            self.post_order_traversal(nnode.leftchild)
            self.post_order_traversal(nnode.rightchild)
            print(nnode.value,end=" ")

        return

    def level_order_traversal(self, nnode):
        q1 = deque()
        q1.append(nnode)
        while (len(q1)>0):
        	temp=q1.popleft()
        	print(temp.value,end=",")
        	if temp.leftchild!=None:
        		q1.append(temp.leftchild)
        	if temp.rightchild!=None:
        		q1.append(temp.rightchild)
        return
        
                

tree = BinaryTree(1)
tree.root.left = Node(2)
tree.root.right = Node(3)


tree.pre_order_traversal(tree.root)
print()
tree.in_order_traversal(tree.root)
print()
tree.post_order_traversal(tree.root)
print()
tree.level_order_traversal(tree.root)
print()





