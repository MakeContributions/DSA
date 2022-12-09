// function of reverse a linkedlist in groups of size K 

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
