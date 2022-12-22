// Description := Reverse a linkedlist in groups of size K .

// Time and space complexity :-
// Time Complexity = O(N) and Space Complexity = O(N)

// Example :-
// Input: 1->2->3->4->5->6->7->8->NULL, K = 3 
// Output: 3->2->1->6->5->4->8->7->NULL 

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void push(Node* &head_ref, int new_data)
{
    Node* new_node = new Node();
 
    new_node->data = new_data;
 
    new_node->next = head_ref;
 
    head_ref = new_node;
}

void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

Node* kReverse(Node* &head, int k) {
  
    // base case
    if(head == NULL) {
        return NULL;
    }
    
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count= 0;
    
    while( curr != NULL && count < k ) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    if(next != NULL) {
        head -> next = kReverse(next,k);
    }
    return prev;
}

int main(){
  Node* head=NULL;
  Node* ans =head;
  push(head,1);
  push(head,2);
  push(head,3);
  push(head,4);
  push(head,5);
  push(head,6);
  push(head,7);
  push(head,8);
  printList(head);
  head = kReverse(head,3);
  cout<<endl;
  printList(head);
}
