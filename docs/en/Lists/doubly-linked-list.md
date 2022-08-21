# Doubly Linked List

A doubly linked list is a type of linked data structure that allows traversal in both directions (forward and backward directions). It differs from singly linked list in that, singly linked list does not support backward traversal. Every node in a doubly linked list contains a **data** part and two pointers; **next pointer** that points to the next node and the **prev pointer** that points to the previous node in the list. A doubly linked list also has two dummy nodes (head and tail) known as **sentinels** (guard nodes) that contains no data of the sequence. The first element of a doubly linked list has its prev pointer pointing to head and the last element has its next node pointing to tail. 

Without a tail pointer, you cannot directly access the last element without having to first traverse the entire list all the way from the beginning. 
![doubly linked list](https://github.com/Ayebilla/project/blob/main/doubly-linked-list.PNG?raw=true)

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

Deletion and insertion at the beginning or end of the list is a constant operation and has a O(1) runtime. Deletion or insertion anywhere in the middle however has a O(n) runtime. 


## Implementation

- [C++](../../../algorithms/C/linked-lists/doubly-linked-list.c)
- [Java](../../../algorithms/CPlusPlus/Linked-Lists/doubly.cpp)
- [JavaScript](../../../algorithms/Java/linked-lists/doubly.java)
- [Python](../../../algorithms/Python/linked_lists/doubly.py)

## Video URL

[Doubly linked list](https://www.youtube.com/watch?v=nquQ_fYGGA4)


## References

Goodrich, T. M., Tamassia, R., Goldwasser, M.H.(2014). *Data Structures & Algorithms in Java* (6th ed.). Wiley