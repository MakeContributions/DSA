class Node<T> {
    T data;
    Node<T> next;

    Node(T data) {
        this.data = data;
        this.next = null;
    }
}

public class SinglyLinkedList<T> {
    Node<T> head;

    SinglyLinkedList() {
        this.head = null;
    }

    void insertAtHead(T data) {
        Node<T> newNode = new Node<T>(data);
        if(this.head == null) {
            this.head = newNode;
        } else {
            newNode.next = this.head;
            this.head = newNode;
        }
    }

    T removeAtHead() {
        if(this.head == null) {
            System.out.println("Underflow");
            System.exit(1);
        }
        T data = this.head.data;
        this.head = this.head.next;
        return data;
    }

    void printList() {
        if(this.head == null) {
            System.out.println("List is Empty");
        } else {
            Node<T> itr = this.head;
            while(itr != null) {
                System.out.print(itr.data + " ");
                itr = itr.next;
            }
            System.out.println("");
        }
    }

    // Test Code
    public static void main(String... args) {
        SinglyLinkedList<String> l = new SinglyLinkedList<String>();
        l.insertAtHead("abc");
        l.insertAtHead("pqr");
        l.insertAtHead("xyz");
        l.removeAtHead();
        l.printList();
    }
}
