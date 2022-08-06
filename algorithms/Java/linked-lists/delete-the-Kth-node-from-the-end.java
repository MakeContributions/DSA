

    class LinkedList 
    { 
    Node head; 
    class Node 
    { 
        int data; 
        Node next; 
        Node(int d) 
        { 
            data = d; 
            next = null; 
        } 
    } 
    public void push(int new_data) 
    { 
        Node new_node = new Node(new_data); 
        new_node.next = head; 

        head = new_node; 
    } 
     //this function will delete the kth node in list
    void deleteNode(int position) 
    { 
     
       //if linked list is empty then return
        if (head == null) 
            return;  
        
        Node temp = head; 
        if (position == 0) 
        { 
            head = temp.next; 
            return; 
        } 
        for (int i=0; temp!=null && i<position-1; i++) 
            temp = temp.next;  
        if (temp == null || temp.next == null) 
            return; 

        Node next = temp.next.next; 

        temp.next = next; 
    } 
    public void printList() 
    { 
        Node tnode = head; 
        while (tnode != null) 
        { 
            System.out.print(tnode.data+" "); 
            tnode = tnode.next; 
        } 
    } 
    public static void main(String[] args) 
    { 
      LinkedList k_List = new LinkedList();  
        k_List.addNode(1);  
        k_List.addNode(2);  
        k_List.addNode(3);  
        k_List.addNode(4);  
        k_List.addNode(5);
      k_List.addNode(6);
        for(int i=n-1;i>=0;i--)
            {
                llist.push(p[i]); 
            }
          //this will delete the kth node
        llist.deleteNode(k-1);  
        //this will print the linked list after deleteion
        llist.printList(); }
    } 
     } 

/* Given: 1->2->3->4->5->6
K=3

after deletion:
1->2->3->5->6

4 is the third last node from the end of linked list. */
