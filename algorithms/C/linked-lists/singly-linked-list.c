#include <stdio.h>
#include <stdlib.h>

//structure mimic the link node
struct node{
    int data;
    struct node* next;
};

typedef struct node Node;

Node *head = NULL;
int count = 0;

void insertAtBegin(int x);
void insertAtEnd(int x);
void insertAtBefore(int x, int before);
void insertAtAfter(int x, int after);
int length();
void display();
void deleteAtBegin();
void deleteAtEnd();
void deleteAtAfter(int after);
void deleteAtBefore(int before);
void search(int key);

int main()
{    
    insertAtEnd(40);
    printf("The no of nodes in the list is %d\n", length());
    insertAtBegin(10);
    insertAtBegin(20);
    display();
    printf("The no of nodes in the list is %d\n", length());
    insertAtBegin(30);
    insertAtEnd(50);
    insertAtAfter(60, 10);
    insertAtBefore(70, 10);
    display();
    printf("The no of nodes in the list is %d\n", length());
    search(30);
    search(10);
    search(50);
    printf("The no of nodes in the list is %d\n", length());
    deleteAtBegin();
    display();
    deleteAtEnd();
    display();
    deleteAtAfter(60);
    display();
    deleteAtBefore(10);
    display();
}

void display()
{
    if (head == NULL)
    {
        printf("The linked list is empty\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int length()
{
    if (head == NULL)
    {
        return -1;
    }
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtBegin(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("OVERFLOW\n");
        return;
    }
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void insertAtEnd(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("OVERFLOW\n");
        return;
    }
    newNode->data = x;
    newNode->next = NULL;
    //check if the list is empty and if it is then insert the node at the beginning
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

//assumes after value already exists in the list
void insertAtAfter(int x, int after)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("OVERFLOW\n");
        return;
    }
    newNode->data = x;
    newNode->next = NULL;

    Node *temp = head;
    while (temp->data != after)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

//assumes before value already exist in the list
void insertAtBefore(int x, int before)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("OVERFLOW\n");
        return;
    }
    newNode->data = x;
    newNode->next = NULL;

    Node *temp = head;
    while (temp->next->data != before)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtBegin()
{
    if (head == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    Node *temp = head;
    printf("The value deleted is %d \n", temp->data);
    head = temp->next;
    temp->next = NULL;
    free(temp);
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    Node *temp = head, *p;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    p = temp->next;
    printf("The value deleted is %d \n", p->data);
    temp->next = NULL;
    free(p);
}

void deleteAtAfter(int after)
{
    if (head == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    Node *temp = head, *p;
    while (temp->data != after)
    {
        temp = temp->next;
    }
    p = temp->next;
    printf("The value deleted is %d \n", p->data);
    temp->next = p->next;
    free(p);
}

void deleteAtBefore(int before)
{
    if (head == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    Node *temp = head, *p;
    while (temp->next->next->data != before)
    {
        temp = temp->next;
    }
    p = temp->next;
    printf("The value deleted is %d \n", p->data);
    temp->next = p->next;
    free(p);
}

void search(int key)
{
    if (head == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    int count = 1; // counting starts from 1
    Node *temp = head;
    while (temp->data != key)
    {
        temp = temp->next;
        count++;
    }
    if (count <= length())
    {
        printf("The node number %d has the value %d\n", count, key);
    }
    else
    {
        printf("The value %d is not found in the list\n");
    }
}


