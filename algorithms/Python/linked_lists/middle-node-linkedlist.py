#printing middle node element of linked list
#we are using two pointer method to get the solution

class Node:
    #Constructor to build node
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    #Constructor to create head node
    def __init__(self):
        self.head = None

    #Function to push element at head (at beginning)
    def push(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node
    
    #Function returns data of middle node
    def middle_element(self):
        if self.head is None:
            return None
        slow = self.head
        fast = self.head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow.data

if __name__=='__main__':
    ob = LinkedList()
    ob.push(5)
    ob.push(4)
    ob.push(3)
    ob.push(2)
    ob.push(1)
    print(ob.middle_element())
    
    #list: 1->2->3->4->5 Hence middle element is 3


