//    Java implementation for folding a linked list
public static class Node {
    int data;
    Node next;
    public Node(int data){
        this.data = data;
        this.next = null;
    }
}

public static class LinkedList {
    Node head;
    Node tail;
    int size;

    public void display() {
        for (Node temp = head; temp != null; temp = temp.next) {
            System.out.print(temp.data + " ");
        }
        System.out.println();
    }

    public void addFirst(int val) {
        Node temp = new Node(val);
        temp.next = head;
        head = temp;
        if (size == 0) {
            tail = temp;
        }
        size++;
    }

    void addLast(int val) {
        Node temp = new Node(val);
        temp.next = null;
        if (size == 0) {
            head = tail = temp;
        } else {
            tail.next = temp;
            tail = temp;
        }
        size++;
    }

    Node fleft;
    private void foldhelper(Node right , int floor){
        if(right == null){
            return;
        }
        foldhelper(right.next , floor+1);
        if(floor>size/2){
            Node val = fleft.next;
            fleft.next = right;
            right.next = val;
            fleft = val;
        }
        else if(floor==size/2){
            this.tail = right;
            tail.next = null;
        }
        else{
            // do nothing
        }
    }
        
    public void fold() {
        fleft = this.head;
        foldhelper(this.head, 0);
    }
}

//Driver Code
public static void main(String[] args) throws Exception {
    LinkedList ll = new LinkedList();
    int n = 6;
    for (int i = 1; i <= n; i++) {
        ll.addLast(i);
    }
    // LinkedList --> [1,2,3,4,5,6] for n = 6

    System.out.print("Linked List before folding --> "); 
    ll.display();
    ll.fold();
    System.out.print("Linked List after folding --> "); 
    ll.display();
}

/*
    Output:-
    Linked List before folding --> 1 2 3 4 5 6 
    Linked List after folding --> 1 6 2 5 3 4
*/
