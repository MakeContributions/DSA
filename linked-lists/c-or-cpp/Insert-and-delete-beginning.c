#include<stdio.h>
#include<stdlib.h>

//  Structure Definition

// 1. Data of Integer type.
// 2. Pointer to the Next Node .
struct node {
    int data ;
    struct node *next ;
} ;
struct node *head = NULL ;
struct node *current = NULL ;

//Function to Print the Linked List
void printList(){
    printf("\nItem in the Linked List are :  ");
    // Initialize the ptr(pointer) with head location .
    struct node *ptr = head ;
    // While Loop until we encounter a Node which is NULL .
    // NULL ,  signifies we are the end of the list .
    while(ptr!=NULL){
        printf("%d ",ptr->data) ;  //Print the value of the Node
        ptr = ptr->next ;         //Increment the ptr
    }
}

//Insertion at the Beginning of the Linked List

void insertBeg(int data){
 //Creating a link
 //Malloc is for space allocation .
 struct node *link = (struct node*) malloc(sizeof(struct node)) ;
 link->data = data ;
 //Point the link's pointer to the current head
 link->next = head ;
 //Update the Head to the node we want to insert at the beginning
 head = link ;
}

//Deletion at the Beginning of the Linked List

struct node* deleteBeg(){
  //Case of Underflow (Deletion when list is empty)
   if(head == NULL) {
    printf("List is Empty , deletion not possible") ;
    return NULL ;
   }
  //Store head location in a temporary Node .
  struct node *temp = head ;

  //Update the current Header
  head = head->next ;

  // returning the deleted Link
  return temp ;

}
int main(){
    deleteBeg();    //Case of Underflow 
    insertBeg(10);  //Insert 10 at Beginning
    insertBeg(20);  //Insert 20 at Beginning
    insertBeg(30);  //Insert 30 at Beginning
    insertBeg(40);  //Insert 40 at Beginning
    insertBeg(50);  //Insert 50 at Beginning
    insertBeg(60);  //Insert 60 at Beginning
    printList();    // Prints : 60 50 40 40 20 10
    deleteBeg();    //Delete First Element
    printList();    // Prints : 50 40 30 20 10
    return 0 ;
}
