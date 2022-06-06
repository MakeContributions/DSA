# Singly Linked List

A linked structure is a collection of nodes storing data and links to other nodes. In this way, nodes can be located anywhere in memory, 
and passing from one node of the linked structure to another is accomplished by storing the addresses of other nodes in the linked structure.

If a node contains a data member that is a pointer to another node, then many nodes can be strung together using only one variable to access 
the entire sequence of nodes. Such a sequence of nodes is the most frequently used implementation of a linked list, which is a data structure 
composed of nodes, each node holding some information and a pointer to another node in the list. If a node has a link only to its successor 
in this sequence, the list is called a singly linked list.

A node includes two data members: **info** and **next**. The info member is used to store information, and this member is important to the user. 
The next member is used to link nodes to form a linked list. It is an auxiliary data member used to maintain the linked list. It is indispensable 
for implementation of the linked list, but less important (if at all) from the user’s perspective.


## Steps

- New node is created.
- The number(data) is assigned to the info member of this node.
- null is assigned to next member of this node.
- The new node is included in the list by making the next member of the first node a pointer to the new node.


## Example

Now, let us create the three-nod linked list as an example. One way to create this three-node linked list is to first  generate the node for number 
8(our first data), then the node for 5(our second data), and finally the node for 2(our last data).

*pointer is represents our successor.

- In the first step, a new Node is created

  Pointer : pointer to first node. 
  
  pointer->info :		
  
  pointer->next :
  
- in the second step, the info member of this node is set to 8, and, the node’s next member is set to null. 

  pointer : pointer to first node.

  pointer->info : 8	

  pointer->next : null

- in the third step, new node is created and the info member of this node is set to 5, and, the node’s next member is set to null. 

  pointer : pointer to first node. 	

  pointer->info : 8	

  pointer->next : pointer to next node.

  Pointer->next->info : 5

  Pointer->next->next : null

- in the fourth step, new node is created and the info member of this node is set to 2, and, the node’s next member is set to null. 

  pointer : pointer to first node. 	

  pointer->info : 8	

  pointer->next : pointer to next node.

  Pointer->next->info : 5

  pointer->next->next : pointer to next node.

  pointer->next->next->info : 2

  pointer->next->next->next : null

## Implementation

- [C++](../../../algorithms/CPlusPlus/Linked-Lists/singly.cpp)
- [Java](../../../algorithms/Java/linked-lists/singly.java)
- [JavaScript](../../../algorithms/JavaScript/src/linked-lists/singly.js)
- [Python](../../../algorithms/Python/linked_lists/singly.py)

## Video URL

[Watch Linear Search Implementation](https://www.youtube.com/watch?v=HB7TcYklBHY)


## References

["Adam Drozdek", "Data Structures and Algorithms in C++", "Fourth Edition".](https://www.ebay.com/itm/Data-Structures-and-Algorithms-in-C-by-Adam-Drozdek-Fourth-Edition-/254763347609)
