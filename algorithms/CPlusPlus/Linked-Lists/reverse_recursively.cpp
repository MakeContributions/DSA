#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int val) {
            this -> data = val;
            this -> next = NULL;
        }
};

void insertAtBeg(Node* &head, int val) {
    Node* node = new Node(val);
    if(head == NULL) {
        head = node;
        return ;
    }
    node -> next = head;
    head = node;
}

void display(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
}

void insertAtEnd(Node* &head, int val) {
    Node* temp = head;
    Node* node = new Node(val);

    if(head == NULL) {
        insertAtBeg(head, val);
        return ;
    }

    while(temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> next = node;
}

void insertAtPos(Node* &head, int pos, int val) {
    Node* node = new Node(val);
    if(head == NULL) {
        insertAtBeg(head, val);
    }

    Node* temp = head;
    int i = 1;
    while(i < pos) {
        temp = temp -> next;
        i++;
    }
    Node* temp2 = temp -> next;
    temp -> next = node;
    node -> next = temp2;
}

Node* revList(Node* &head) {
    if(head == NULL or head -> next == NULL) 
        return head;

    Node* temp = head -> next;
    head -> next = NULL;

    Node* rev = revList(temp);
    temp -> next = head;

    return rev;
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;

    insertAtBeg(head1, 1);
    insertAtEnd(head1, 4);
    insertAtEnd(head1, 5);
    insertAtEnd(head1, 2);
    insertAtEnd(head1, 3);
    insertAtEnd(head1, 6);

    cout << "List1 : ";
    display(head1);

    cout << "\nRev List1 : \n";
    Node* l1 = revList(head1);
    display(l1);
    return 0;
}