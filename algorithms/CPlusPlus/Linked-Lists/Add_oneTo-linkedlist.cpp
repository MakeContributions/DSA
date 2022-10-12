#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for the node with data" << value << endl;
    }
};

void insertAtHead(Node *&head, int data)
{
    Node *temp = head;
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
    }
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node *&head, int d)
{
    // new node create
    if (head == NULL)
    {
        insertAtHead(head, d);
    }
    Node *temp = new Node(d);
    head->next = temp;
    head = temp;
}

void display(Node *&head)
{
    if (head == NULL)
    {
        cout << "List empty" << endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node *reverse(Node *head)
{
    Node *curr = head;
    Node *Next = NULL;
    Node *prev = NULL;
    while (curr != NULL)
    {
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
    return prev;
}

Node *Sum(Node *head)
{
    Node *dummy = new Node(0);
    Node *temp = dummy;

    head = reverse(head);
    Node *curr = head;
     
    int sum = curr->data + 1;
    int carry = 0;

    int digit = sum % 10;
    temp->next = new Node(digit);
    temp = temp->next;
    carry = sum / 10;
    curr = curr->next;

    while (curr != NULL)
    {
        sum = curr->data + carry;
        digit = sum % 10;
        temp->next = new Node(digit);
        temp = temp->next;
        carry = sum / 10;
        
        curr = curr->next;
    }

    while(carry != 0)
    {
        int sum = carry;
        int digit = sum % 10;
        temp->next = new Node(digit);
        temp = temp->next;

        carry = sum / 10;
    }
    return reverse(dummy->next);
}

int main()
{

    Node *node1 = new Node(9);
    Node *head = node1;

    Node *tail = node1;
    insertAtTail(tail, 9);

     insertAtTail(tail, 3);
     insertAtTail(tail, 4);
     insertAtTail(tail, 5);
     insertAtTail(tail, 1);

    display(head);

    Node *temp = Sum(head);
    display(temp);

    return 0;
}
