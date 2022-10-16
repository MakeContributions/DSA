 class circularll {
        Node head;
        Node tail;
        class Node{
            int data;
            Node next;

            Node(int data){
                this.data=data;
                this.next=null;
            }
        }
  
   //add() function add element to the rear of the linkedlist
        public void add(int data){
            Node newNode = new Node(data);
            if(head==null){
                head=tail=newNode;
            }
            else{
                tail.next=newNode;
                tail=tail.next;
            }
            tail.next=head;
        }
  
   //display() function to show elements of linkedlist
        public void display(){
            System.out.printf("\nThe Linkedlist is ");
            Node temp=head;
            do{
                System.out.print(temp.data+" ");
                temp=temp.next;
            }while (temp!=head);
        }

   //search() function searches the element in the linkedlist
    public void search(int target){
        int flag=0;
        Node temp=head;
        do{
           if(target==temp.data){
               System.out.print("\nTarget is found");
               flag=1;
               break;
           }
            temp=temp.next;
        }while (temp!=head);

        if (flag==0)
            System.out.print("\nTarget Not Found");
    }
   
   
    // addfront() function added a element to the front of the circular singly linkedlist
        public void addfront(int data){
            Node newNode = new Node(data);
            newNode.next=head;
            head=newNode;
            tail.next=head;
        }

   //reverse() function is reversing the circular singly linkedlist
        public void reverse(){
            Node previous=tail;
            Node current=head,nextnode = head;


            do{
                nextnode=current.next;
                current.next=previous;

                previous=current;
                current=nextnode;

            }while(current!=head);

            tail=head;
            head=previous;
            tail.next=head;

        }

        public static void main(String[] args) {
            System.out.println("LinkedList");
            circularll ll = new circularll();
            ll.add(5);
            ll.add(8);
            ll.add(7);
            ll.add(1);
            ll.add(2);
            ll.display();
            ll.addfront(9);
            ll.display();
            ll.search(2);
            ll.search(4);
            ll.reverse();
            ll.display();

        }
    }



/*

OUTPUT: 

    LinkedList

The Linkedlist is 5 8 7 1 2 
The Linkedlist is 9 5 8 7 1 2 
Target is found
Target Not Found
The Linkedlist is 2 1 7 8 5 9 

*/

// Here initial linkedlist was 9 5 8 7 1 2 and after using reverse function the linkedlist become 2 1 7 8 5 9
