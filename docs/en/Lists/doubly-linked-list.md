# Doubly Linked List

A doubly linked list is a type of list that allows traversal in both directions (forward and backward directions). It differs from singly linked list in that, singly linked list does not support backward traversal. Every node in a doubly linked list contains a **data** part and two pointers; **next pointer** that points to the next node and the **prev pointer** that points to the previous node in the list. A doubly linked list also has a **head pointer** (not a node) that points to the first element in the list. The first element of a doubly linked list has its prev pointer pointing to null (there is no node before the first node) and the last element has its next node pointing to null (no node after the last node). 
Note: Though the **head pointer** doesn't contain any data, if you remove it from the doubly linked list, your list will be lost as you will have no way to track it. 

For faster traversal, a **tail pointer** is normally added which points to the last element of the list. without a tail pointer, you cannot directly access the last element without having to first traverse the entire list all the way from the beginning. 


## Steps to create a doubly linked list
A doubly linked list can have one or more elements. start with a single node list and then add elements at the beginning to grow the list.
create a new node. 
    If this is the first or the only node in the list,let:
    - prev point to null
    - next point to null
    -head point to this new node
    If it is not the first, let:
      - next point to first element (i.e head.next)
      - prev point to null
      - head point to this new node


- 2. 
- null is assigned to next member of this node.
- The new node is included in the list by making the next member of the first node a pointer to the new node.


## Example


## Implementation

- [C++](../../../algorithms/C/linked-lists/doubly-linked-list.c)
- [Java](../../../algorithms/CPlusPlus/Linked-Lists/doubly.cpp)
- [JavaScript](../../../algorithms/Java/linked-lists/doubly.java)
- [Python](../../../algorithms/Python/linked_lists/doubly.py)

## Video URL

[Doubly linked list](https://www.youtube.com/watch?v=nquQ_fYGGA4)


## References

Goodrich, T. M., Tamassia, R., Goldwasser, M.H.(2014)., *Data Structures & Algorithms in Java* (6th ed).Wiley