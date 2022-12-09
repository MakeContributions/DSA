// Description := function of reverse a linkedlist in groups of size K .

// Time and space complexity :-
// Time Complexity = O(N) and Space Complexity = O(N)

// Example :-
// Input: 1->2->3->4->5->6->7->8->NULL, K = 3 
// Output: 3->2->1->6->5->4->8->7->NULL 

Node* kReverse(Node* head, int k) {
  
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
