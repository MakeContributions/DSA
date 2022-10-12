//Let the elements of the list are 1-indexed

#include<stdio.h>
#include<sstdlib.h>

struct Node{
  int data;
  struct Node* next;
};

struct Node* head;

void Insert(int data)
{
  struct Node* A;
  A = NULL;
  struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*));   //use 'new = Node()' in C++
  temp1 -> data;
  temp1 -> = NULL;
  A = temp;
  temp2 = new Node();
  temp2 -> data;
  temp2 -> next = NULL;     //temp1
}
  
void Print()
{
  Node* temp = head;
  while(temp != NULL)
  {
    printf("%d", temp -> data);
    temp = temp -> next;
  }
  printf("\n");
}

void Delete(int n)
{
  struct Node* temp1 = head;
  if(n == 1)
  {
    head = temp1 -> next;
    free(temp1);
    return;
  }
  int i;
  for(i = 0; i < n - 2; i++)
  {
    temp1 = temp1 -> next;
  }
  struct Node* temp2 = temp1 -> next;
  temp1 -> next = temp2 -> next;
  free(temp2);    //delete temp2;
}

int main()
{
  head = NULL;
  Insert(2);
  Insert(4);
  Insert(6);
  Insert(5);
  
  int n;
  printf("Enter a position: \n");
  scanf("%d", &n);
  Delete(n);
  Print();
}
