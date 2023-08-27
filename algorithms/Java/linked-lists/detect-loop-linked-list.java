/*

Let us assume that we have a Singly Linked List as follows:

1 --> 2 --> 3 --> 4
            ^     |
            |     |
            |     v
            6 <-- 5
            
As we can see, there is a loop that exists within this singly linked list. 

One way of detecting this loop is to use a HashMap.
You keep on traversing through the list and keep on adding each element in the HashMap.
HashMap has a useful property: you cannot add a duplicate element.
This means if a node cannot be added to the HashMap, it implies that the node is already present there, and thus the cycle is detected.

However, using a HashMap takes up space in the memory. In this case, both the time complexity and the space complexity becomes O(n).

This is where Floyd's Cycle Detection comes handy.

Floyd's Cycle Detection is an algorithm that basically provides a way to detect a loop without using HashMap. Therefore, the space complexity becomes O(1), while time complexity is O(n).

This algorithm uses 2 pointers to traverse through the list- a fast pointer and a slow pointer. Both the fast and the slow pointers start at the head(the starting node). The difference lies in the fact that a slow pointer moves one step at a time, and a fast pointer moves two steps at a time.
This means that by the time the slow pointer reaches the loop, the fast pointer is already inside the loop.
There has to be an instance when both the fast and slow pointers point to the same node other than head. This is when the loop is detected. 

If the fast pointer reaches null(the value that is pointed to by the last node), then it means that there is no cycle in the list.
*/
public class DetectLoopSLL
{
  private ListNode head;
  private class ListNode<T>
  {
    private T data;
    private ListNode<T> next;
    public ListNode(T data)
    {
      this.data = data;
      this.next = null;
    }
  }
  
  public boolean detectLoop() // Detecting whether there is a loop or not
  {
    ListNode fastPointer = head;
    ListNode slowPointer = head;
    while(fastPointer != slowPointer && fastPointer.next != null)
    {
      fastPointer = fastPointer.next.next;
      slowPointer = slowPointer.next;
      if(slowPointer == fastPointer)
        return true;
    }
    return false;
  }// End of detectLoop()
  
  public ListNode startingNodeOfLoop() // Detecting and Returning the starting node of the loop
  {
    ListNode fastPointer = head;
    ListNode slowPointer = head;
    while(fastPointer != slowPointer && fastPointer.next != null)
    {
      fastPointer = fastPointer.next.next;
      slowPointer = slowPointer.next;
      if(slowPointer == fastPointer)
      {
        ListNode temp = head;
        while(temp != slowPointer)
        {    
          temp = temp.next;
          slowPointer = slowPointer.next;
        }
        return temp; // starting node of loop
      }
    }
    return null;
  }// End of startingNodeOfLoop()
  public static void main(String[] args)
  {
            DetectLoopSLL linkedList = new DetectLoopSLL();
            DetectLoopSLL.ListNode<Integer> node1 = linkedList.new ListNode<>(1);
            DetectLoopSLL.ListNode<Integer> node2 = linkedList.new ListNode<>(2);
            DetectLoopSLL.ListNode<Integer> node3 = linkedList.new ListNode<>(3);
            DetectLoopSLL.ListNode<Integer> node4 = linkedList.new ListNode<>(4);
            DetectLoopSLL.ListNode<Integer> node5 = linkedList.new ListNode<>(5);
            linkedList.head = node1;
            node1.next = node2;
            node2.next = node3;
            node3.next = node4;
            node4.next = node5;
            node5.next = node2; // Creating a loop by pointing the last node to the second node
            // Detect loop and display result
            if (linkedList.detectLoop()) {
            System.out.println("Loop detected");
            } else {
            System.out.println("No loop detected");
            }
            DetectLoopSLL.ListNode<Integer> loopNode = linkedList.startingNodeOfLoop()
            System.out.println("Node from where the loop starts: " + loopNode.data);
            }
}


/*
Input: 
1 --> 2 --> 3 
      ^     |
      |     |
      |     v
      5  <--4


Output:
Loop Detected
Node from where the loop starts: 2
*/
