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


if __name__ == '__main__':
    ll = LinkedList()
    ll.push(1)
    ll.push('xyz')
    ll.push(1.1)
    ll.pop()
    print(ll)
    print(list(ll))
