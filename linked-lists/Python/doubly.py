class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

    def __repr__(self):
        return f"Node({self.data})"


class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def __iter__(self):
        node = self.head
        while node:
            yield node.data
            node = node.next

    def __repr__(self):
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
