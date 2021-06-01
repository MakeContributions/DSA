
//Circular Linked List
//insertion and Deletion at the beginning of the Linked List
#include <stdio.h>
#include <stdlib.h>

//  Structure Definition

// 1. Data of Integer type.
// 2. Pointer to the Next Node .
struct node {
    int data ;
    struct node *next ;
} ;
struct node *head = NULL ;
// Use tail pointer to avoid traversing the Linked List while inserting of the new created node
// because after every insertion of a new node we need to point make the last node point to the newly created Node 
struct node *tail = NULL ;

void printList(){

    if(head == NULL)
    {
        printf("\nList is empty");
        return;
    }

    else{
        printf("\nItem in the Linked List are :  ");
        // Initialize the ptr(pointer) with head location .
        struct node *ptr = head ;
        do{
            printf("%d ",ptr->data) ; // Print the value of the Node
            ptr = ptr->next ;         // Increment the ptr 
        }while(ptr != head);          // While Loop until we encounter a Node pointer ptr not pointing to the same location as head .

    }
}


void insertBeg(int data){
// create a link
   struct node *new_node = (struct node*) malloc(sizeof(struct node)) ;

   if(new_node==NULL){
       printf("\nCannot create the Node");
       return;
   }

   else{
       new_node->data=data;
       if(head==NULL){
            // making the head and the tail pointer to point to the newly created node
            head = new_node ;
            tail = new_node;
       }
       else{
            // Point the new_node pointer to the current head
            new_node->next = head ;
            head = new_node ;
        }

        // making the tail pointer to point to the new head
        tail->next=head;
    }
}

// Deletion at the Beginning of the Circular Linked List

void deleteBeg(){
    // NO Deletion when list is empty
    if(head == NULL) {
        printf("\ndeletion not possible ( List is empty )");
        return;
    }

    // There is only one node left in the list
    else if(head == tail)
    {
        free(head);
        head = NULL;
        tail = NULL;
        return;
    }

    else{
        // Store head location in a temporary Node pointer.
        struct node *temp = head ;

        head = head->next ;
        tail->next=head;

        free(temp);
    }
}

int main(){

    insertBeg(10);  // Insert 10 at Beginning
    insertBeg(20);  // Insert 20 at Beginning
    insertBeg(30);  // Insert 30 at Beginning
    insertBeg(40);  // Insert 40 at Beginning
    insertBeg(50);  // Insert 50 at Beginning
    insertBeg(60);  // Insert 60 at Beginning

    printList();    // Prints : 60 50 40 30 20 10

    deleteBeg();    // Delete First Element

    printList();    // Prints : 50 40 30 20 10

    return 0 ;
}

