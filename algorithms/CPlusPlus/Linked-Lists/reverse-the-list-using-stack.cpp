/* 
Algorithm: 
    (i) Traverse the list and push all of its nodes onto a stack.
    (ii) Traverse the list from the head node again and pop a value 
        from the stack top and connect them in reverse order.
    
    
TIME COMPLEXITY: O(n), as we are traversing over the linked list of size N using a while loop.
SPACE COMPLEXITY: o(n), as we are using stack of size N in worst case which is extra space.

 */


#include <iostream>
#include <stack>

using namespace std;

class Node {
public:
    int data;
    Node *next;
};
Node *head;

void Print(Node* n);
void RevList();

int main() {
    head = NULL;

    Node *first = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;
    Node *fifth = new Node;
    Node *sixth = new Node;
    Node *seventh = new Node;

    head = first;

    first->data = 10;
    first->next = second;
    
    second->data = 20;
    second->next = third;
    
    third->data = 30;
    third->next = fourth;
    
    fourth->data = 40;
    fourth->next = fifth;

    fifth->data = 50;
    fifth->next = sixth;

    sixth->data = 60;
    sixth->next = seventh;

    seventh->data = 70;
    seventh->next = NULL;

    Print(head);

    RevList();
    cout<<endl;
    Print(head);

    return 0;
}

void Print(Node* n){
    if(n==NULL){
        return;
    }
    cout<<n->data<<" ";
    Print(n->next);
}
void RevList() {
    if(head == NULL) return;
    stack<Node *> st;
    Node * temp = head;
    while(temp!= NULL){
        st.push(temp);
        temp = temp->next;
    }
    temp = st.top();
    head = temp;
    st.pop();
    
    while(!st.empty()) {
        temp->next = st.top();
        temp = temp->next;
        st.pop();
    }
    temp->next = NULL;
}
