class DoublyLinkedList {    
    class Node{  
        int item;  
        Node previous;  
        Node next;  
   
        public Node(int item) {  
            this.item = item;  
        }  
    }  

    Node head, tail = null;  
    
    public void addNode(int item) { 
        Node newNode = new Node(item);  
   
        //if list is empty, head and tail points to newNode  
        if(head == null) {  
            head = tail = newNode;  
            //head's previous will be null  
            head.previous = null;  
            //tail's next will be null  
            tail.next = null;  
        }  
        else {  
            //add newNode to the end of list. tail->next set to newNode  
            tail.next = newNode;  
            //newNode->previous set to tail  
            newNode.previous = tail;  
            //newNode becomes new tail  
            tail = newNode;  
            //tail's next point to null  
            tail.next = null;  
        }  
    }  
     
    public void printNodes() {   
        Node current = head;  
        if(head == null) {  
            System.out.println("Doubly linked list is empty");  
            return;  
        }  
        System.out.println("The doubly linked list is: ");
        System.out.print("[ ");  
        while(current != null) {    
            System.out.print(current.item + " ");
            //go to next  
            current = current.next;  
        } 
        System.out.print("]"); 
    }  
}
 
public class doubly {
    public static void main(String [] args){
        DoublyLinkedList dl_List = new DoublyLinkedList();  
        
        dl_List.addNode(5);  
        dl_List.addNode(7);  
        dl_List.addNode(1);  
        dl_List.addNode(17);  
        dl_List.addNode(27);  
   
        dl_List.printNodes();
        //this will print :
        /*
        The doubly linked list is: 
        [ 5 7 1 17 27 ]
        */
    }
}

/*
    to run the file:
    javac doubly.java
    java doubly
*/