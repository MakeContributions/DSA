//Description : Creating Circular linked list

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node * next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
Node * insertion(int newdata, Node * head) {  //Insertion at the end of linked list
    Node * newnode = new Node(newdata);       //Creating a new node with value newdata
    Node * ptr = head;
    if (head == NULL) {                       //If the list was initially empty then return the newnode as the new head 
        newnode -> next = newnode;
        return newnode;
    }
    while (ptr -> next != head) {            //Traversing till we reach the last node
        ptr = ptr -> next;
    }
    newnode -> next = ptr -> next;          //Insert the new node at the end of the list
    ptr -> next = newnode;
    return head;

}

void display(Node * head) {                //Function to print items in the list
    Node * ptr = head;
    if (head == NULL) {
        cout << "Empty Circular Linked List";
        return;
    }
    do {
        cout << ptr -> data << " ";
        ptr = ptr -> next;
    }
    while (ptr != head);
}

int main() {                            //Main Driver function
    Node * head = NULL;
    head = insertion(3, head);
    head = insertion(4, head);
    head = insertion(5, head);
    head = insertion(6, head);
    head = insertion(1, head);
    head = insertion(7, head);
    display(head);
    return 0;

}
