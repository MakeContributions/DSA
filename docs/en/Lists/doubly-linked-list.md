# Doubly Linked List

A doubly linked list is a type of linked data structure that allows traversal in both directions (forward and backward directions). 
It differs from singly linked list in that, singly linked list does not support backward traversal. 
Every node in a doubly linked list contains a **data** part and two pointers; **next pointer** that points to the next node and the **prev pointer** that points to the previous node in the list. 
A doubly linked list also has two dummy nodes (head and tail) known as **sentinels** (guard nodes) that contains no data of the sequence. 
The first element of a doubly linked list has its prev pointer pointing to head and the last element has its next node pointing to tail. 

Without a tail pointer, you cannot directly access the last element without having to first traverse the entire list all the way from the beginning. 

## Steps to create a doubly linked list
To create an empty list,
- create head and tail nodes (nodes without data) first
- let the **next pointer** of the head point to the tail node
- let the **prev pointer** of the tail point to the head node.

For a non-empty list,
- let the next pointer of the head point to the first real element of the sequence
- let the prev pointer of the tail point to the last real element of the sequence

## Key operations
- Insertion (insert at the beginning, at the end or anywhere in the middle)
- deletion (delete from beginning, end or anywhere in the middle)

To add an element(node) at the beginning of the list, let the;
- *next pointer* of the new element (node) point to the first element (the one the *head* currently points to)
- *next pointer* of the *head* point to this new element you want to add
- *prev pointer* of the element (node) you want to add point to *head*.

To add an alement (node) to the end of the list, let the;
- *prev pointer* of the new element you want to add point to the last element (the one before the *tail*)
- *next pointer* of the last element (the one before the *tail*) point to the new element you want to add
- *prev pointer* of the *tail* point to the new element.

To delete an element from the beginning, let the;
- *next pointer* of the *head* point to the second element in the list (node after the one *head* pointers to). 
- *prev pointer* of the second element point to the *head*
 

To delete from the end of the list, let the;
- *prev pointer* of the *tail* point to the element before the last node
- *next pointer* of the element before the last node point to the *tail*

Note: If there is only one element in the list, deletion from both directions happens by pointing the *next pointer* of *head* to *tail* and *prev pointer* of *tail* to *head*. 

Deletion anywhere in the middle happens by letting the *prev pointer* and the *next pointer* of the node after and before the one you want to delete point to each other respectively.

To insert anywhere in the middle, let the;
- *next pointer* of the element you want to insert point to the node at the position you want to insert it
- *prev pointer* of the element you want to insert point to node before the position you want to insert it
- *prev pointer* of the node at the position you want to insert point to the new element
- *next pointer* of the node before the position you want to insert point to the new element.

Deletion and insertion at the beginning or end of the list is a constant operation and has a O(1) runtime. Deletion or insertion anywhere in the middle however has a O(n) runtime. 


## Implementation

- [C++](../../../algorithms/C/linked-lists/doubly-linked-list.c)
- [Java](../../../algorithms/CPlusPlus/Linked-Lists/doubly.cpp)
- [JavaScript](../../../algorithms/Java/linked-lists/doubly.java)
- [Python](../../../algorithms/Python/linked_lists/doubly.py)

## Video URL

[Doubly linked list](https://www.youtube.com/watch?v=nquQ_fYGGA4)


## References

[Goodrich, T. M., Tamassia, R., Goldwasser, M.H.(2014). *Data Structures & Algorithms in Java* (6th ed.). Wiley](https://www.wiley.com/en-us/Data+Structures+and+Algorithms+in+Java,+6th+Edition-p-9781118771334)
