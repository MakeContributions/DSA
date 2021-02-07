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

void solve()
{
    Node *head = NULL;
    push(&head, 5);
    push(&head, 7);
    push(&head, 10);
    reverseList(head);
}

int32_t main()
{
    // ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;
    for (int t = 1; t <= tt; t++)
    {
        solve();
    }
}