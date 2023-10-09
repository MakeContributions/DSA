// add the relevant header files
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// create a structure for a single node of the linked list
struct Node
{
// the node contains two parts- an integer part, a pointer of its own data type to point to the next node
int data; 
struct Node *next;
// assigning values to the node elements
Node (int x)
{
   data=x;
   next=NULL;
}
};

// function to return intersection point, if it exists, of given two lists
// pointers head1 and head2 point to the first element/head of the given lists respectively
int intersectPoint(struct Node* head1, struct Node* head2){
   // initialising another pointer to point at the 1st list's head
    Node *t=head1,*k;
   // declaring c1 and c2 to keep the length of the two lists respectively\
   // initialising flag to 0 to keep check whether intersection point was found or not
    int c1=0,c2=0,flag=0;
   // finding the length of the first list
    while(t!=NULL)
    {
        c1++;
        t=t->next;
    }
   // finding the length of the 2nd list
    t=head2;
    while(t!=NULL)
    {
        c2++;
        t=t->next;
    }
   // calculating the difference in lengths of the two lists and storing in f
    int f=abs(c1-c2);
   // depending on the greater value out of the two variables, c1 and c2
   // we assign t pointer to the list with greater length and k to the list with smaller length
    if(c1>c2){
    t=head1;
    k=head2;}
    else
    {
        t=head2;
        k=head1;
    }

   // in case of unequal lengths of the two lists, we move the pointer t (pointing to the longer list)
   // f no. of nodes forward so that we can compare whether the next node of t and k pointers is the same node or not simultaneously
   // (to make t and k pointers start traversing the same length/ to reach the intersection point side by side)
    if(c1!=c2){
     for(int i=0;i<f;i++)
     {
         t=t->next;
     }}
     else
     {
         t=head1;
         k=head2;
     }
    while(t)
    {
        if(t->next==k->next&&t->next!=NULL)
        {
           // when intersection point is found, flag is set to 1 and the common node value is returned as the intersection point
            flag=1;
            return t->next->data;
        }
       // if not found, t and k pointers move to the next nodes in their respective lists
        t=t->next;
        k=k->next;
    }
   // if no intersection point was found at all (there is no common list), then a value of -1 is returned
     if(flag==0)
     return -1;
}

// function to add elements in a list
vector<int> take(int n)
{
   vector<int> ans(n);
   for(int i=0;i<n;i++) cin>>ans[i];
   return ans;
}

// function to add a node using take function to the linked list and return the head of the formed list
Node* inputList(int size, vector<int> v){
if(size==0) return NULL;

   int val = v[0];
   Node *head= new Node(val);
   Node *tail=head;

for(int i=0; i<size-1; i++)
{
   val = v[i+1];
   tail->next = new Node(val);
   tail = tail->next;
}
return head;
}

int main()
{
   // to take input of lengths of the two lists in the Y shaped list and length of the common list
   int n1,n2,n3;
   cout<<"Enter length of 1st, 2nd and the common list: ";
   cin>>n1>>n2>>n3;

   // creating 3 vector lists intitally
   vector<int> v1 = take(n1);
   vector<int> v2 = take(n2);
   vector<int> v3 = take(n3);

   Node* head1 = NULL;
   Node* head2 = NULL;
   Node* common = NULL;
   // taking input of the 1st list
   cout<<"Enter values for 1st list: ";
   head1= inputList(n1, v1);
   // taking input of the 2nd list
   cout<<"Enter values for 2nd list: ";
   head2 = inputList(n2, v2);
   // taking input of the 3rd list
   cout<<"Enter values for 3rd list: ";
   common = inputList(n3, v3);

   // forming a Y shaped list
   Node* temp = head1;
   while(temp!=NULL && temp->next != NULL)
   temp = temp->next;
   
   if (temp!=NULL) temp->next = common;
   
   temp = head2;
   
   while(temp!=NULL && temp->next != NULL)
   temp = temp->next;
   
   if (temp!=NULL) temp->next = common;

   // printing the intersection point
   cout <<"The intersection point is: " <<intersectPoint(head1, head2) <<endl;
   return 0;
}
// Time Complexity: O(N+M), where n and m are the lenghts of the two lists
// Auxiliary Space: O(1), in regards to the logic in finding the intersection point
