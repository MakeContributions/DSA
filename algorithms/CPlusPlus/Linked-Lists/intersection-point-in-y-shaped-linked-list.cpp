
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node

{
int data;
struct Node *next;
Node (int x)
{
   data=x;
   next=NULL;
}
};

int intersectPoint(struct Node* head1, struct Node* head2){
Node *t=head1,*k;
    int c1=0,c2=0,flag=0;
    while(t!=NULL)
    {
        c1++;
        t=t->next;
    }
    t=head2;
    while(t!=NULL)
    {
        c2++;
        t=t->next;
    }
    int f=abs(c1-c2);
    if(c1>c2){
    t=head1;
    k=head2;}
    else
    {
        t=head2;
        k=head1;
    }
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
            flag=1;
            return t->next->data;
        }
        t=t->next;
        k=k->next;
    }
     if(flag==0)
     return -1;
}

vector<int> take(int n)
{
vector<int> ans(n);
for(int i=0;i<n;i++) cin>>ans[i];
return ans;
}

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

srand(time(0));
int n1,n2,n3;
cout<<"Enter length of 1st, 2nd and the common list: ";
cin>>n1>>n2>>n3;

int p = rand()%3;

vector<int> v1 = take(n1);
vector<int> v2 = take(n2);
vector<int> v3 = take(n3);

Node* head1 = NULL;
Node* head2 = NULL;
Node* common = NULL;
cout<<"Enter values for 1st list: ";
head1= inputList(n1, v1);
cout<<"Enter values for 2nd list: ";
head2 = inputList(n2, v2);
cout<<"Enter values for 3rd list: ";
common = inputList(n3, v3);

Node* temp = head1;
while(temp!=NULL && temp->next != NULL)
temp = temp->next;

if (temp!=NULL) temp->next = common;

temp = head2;

while(temp!=NULL && temp->next != NULL)
temp = temp->next;

if (temp!=NULL) temp->next = common;

cout <<"The intersection point is: " <<intersectPoint(head1, head2) <<endl;


return 0;

}

