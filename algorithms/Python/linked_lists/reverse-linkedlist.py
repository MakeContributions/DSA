# reverse a given linkedlist

class Node:
  # Constructor to initialize the node object
    def __init__(self, data=0, next=None):
        self.data = data
        self.next = next


class LinkedList:
    # Constructor to initialize head
    def __init__(self) -> None:
        self.head = None

     # Function to insert a new node at the beginning
    def push(self, data):
        node = Node(data)
        node.next = self.head
        self.head = node

     # Function to print the list from beginning
    def printList(self):
        temp = self.head
        while temp:
            print(temp.data, end=" ")
            temp = temp.next

    # Function to reverse the list
    def reverse(self):
        dummy = None
        cur = self.head
        while cur:
            nextTemp = cur.next
            cur.next = dummy
            dummy = cur
            cur = nextTemp
        self.head = dummy


if __name__ == '__main__':
    ll = LinkedList()
    ll.push(1)
    ll.push(2)
    ll.push(3)
    ll.push(4)
    ll.push(5)
    print("Before Reverse")
    ll.printList()
    ll.reverse()  # reversing
    print("\nAfter Reversing")
    ll.printList()
