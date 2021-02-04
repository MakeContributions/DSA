//PROGRAM TO INSERT ITEM AT BEGINNING OF LINKED LIST USING STRUCTURE

#include<iostream>
using namespace std ;
struct Node{
 int data ;         // INTEGER DATA TYPE
 Node *next ;       //POINTER TO NEXT NODE(
 Node(int x){       //CONSTRUCTOR
 data=x ;           //INTIALIZE NEW NODE'S DATA WITH X
 next = NULL ;      //INTIALIZE NEW NODE'S POINTER AS NULL
 }
};
// FUNCTION TO INSERT ITEM AT BEGINNING OF LINKED LIST
Node *insert_at_Beginning(Node *head,int val){
Node *temp = new Node(val) ;      //CREATE NEW NODE WITH VALUE AS VAL .
temp->next = head ;               // LINK THE TEMP'S POINTER TO HEAD NODE
return temp ;                     // RETURN NEW HEAD

}
//FUNCTION TO PRINT VALUES

void printList(Node *head){
while(head!=NULL){           //ITERATE UNTIL WE REACH END OF LIST (LINKED LIST)
    cout<<head->data<<" ";   //PRINT VALUE AT THAT NODE
    head=head->next;         // MOVE TO NEXT NODE
}
return ;
}
int main(){
Node *head = NULL ;
head = insert_at_Beginning(head , 1); //INSERT 1 AT BEGINNING
head = insert_at_Beginning(head , 2); //INSERT 2 AT BEGINNING
head = insert_at_Beginning(head , 3); //INSERT 3 AT BEGINNING
head = insert_at_Beginning(head , 4); //INSERT 4 AT BEGINNING
printList(head);               //OUTPUT : 4 3 2 1
return 0;
}
