import java.util.Scanner;
/* The RemoveDuplicateLL removes the duplicate elements from a singly linkedlist. In order to remove the duplicates
 we first sort the list using the merge sort. The time Complexity for the merge sort is O(n*log n) and
  space complexity is O(log n); from the sorted list to remove the duplicate elements the time complexity is O(n). */
public class RemoveDuplicateLL {
    private Node head = null;
    class Node {
        int data;
        Node next;

        public Node(int value) {
            this.data = value;
        }
    }
    /* add a single node at the head of the list */
    public void addNode(int item){
        Node addNode = new Node(item);

        if(this.head != null){
            addNode.next = this.head;
        }
        this.head = addNode;

    }

    /* To sort remove the duplicates from the linkedlist it would be better to sort it in O(n logn)*/
    Node sortedMerge(Node first, Node second) {
        Node result;
        if (first == null)
            return second;
        if (second == null)
            return first;
        /* Choose the list which contains smaller elements */
        if (first.data <= second.data) {
            result = first;
            result.next = sortedMerge(first.next, second);
        }else {
            result = second;
            result.next = sortedMerge(first, second.next);
        }
        return result;
    }

    Node mergeSortList(Node head){

        if (head == null || head.next == null) {
            return head;
        }
        Node middle = getMiddle(head);
        Node midnext = middle.next;
        middle.next = null;

        Node left = mergeSortList(head);
        Node right = mergeSortList(midnext);
        Node sortedlist = sortedMerge(left, right);
        return sortedlist;
    }

    public static Node getMiddle(Node head){
        if (head == null)
            return head;

        Node slow = head, fast = head;

        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    /* To remove the duplicates in O(n)*/
    public Node removeDuplicates() {
        if(head == null) {
            return null;
        }
        Node ptr = head;
        while (ptr.next != null) {
            if(ptr.data == ptr.next.data) {
                ptr.next = ptr.next.next;
            }else {
                ptr = ptr.next;
            }
        }
        return head;
    }


    public void print() {
        Node pointer = head;
        if(head == null) return;
        System.out.print("[ ");
        while(pointer != null) {
            System.out.print(" "+pointer.data + " ");
            pointer = pointer.next;
        }
        System.out.println("]");
    }

    public static void main(String [] args) {
        RemoveDuplicateLL list = new RemoveDuplicateLL();
        System.out.print("Enter the length of list : ");
        Scanner sc=new Scanner(System.in);
        int length = sc.nextInt();
        for(int i=0; i<length; i++) {
            list.addNode( sc.nextInt());
        }

        System.out.print("input : ");
        list.print();
        System.out.print("sorted : ");
        list.head= list.mergeSortList(list.head);
        list.print();
        System.out.print("remove duplicates : ");
        list.removeDuplicates();
        list.print();
    }
    /* Output
   input : [  2  1  0  3  1  9  0  0  9 ]
   sorted : [  0  0  0  1  1  2  3  9  9 ]
   remove duplicates : [  0  1  2  3  9 ]
     */
}
