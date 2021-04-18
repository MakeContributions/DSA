#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *newNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

Node *reverseList(Node *A)
{
    Node *current, *prev, *next;
    current = A;
    prev = NULL;
    next = NULL;
    while (current != NULL)
    {

        // storing address of node next to current
        next = current->next;

        // reversing the link of current node
        current->next = prev;

        // updating prev and current
        prev = current;
        current = next;
    }

    current = prev;

    return current;
}

void printlist(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int32_t main()
{
    Node *head = NULL;
    push(&head, 5);
    push(&head, 7);
    push(&head, 10);

    cout << "Linked list before reversing ->" << endl;
    printlist(head);

    head = reverseList(head);

    cout << "Linked list after reversing ->" << endl;
    printlist(head);
}