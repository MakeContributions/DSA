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

Node *Sum(Node *head1, Node *head2)
{
    head1 = reverse(head1);
    head2 = reverse(head2);
    Node *ans = new Node(0);
    Node *temp;
    temp = ans;
    int carry = 0;
    while (head1 != NULL && head2 != NULL)
    {
        int sum = head1->data + head2->data + carry;
        int digit = sum % 10;
        temp->next = new Node(digit);
        temp = temp->next;
        carry = sum / 10;
        head1 = head1->next;
        head2 = head2->next;
    }

    while (head1 != NULL)
    {
        int sum = head1->data + carry;
        int digit = sum % 10;
        temp->next = new Node(digit);
        temp = temp->next;
        carry = sum / 10;
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        int sum = head2->data + carry;
        int digit = sum % 10;
        temp->next = new Node(digit);
        temp = temp->next;
        carry = sum / 10;
        head2 = head2->next;
    }
    while (carry != 0)
    {
        int sum = carry;
        int digit = sum % 10;
        temp->next = new Node(digit);
        temp = temp->next;

        carry = sum / 10;
    }
    return reverse(ans->next);
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
    insertAtTail(tail, 6);
    cout << "The first Linked List" << endl;
    display(head);

    cout << endl;

    Node *node2 = new Node(5);
    Node *head1 = node2;
    Node *tail1 = node2;
    insertAtTail(tail1, 6);
    insertAtTail(tail1, 4);
    insertAtTail(tail1, 8);
    cout << "The second Linked List" << endl;
    display(head1);

    Node *temp = Sum(head, head1);
    cout << "The sum of the given two linked list" << endl;

    display(temp);

    return 0;
}
