# Create a singly linked list

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

    def __repr__(self):
        """
        >>> Node(77)
        Node(77)
        """
        return f"Node({self.data})"


class LinkedList:
    def __init__(self):
        self.head = None

    def __iter__(self):
        """
        >>> ll = LinkedList()
        >>> list(ll)
        []
        >>> ll.push(88)
        >>> tuple(ll)
        (88,)
        >>> ll.push(89)
        >>> tuple(ll)
        (89, 88)
        """
        node = self.head
        while node:
            yield node.data  # `yield node` would also be possible
            node = node.next

    def __len__(self):
        return len(tuple(iter(self)))

    def __repr__(self):
        """
        >>> ll = LinkedList()
        >>> repr(ll)
        'LinkedList()'
        >>> ll.push(99)
        >>> ll.push(100)
        >>> repr(ll)
        'LinkedList(100, 99)'
        >>> str(ll)
        'LinkedList(100, 99)'
        """
        return f"LinkedList({', '.join(str(node) for node in self)})"

    def push(self, data):
        node = Node(data)
        node.next = self.head
        self.head = node

    def pop(self):
        """
        >>> ll = LinkedList()
        >>> len(ll)
        0
        >>> ll.push("push/pop")
        >>> len(ll)
        1
        >>> ll.pop()
        'push/pop'
        >>> len(ll)
        0
        >>> ll.pop()
        Traceback (most recent call last):
            ...
        IndexError: pop from empty LinkedList
        """
        node = self.head
        if not node:
            raise IndexError("pop from empty LinkedList")
        self.head = node.next
        return node.data
    
    def insertEnd(self, data):
        '''
        Insert node at the end of linked list
        '''
        node = Node(data)
        if self.head is None:
            self.head = node
            return

        # Linked list traversal
        temp = self.head
        while(temp.next is not None):
            temp = temp.next

        temp.next = node
        return
    
    def deleteData(self, data):
        '''
        Delete first occurrence of given data
        '''
        temp = self.head
        
        # raise exception if linked list is empty
        if temp is None:
            raise Exception("Linked List is empty")

        # if head node is deleted
        if temp.data == data:
            self.head = temp.next
            temp = None
            return

        # search for data
        # previous node data is stored
        while(temp):
            found = False
            if temp.data == data:
                found = True
                break
            prev = temp
            temp = temp.next
            
        # raise exception if data not found
        if not found:
            raise Exception("Data not present")

        # delete the link
        prev.next = temp.next
        temp = None
        return


if __name__ == '__main__':
    ll = LinkedList()
    ll.push(1)
    ll.push('xyz')
    ll.push(1.1)
    ll.pop()
    ll.insertEnd('END')
    print(ll)
    ll.deleteData(1)
    print(ll)
    print(list(ll))
