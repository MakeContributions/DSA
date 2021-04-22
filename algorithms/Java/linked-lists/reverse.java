class LinkedList{
    class Node{  
        int item;
        Node next;  
   
        public Node(int item) {  
            this.item = item;  
        }  
    }

    Node head = null;

    public void addNode(int item){
        Node newElem = new Node(item);

        if(this.head != null){
            newElem.next = this.head;
        }

        this.head = newElem;
    }

    public void reverse(){
        Node prev = null;
        Node current = this.head;
        Node next = null;

        while (current != null) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        this.head =prev;
    }

    public void print() {   
        Node current = head;  
        if(head == null) return;
        System.out.print("[ ");  
        while(current != null) {    
            System.out.print(current.item + " ");
            current = current.next;  
        } 
        System.out.println("]"); 
    }
}

public class reverse{
    
    public static void main(String [] args){
        LinkedList list = new LinkedList();

        list.addNode(2);
        list.addNode(7);
        list.addNode(1);
        list.addNode(8);
        list.addNode(5);

        System.out.print("before : \t");
        list.print();

        list.reverse();

        System.out.print("after reverse : ");
        list.print();
    }
}

/*
    to run the file :
        javac reverse.java
        java reverse
    
    results :
        before :        [ 5 8 1 7 2 ]
        after reverse : [ 2 7 1 8 5 ]
*/