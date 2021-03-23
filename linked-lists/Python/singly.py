# A simple Python program to create a singly linked list 
  
# Node class 
class Node: 
  
    # Function to initialise the node object 
    def __init__(self, data): 
        self.data = data  # Assign data 
        self.next = None  # Initialize next as null 
  
  
# Linked List class contains a Node object 
class LinkedList: 
  
    # Function to initialize head 
    def __init__(self): 
        self.head = None

    
    # Function to insert a new node at the beginning 
    def insertAtHead(self, new_data): 
    
        # 1 & 2: Allocate the Node & 
        #        Put in the data 
        new_node = Node(new_data) 
            
        # 3. Make next of new Node as head 
        new_node.next = self.head 
            
        # 4. Move the head to point to new Node  
        self.head = new_node 
    def removeAtHead(self):
        temp = self.head 
 
        # If head node itself holds the key to be deleted 
        if (temp is not None): 
            self.head = temp.next
            temp = None
            return
        else:
            return('underflow')
    def printList(self): 
        temp = self.head 
        while(temp): 
            print (temp.data)
            temp = temp.next

  
  
# Code execution starts here 
if __name__=='__main__':
    l=LinkedList()
    l.insertAtHead(1);
    l.insertAtHead('xyz');
    l.insertAtHead(1.1);
    l.removeAtHead();
    l.printList()

