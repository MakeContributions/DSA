//Let, there are 3 nodes in the integer linked list and their addresses are 200, 100 and 250 
//repectively we have a pointer to node 'head' which stores the address of the 1st node

//Implementation Logic
//1. Create a node
//2. Let us say we want to insert a node at 3rd position in the list(noeds are 1-indexed)
//3. Let the data of node to be inserted is integer element 8
//4. To insert a node at nth position, we have to go to the (n-1)th position, here 2nd node.
//5. Then we will have to set the link field of new node, equal to the link field of (n - 1)th node

//OUTPUT of following code: 4 5 2 3

#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node* next;
};

struct Node* head;

void Insert(int data, int n)      //data and position
{
  //In C-language use => struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*));
  
  Node* temp1 = new Node();       //In C++
  temp1 -> data = data;
n empty list
  if(n == 1)
  {
    temp1 -> next = head;         //Set the 'link' field of newly created node as existing head
    head = temp1;                 //Point to the newly created node
    return;
  }
  Node* temp2 = head;
  for(int i = 0; i < n - 2; i++)
  {
    temp2 = temp2 -> next;
  }
  temp1 -> next = temp2 -> next;      //link field of new node == link field of (n - 1)th node
  temp2 -> next = temp1;              //link field of (n - 1)th node to point to new node
}
  
void Print()
{
  Node* temp = head;                //Pointer to node
  while(temp != NULL)
  {
    printf("%d", temp -> data);
    temp = temp -> next;            //Traversed the whole list
  }
  printf("\n");
}

int main()
{
  head = NULL;        //Initially, list is empty
  Insert(2, 1);       //List: 2
  Insert(3, 2);       //List: 2, 3
  Insert(4, 1);       //List: 4, 2, 3
  Insert(5, 2);       //List: 4, 5, 2, 3
  Print();
}
