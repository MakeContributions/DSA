"""
Data Structure : Circular Linked List.
Time Complexity : O(1) for all operations.
Space Complexity : O(n) Where, 'n' is the number of nodes in the linked list.
"""
from typing import Optional

class Node:
    """
    Class to represent a Node.
    Attributes:
        - value (int) : The value of the node.
        - next (Node) : The reference of the next node.
    """

    def __init__(self, value: int):
        self.value = value
        self.next:Optional[Node] = None


class CircularLinkedList:
    """
    CLass to represent circular linked list and perform its operations.
    Attributes:
        - head (Node) : The first node in the linked list.
        - tail (Node) : The last node in the linked list.
    """

    def __init__(self):
        self.head = None
        self.tail = None

    def __iter__(self):
        trackNode = self.head
        while trackNode.next != self.head:
            yield trackNode.value
            trackNode = trackNode.next
        yield trackNode.value

    def __str__(self):
        result = ""
        for value in self:
            result += f'{value} -> '

        return result

    def isEmpty(self) -> bool:
        """Return 'True' if the circular linked list is Empty. Otherwise, return 'False'."""
        if self.head is None:
            return True
        else:
            return False

    def insertNode(self, value: int, location: int = -1) -> None:
        """
        Insert the node at the given location. Default in the end.
        Args:
            - value (int): The value of the node.
            - location (int): The position of the node to insert into the linked list.
                - 0 : At the beginning.
                - -1 : At the end.
                - Any `int` : At the specified location.
        """

        newNode = Node(value)

        # Insertion at the beginning of the circular linked list.
        if location == 0:
            if not self.isEmpty():
                self.head = newNode
                newNode.next = self.tail.next
                self.tail.next = self.head
            else:
                self.head = self.tail = newNode
                newNode.next = newNode

        # Insertion at the end of the circular linked list.
        elif location == -1:
            if not self.isEmpty():
                newNode.next = self.tail.next
                self.tail.next = newNode
                self.tail = newNode
            else:
                self.head = self.tail = newNode
                newNode.next = newNode
        else:
            trackLocation = 0
            trackNode = self.head

            while trackLocation < trackLocation - 1:
                trackNode = trackNode.next
                trackLocation += 1

            nextNode = trackNode.next
            trackNode.next = newNode
            newNode.next = nextNode

    def deleteNode(self, value: int) -> None:
        """
        Delete the node if the value exist in the linked list.
        Args:
            - value (int) : The value of the node.
        """
        if not self.isEmpty():
            trackNode = self.head
            previousNode:Optional[Node] = None
            while trackNode.value != value:
                previousNode = trackNode
                trackNode = trackNode.next

            if trackNode == self.head:
                self.head = self.head.next
                self.tail.next = self.head
            elif trackNode == self.tail:
                previousNode.next = self.head
            else:
                previousNode.next = trackNode.next
        else:
            print("The linked list is Empty.")


# TESTING THE CIRCULAR LINKED LIST
cll = CircularLinkedList()
cll.insertNode(10)
cll.insertNode(20)
cll.insertNode(1000, 1)
cll.insertNode(20)

cll.deleteNode(1000)
print(cll)
