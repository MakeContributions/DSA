class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

    def __repr__(self):
        """
        >>> Node(77)
        Node(77)
        """
        return f"Node({self.data})"


class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def __iter__(self):
        """
        >>> dll = DoublyLinkedList()
        >>> list(dll)
        []
        >>> dll.push(88)
        >>> tuple(dll)
        (88,)
        >>> dll.push(89)
        >>> tuple(dll)
        (89, 88)
        """
        node = self.head
        while node:
            yield node.data
            node = node.next

    def __repr__(self):
        """
        >>> dll = DoublyLinkedList()
        >>> repr(dll)
        'DoublyLinkedList()'
        >>> dll.push(99)
        >>> dll.push(100)
        >>> repr(dll)
        'DoublyLinkedList(100, 99)'
        >>> str(dll)
        'DoublyLinkedList(100, 99)'
        """
        return f"DoublyLinkedList({', '.join(str(node) for node in self)})"

    # Adding data elements is like pushing onto a stack
    def push(self, data):
        node = Node(data)
        node.next = self.head
        if self.head:
            self.head.prev = node
        self.head = node


if __name__ == "__main__":
    dllist = DoublyLinkedList()
    for i in 12, 8, 62:
        dllist.push(i)
    print(dllist)        # DoublyLinkedList(62, 8, 12)
    print(list(dllist))                  # [62, 8, 12]
    print(list(reversed(list(dllist))))  # [12, 8, 62]
    print(sorted(dllist))                # [8, 12, 62]
