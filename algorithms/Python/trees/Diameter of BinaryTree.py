# Python3 program to find the diameter of binary tree
 
# A binary tree node
class Node:
 
    # Constructor to create a new node
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
 
 
 
# The function Compute the "height" of a tree. Height is the
# number of nodes along the longest path from the root node
# down to the farthest leaf node.
 
def height(node):
 
    # Base Case : Tree is empty
    if node is None:
        return 0
 
    # If tree is not empty then height = 1 + max of left
    # height and right heights
    return 1 + max(height(node.left), height(node.right))
 
# Function to get the diameter of a binary tree
def diameter(root):
 
    # Base Case when tree is empty
    if root is None:
        return 0
 
    # Get the height of left and right sub-trees
    lheight = height(root.left)
    rheight = height(root.right)
 
    # Get the diameter of left and right sub-trees
    ldiameter = diameter(root.left)
    rdiameter = diameter(root.right)
 
    # Return max of the following tree:
    # 1) Diameter of left subtree
    # 2) Diameter of right subtree
    # 3) Height of left subtree + height of right subtree +1
    return max(lheight + rheight + 1, max(ldiameter, rdiameter))
 
 
# Driver Code
"""
Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
"""
 
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
 
# Function Call
print(diameter(root))
 
