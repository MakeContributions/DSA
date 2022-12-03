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

    /* Sort  the list using merge sort it O(n logn)*/
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

    /* To sort remove the duplicates in O(n)*/
    public Node removeDuplicates(Node head) {
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
            System.out.print(pointer.data + " ");
            pointer = pointer.next;
        }
        System.out.println("]");
    }

    public static void main(String [] args) {
        RemoveDuplicateLL list = new RemoveDuplicateLL();
        list.addNode(9);
        list.addNode(2);
        list.addNode(7);
        list.addNode(1);
        list.addNode(8);
        list.addNode(3);
        list.addNode(7);
        list.addNode(5);
        list.addNode(4);
        list.addNode(8);
        list.addNode(1);

        System.out.print("input : ");
        list.print();
        System.out.print("sorted : ");
        list.mergeSortList(list.head);
        list.print();
        System.out.print("remove duplicates : ");
        list.removeDuplicates(list.head);
        list.print();
    }
    /* Output
    input : [ 1 8 4 5 7 3 8 1 7 2 9 ]
    sorted : [ 1 1 2 3 4 5 7 7 8 8 9 ]
    remove dupliactes : [ 1 2 3 4 5 7 8 9 ]
     */
}
