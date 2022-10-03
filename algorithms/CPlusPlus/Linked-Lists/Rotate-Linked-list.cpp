#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void rotate(Node **head_ref, int k)
{
    if (k == 0)
        return;

    Node *current = *head_ref;

    int count = 1;
    while (count < k && current != NULL)
    {
        current = current->next;
        count++;
    }

    if (current == NULL)
        return;

    Node *kthNode = current;

    while (current->next != NULL)
        current = current->next;

    current->next = *head_ref;

    *head_ref = kthNode->next;

    kthNode->next = NULL;
}

void push(Node **head_ref, int new_data)
{

    Node *new_node = new Node();

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

int main(void)
{

    Node *head = NULL;

    cout << "Enter the number of elements in the linked list: ";
    int n;
    cin >> n;
    cout << "Enter the elements of the linked list: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        push(&head, x);
    }

    cout << "Enter the number of rotations: ";
    int k;
    cin >> k;
    rotate(&head, k);

    cout << "\nRotated Linked list \n";
    printList(head);

    return (0);
}
