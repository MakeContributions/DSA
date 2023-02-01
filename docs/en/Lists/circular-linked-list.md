
# Circular Linked List

A linked list in which the last node points to the first node is called a circular linked list. Each node in circular linked list includes data(value that a node holds) and next(address of next node). 

## How to create a Circular Linked List?
1. Create a node, store a value in it and points it to next address.
2. If there is only one node in list, then it points to itself as the next node is itself. If more than one, then each node stores address of next node.
The below mentioned code shows implementation of circular linked list. The traversal function is used to display the values of circular linked list.
```bash
#include <iostream>
using namespace std;

class node
{
public:
    int value;
    node *next;
};

void transverse_linkedlist(node *head)    //display function
{
    node* p = head;
   do
    {
        cout << "Element : " << head->value << endl;
        head = head->next;
    } while (head != p);
}

int main()
{
    node *head;
    node *secondNode;
    node *thirdNode;
    node *fourthNode;


    //Allocting dynamic memory to 3 nodes
    head = new node();
    secondNode = new node();
    thirdNode = new node();
    fourthNode = new node();


    //Assigning values to nodes
    head->value = 5;
    secondNode->value = 55;
    thirdNode->value = 555;
    fourthNode->value = 5555;


    //Connecting nodes
    head->next = secondNode;
    secondNode->next = thirdNode;
    thirdNode->next = fourthNode;
    fourthNode->next = head;
    cout<<".......Circular Linked List......."<<endl;
    transverse_linkedlist(head);

    return 0;
}

```

## Operations
The operations on circular linked list are:
-	Initialize the list (to an empty state).
-	Determine whether the list is empty.
-	Destroy the list.
-	Print the list
-	Find the length of the list
-	Search the list for a given item
-	Retrieve the first and the last element of the list
-	Insert an item in the list
-	Delete an item from the list
-	Copy the list 

The most basic and key operations are insertion and deletion from the circular linked list.

### Insertion in Circular Linked List
Insertion in circular linked list can be done at three positions in the list:
-	Insertion at the beginning 
-	Insertion in between the list 
-	Insertion at the end

### Deletion in Circular Linked List
Deletion in circular linked list can be done at four positions in the list: 
-	Deletion at the beginning 
-	Deletion in between the list 
-	Deletion at the end 
-   Deletion of a node with specific value

## Implementation

-  [C++](../../../algorithms/CPlusPlus/Linked-Lists/circular.cpp)


## Reference


["D.S. Malik", "Data Structures using C++", "Second Edition".](https://www.amazon.com/Data-Structures-Using-D-Malik/dp/0324782012)
