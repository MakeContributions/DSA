# Topic - Linkedlist
# Language - Python
# Problem - Detection and Removal of Cycle in Linkedlist.
# 
# Idea - run 2 pointers at the start of the linkedlist
# increment slow pointer by one and fast pointer by two nodes.
# if slow pointer is equal to fast pointer - then cycle exist
# to remove the cycle - we need to start slow pointer to start
# and another fast pointer to same location it is pointing to
# we will stop increamenting slow pointer when slow equals to
# fast pointer and break the link from fast.next is None. 

class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

class Linkedlist:
    def __init__(self):
        self.head = None

    # pushAtStart is used to create linkedlist
    def pushAtStart(self, data):
        node = Node(data)
        node.next = self.head
        self.head = node
    

    def cycleDetectionAndRemoval(self):
        temp = self.head
        if temp is None or temp.next is None:
            return 'No Cycle Detected'
        slow_ptr = temp
        fast_ptr = temp

        while (slow_ptr and fast_ptr and fast_ptr.next):
            # moving slow pointer by one node and fast by two node.
            slow_ptr = slow_ptr.next
            fast_ptr = fast_ptr.next.next

            # if slow equals to fast, then we have encountered cycle
            if slow_ptr == fast_ptr:
                slow_ptr = temp

                while slow_ptr != fast_ptr:
                    slow_ptr = slow_ptr.next
                    fast_ptr = fast_ptr.next

                # removing cycle
                fast_ptr.next = None
                return 'Cycle Detected and Removed'
        return 'No Cycle Detected'

if __name__ == '__main__':

    # creating linkedlist
    mylist = Linkedlist()

    # adding nodes
    mylist.pushAtStart(10)
    mylist.pushAtStart(20)
    mylist.pushAtStart(30)
    mylist.pushAtStart(40)
    mylist.pushAtStart(50)

    # creating cycle
    mylist.head.next.next.next.next.next = mylist.head.next.next

    # removing cycle
    print(mylist.cycleDetectionAndRemoval())

    # after removing cycle we don't have cycle
    print(mylist.cycleDetectionAndRemoval())
