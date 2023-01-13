"""
Data Structure : Binary Tree
Algorithm : Binary Tree Traversals (Pre-Order, In-Order, Post-Order)
Time Complexity : O(n)
Space Complexity: O(n) (Auxiliary space)
"""
from typing import Optional, Union
from queue import Queue, LifoQueue


class BinaryTreeNode:
    """
    Class to represent Binary Tree Node.
    Attributes:
        - data (int) : The data stored in the `BinaryTreeNode`.
        - leftChild (BinaryTreeNode) : The left child of the current node.
        - rightChild (BinaryTreeNode) : The right child of the current node.
    """
    def __init__(self, data: int) -> None:
        self.data = data
        self.leftChild: Optional[BinaryTreeNode] = None
        self.rightChild: Optional[BinaryTreeNode] = None


class BinaryTree:
    """
    Class to represent Binary Tree.
    Attributes:
        - root (BinaryTreeNode) : The root of the Binary Tree.
    """
    def __init__(self):
        self.root: Optional[BinaryTreeNode] = None

    def insert(self, value: int) -> str:
        """
        Create a `BinaryTreeNode` with the `value` and insert the node at the
        vacant place in the Binary Tree.

        NOTE : The vacant place can be found using level order traversal.
        Also, we need queue for level order traversal.

        :param value: The value of the `BinaryTreeNode`.
        :return: A meaningful message to the user of the program.
        """
        if not self.root:
            self.root = BinaryTreeNode(value)
        else:
            # Creating the FIFO (Queue) for level order traversal
            auxQueue = Queue()
            auxQueue.put(self.root)

            while not auxQueue.empty():
                currentNode = auxQueue.get()

                # Check if current node has vacant place.
                if currentNode.leftChild is None:
                    currentNode.leftChild = BinaryTreeNode(value)
                    break
                else:
                    auxQueue.put(currentNode.leftChild)

                if currentNode.rightChild is None:
                    currentNode.rightChild = BinaryTreeNode(value)
                    break
                else:
                    auxQueue.put(currentNode.rightChild)

        return "The value inserted successfully in the Binary Tree."


class RecursiveTraversal:
    """Class to represent Recursive Traversals of the Binary Tree."""
    def preOrder(self, root: BinaryTreeNode, result: list) -> Union[None, list]:
        if not root:
            return
        else:
            result.append(root.data)
            self.preOrder(root.leftChild, result)
            self.preOrder(root.rightChild, result)

        return result

    def inOrder(self, root: BinaryTreeNode, result: list) -> Union[None, list]:
        if not root:
            return
        else:
            self.inOrder(root.leftChild, result)
            result.append(root.data)
            self.inOrder(root.rightChild, result)

        return result

    def postOrder(self, root: BinaryTreeNode, result: list) -> Union[None, list]:
        if not root:
            return
        else:
            self.postOrder(root.leftChild, result)
            self.postOrder(root.rightChild, result)
            result.append(root.data)

        return result


class IterativeTraversal(BinaryTree):
    """Class to represent Iterative Traversal for Binary Tree."""

    def preOrder(self) -> Union[str, list]:
        result = []

        if not self.root:
            return "The Binary Tree is Empty."
        else:
            auxStack = LifoQueue()
            auxStack.put(self.root)

            while not auxStack.empty():
                currentNode = auxStack.get()
                result.append(currentNode.data)

                # Process right node then left node of the tree.
                if currentNode.rightChild:
                    auxStack.put(currentNode.rightChild)

                if currentNode.leftChild:
                    auxStack.put(currentNode.leftChild)

        return result

    def inOrder(self) -> Union[str, list]:
        result = []

        if not self.root:
            return "The Binary Tree is Empty."
        else:
            auxStack = LifoQueue()
            currentNode = self.root

            while currentNode or not auxStack.empty():
                # Process the left node
                if currentNode:
                    auxStack.put(currentNode)
                    currentNode = currentNode.leftChild
                else:
                    # Process the right node
                    currentNode = auxStack.get()
                    result.append(currentNode.data)
                    currentNode = currentNode.rightChild

        return result

    def postOrder(self) -> Union[str, list]:
        result = []

        if not self.root:
            return "The Binary Tree is Empty."
        else:
            auxStack = []
            previous: Optional[BinaryTreeNode] = None
            currentNode = self.root

            while currentNode or auxStack:
                # Process the left node
                while currentNode:
                    auxStack.append(currentNode)
                    currentNode = currentNode.leftChild

                currentNode = auxStack[-1]

                # Process the current node if it is the second visit.
                if not currentNode.rightChild or previous == currentNode.rightChild:
                    previous = auxStack.pop()
                    result.append(previous.data)
                    currentNode = None
                else:
                    currentNode = currentNode.rightChild

        return result


if __name__ == "__main__":

    bTree = IterativeTraversal()
    # Create Binary Tree with random values
    testValues = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    for value in testValues:
        bTree.insert(value)

    print("Iterative Outputs")
    print(bTree.preOrder())
    print(bTree.inOrder())
    print(bTree.postOrder())

    print("\nRecursive Outputs")
    recursion = RecursiveTraversal()
    print(recursion.preOrder(bTree.root, []))
    print(recursion.inOrder(bTree.root, []))
    print(recursion.postOrder(bTree.root, []))
