# Circular Linked List

A Circular Linked List is a type of linked list where the last node points back to the first node, forming a circle. This structure allows for an efficient circular traversal of the list, making it particularly useful in applications where the list needs to be looped over repeatedly.

## Structure

Each node in a Circular Linked List contains at least two parts:

1. **Data**: The value or data that is stored in the node.
2. **Next**: A pointer or reference to the next node in the list.

The "Next" of the last node in the list points to the first node, creating a circular structure.

## Operations

### Initialization

To initialize an empty Circular Linked List:

```plaintext
LinkedList() {
    head = null;
}
```

### Insertion

There are several ways to insert a new node into a Circular Linked List:

- **At the beginning**:
  Insert a new node before the current head and make the new node as the head of the list.

- **At the end**:
  Insert a new node after the current last node, which requires traversing the list to find the last node.

- **After a given node**:
  Insert a new node after a specified node in the list.

### Deletion

Nodes can be deleted from a Circular Linked List by adjusting the pointers of the adjacent nodes. The node to be deleted is identified either by its value or by its position in the list.

### Traversal

To traverse a Circular Linked List, start from the head and move along the list using the "Next" pointers until you reach the head again.

## Example

Here's a simple example of a Circular Linked List in Python:

```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class CircularLinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        newNode = Node(data)
        if not self.head:
            self.head = newNode
            self.head.next = self.head
        else:
            temp = self.head
            while temp.next != self.head:
                temp = temp.next
            temp.next = newNode
            newNode.next = self.head

    def display(self):
        nodes = []
        temp = self.head
        while temp and (temp not in nodes):
            nodes.append(temp)
            temp = temp.next
            if temp == self.head:
                break
        for node in nodes:
            print(node.data, end=" -> ")
        print("Back to Head")

```

## Applications

Circular Linked Lists are used in applications where a circular traversal of data is required, such as implementing round-robin scheduling, multiplayer games, and cyclically rotating arrays.

## Conclusion

Circular Linked Lists provide a flexible and efficient structure for circular data organization and traversal. Understanding how to implement and manipulate these lists is crucial for solving specific algorithmic problems where circular data representation is beneficial.
