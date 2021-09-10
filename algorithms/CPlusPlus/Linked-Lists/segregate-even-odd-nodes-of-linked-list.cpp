/*
The idea is to split the linked list into two: 
one containing all even nodes and other containing all odd nodes. 
And finally, attach the odd node linked list after the even node linked list. 
To split the Linked List, traverse the original Linked List and move all odd nodes to a separate Linked List of all odd nodes. 
At the end of loop, the original list will have all the even nodes and the odd node list will have all the odd nodes. 
To keep the ordering of all nodes same, we must insert all the odd nodes at the end of the even node list. 
And to do that in constant time, we must keep track of last pointer in the even node list
*/

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
// Function to segregate even and odd nodes.
Node *segregate(Node *head){
	// Starting node of list having
    // even values.
    Node *eS=NULL;
    // Ending node of even values list.
	Node *eE=NULL;
	// Starting node of odd values list.
	Node *oS=NULL;
	// Ending node of odd values list.
	Node *oE=NULL;
    for(Node *curr=head;curr!=NULL;curr=curr->next){
        int x=curr->data;
        // If current value is even, add
        // it to even values list.
        if(x%2==0){
            if(eS==NULL){
                eS=curr;
                eE=eS;
            }else{
                eE->next=curr;
                eE=eE->next;
            }
        }
		// If current value is odd, add
        // it to odd values list.
		else{
            if(oS==NULL){
                oS=curr;
                oE=oS;
            }else{
                oE->next=curr;
                oE=oE->next;
            }
        }
    }
    // If either odd list or even list is empty,
    // no change is required as all elements
    // are either even or odd.
    if(oS==NULL||eS==NULL)
        return head;
    // Add odd list after even list.     
    eE->next=oS;
    oE->next=NULL;
    return eS;
}

/* Driver program to test above functions*/
int main() 
{ 
	Node *head=new Node(10);
	head->next=new Node(11);
	head->next->next=new Node(12);
	head->next->next->next=new Node(13);
	head->next->next->next->next=new Node(14);
	head->next->next->next->next->next=new Node(15);
	printlist(head);
	head=segregate(head);
	printlist(head);
	return 0;
}

/*
Input: 10 11 12 13 14 15
Output: 10 12 14 11 13 15

Time complexity: O(n)
*/ 
