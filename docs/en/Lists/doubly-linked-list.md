# Doubly Linked List

A doubly linked list is a type of linked data structure that allows traversal in both directions (forward and backward directions). It differs from singly linked list in that, singly linked list does not support backward traversal. Every node in a doubly linked list contains a **data** part and two pointers; **next pointer** that points to the next node and the **prev pointer** that points to the previous node in the list. A doubly linked list also has two dummy nodes (head and tail) known as **sentinels** (guard nodes) that contains no data of the sequence. The first element of a doubly linked list has its prev pointer pointing to head and the last element has its next node pointing to tail. 

Without a tail pointer, you cannot directly access the last element without having to first traverse the entire list all the way from the beginning. 
![doubly linked list](https://github.com/Ayebilla/project/blob/main/doubly-linked-list.PNG?raw=true)

## Steps to create a doubly linked list
A doubly linked list can have one or more elements. start with a single node list and then add elements at the beginning to grow the list.
create a new node. 

If this is the first or the only node in the list,let:
  - prev point to null
  - next point to null
  - head point to this new node
If it is not the first, let:
  - next point to first element (i.e head.next)
  - prev point to null
  - head point to this new node

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