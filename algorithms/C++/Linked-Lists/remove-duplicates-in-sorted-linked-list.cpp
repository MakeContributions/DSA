//Program to Remove Duplicates in Sorted Singly linkedlist 


//                                                            Algorithm: 

//Traverse the list from the head (or start) node. 
//While traversing, compare each node with its next node. 
//If the data of the next node is the same as the current node then delete the next node. 
//Before we delete a node, we need to store the next pointer of the node 


//Implementation: 
#include <bits/stdc++.h> 
using namespace std; 

/* a node of the singly linked list */
struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

/* Function to print nodes in a given linked list */
void printlist(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }cout<<endl;
}

//Function to Remove Duplicates from linked list
void removeduplicates(Node *head){
    Node *curr=head;
    //check for duplicates if found then remove it
    while(curr!=NULL && curr->next!=NULL){
        if(curr->data==curr->next->data){
            Node *temp=curr->next;
            curr->next=curr->next->next;
            delete temp;
        }
        else{
            curr=curr->next;
        }
    }
}

int main() 
{ 
	Node *head=new Node(10);
	head->next=new Node(11);
	head->next->next=new Node(11);
	head->next->next->next=new Node(13);
	head->next->next->next->next=new Node(13);
	head->next->next->next->next->next=new Node(15);
	printlist(head);
    removeduplicates(head);
	printlist(head);
	return 0;
}
/*
Input: 10 11 11 13 13 15
Output: 10 11 13 15
Time Complexity: O(n) where n is the number of nodes in the given linked list.
*/
