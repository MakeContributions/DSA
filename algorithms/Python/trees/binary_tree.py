# Author: github.com/Mo-Shakib

""" The binary tree data structure implementation """

class Node:
    """ node class """
    def __init__(self, data = None):
        """ initializing function """
        self.left = None
        self.right = None
        self.data = data

    def set_left(self, node):
        """ for setting left node """
        self.left = node

    def set_right(self, node):
        """ for setting right node """
        self.right = node

    def get_left(self):
        """ for getting the left node """
        return self.left

    def get_right(self):
        """ for getting right node """
        return self.right

    def set_data(self, data):
        """ for setting data of a node """
        self.data = data

    def get_data(self):
        """ for getting data of a node """
        return self.data

def inorder(tree):
    """ in this we traverse first to the leftmost node,
    then print its data and then traverse for rightmost node """
    if tree:
        inorder(tree.get_left())
        print(tree.get_data(), end = ' ')
        inorder(tree.get_right())

def preorder(tree):
    """ in this we first print the root node
    and then traverse towards leftmost node and then to the rightmost node """
    if tree:
        print(tree.get_data(), end = ' ')
        preorder(tree.get_left())
        preorder(tree.get_right())

def postorder(tree):
    """ in this we first traverse to the leftmost node
    and then to the rightmost node and then print the data """
    if tree:
        postorder(tree.get_left())
        postorder(tree.get_right())
        print(tree.get_data(), end = ' ')

if __name__ == '__main__':
    root = Node(1)
    root.set_left(Node(2))
    root.set_right(Node(3))
    root.left.set_left(Node(4))

    print('Inorder  Traversal:')
    inorder(root)
    print('\nPreorder Traversal:')
    preorder(root)
    print('\nPostorder Traversal:')
    postorder(root)

    # OUTPUT:
    # Inorder  Traversal:
    # 4 2 1 3
    # Preorder Traversal:
    # 1 2 4 3
    # Postorder Traversal:
    # 4 2 3 1
