public class DoublyLinkedList {
    static class Node{
        int data;
        Node previous;
        Node next;
        public Node(int data){
            this.data=data;
        }
    }
    Node head,tail=null;

    public void addInLast(int data){
        Node newNode = new Node(data);
        if(head==null){
            //both head and tail will point to newNode
            head=tail=newNode;
            head.previous=null;
            tail.next=null;
        }
        else{
            tail.next=newNode;
            newNode.previous=tail;
            tail=newNode;
        }
    }
    public void addAtFirst(int data){
        Node newNode = new Node(data);
        if(head==null){
            //both head and tail will point to newNode
            head=tail=newNode;
            head.previous=null;
            tail.next=null;
        }
        else{
            newNode.next=head;
            head.previous=newNode;
            head=newNode;
        }
    }
    public void addAtPos(int data,int pos){
        Node temp=head;

        Node newNode = new Node(data);
        if(head==null){
            //both head and tail will point to newNode
            head=tail=newNode;
            head.previous=null;
            tail.next=null;
        }
        else{
            Node temp1=head.next;
            int i=0;
            while(i<pos){
                temp=temp.next;
                temp1=temp1.next;
                i++;
            }
            temp.next=newNode;
            newNode.previous=temp;
            newNode.next=temp1;
            temp1.previous=newNode;
        }
    }
    public void deleteLast(){

        if(head==null){
            System.out.println("the list is empty");
        }
        else {
            tail=tail.previous;
            tail.next=null;
        }
    }
    public void deleteFirst(){

        if(head==null){
            System.out.println("the list is empty");
        } else if (head==tail) {
            tail=head=null;
        } else {
            head=head.next;
            head.previous=null;
        }
    }
    public void display(){
        if(head==null){
            System.out.println("list is empty");
        }
        Node curr=head;
        while(curr!=null){
            System.out.print(curr.data+"->");
            curr=curr.next;
        }
        System.out.print("NULL");
        System.out.println();
    }

    public static void main(String[] args) {
        DoublyLinkedList list1=new DoublyLinkedList();
        list1.addInLast(1);
        list1.addInLast(2);
        list1.addInLast(3);
        list1.addInLast(4);
        list1.addInLast(5);
        list1.addAtFirst(6);
        list1.addAtFirst(7);
        list1.addAtFirst(8);
        list1.addAtPos(0,2);
        list1.display();  //list after inserting the elements 
        list1.deleteFirst();
        list1.deleteFirst();
        list1.display();  // list after deleting 1st node
        list1.deleteLast();
        list1.display(); // list after deleting last node 
    }
}

/*
output :
8->7->6->0->1->2->3->4->5->NULL
6->0->1->2->3->4->5->NULL
6->0->1->2->3->4->NULL
*/
