class CircularLinkedList{
    class Node {
        int value;
        Node next;

        public Node(int value) {
            this.value = value;
        }
    }

    private Node head = null;
    private Node tail = null;

    public void addNode(int value) {
        Node newNode = new Node(value);

        if (head == null) {
            head = newNode;
        } else {
            tail.next = newNode;
        }

        tail = newNode;
        tail.next = head;
    }
    public void printNodes() {  
        Node current = head;  
        if(head == null) {  
            System.out.println("List is empty");
            return;  
        }    
        System.out.println("The circular linked list is: "); 
        System.out.print("[ "); 
        do{   
            System.out.print(current.value + " ");  
            current = current.next;
            //go to next until we get back to the head 
        }while(current != head);
        System.out.println("]"); 
    }
}

public class circular {
    public static void main(String [] args){
        CircularLinkedList cll = new CircularLinkedList();

        cll.addNode(10);
        cll.addNode(12);
        cll.addNode(2);
        cll.addNode(1);
        cll.addNode(8);
        cll.addNode(42);
        cll.addNode(17);

        cll.printNodes();

        //this will print :
        /*
            The circular linked list is: 
            [ 10 12 2 1 8 42 17 ]
        */
    }
}

/*
    to run the file:
    javac circular.java
    java circular
*/