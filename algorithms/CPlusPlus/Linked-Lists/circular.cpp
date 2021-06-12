#include <iostream>
using namespace std;
struct Node
{
  int data;
  Node *next;
  Node (int x)
  {
    data = x;
    next = NULL;
  }
};
Node *insertion (int newdata,Node *head)
{
  Node *newnode = new Node(newdata);
  Node *ptr = head;
  if(head == NULL){
      return newnode;
  }
  while(ptr->next!=head){
          ptr = ptr->next;
  }
  newnode->next = ptr->next ;
  ptr->next=newnode;
  return head ;

}

void display (Node *head)
{
  Node *ptr = head;
  if(head == NULL) {
    cout<<"Empty Circular Linked List";
    return ;
  }
  do
    {
      cout << ptr->data << " ";
      ptr = ptr->next;
    }
  while (ptr != head);
}

int main ()
{
  Node *head = NULL ;
  head = insertion (3,head);
  head = insertion (4,head);
  head = insertion (5,head);
  head = insertion (6,head);
  head = insertion (1,head);
  head = insertion (7,head);
  display (head);
  return 0;

}
