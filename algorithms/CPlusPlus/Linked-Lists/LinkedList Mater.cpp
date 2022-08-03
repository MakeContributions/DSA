#include<iostream>
using namespace std;
 struct node{
 int no;
 struct node *pre;
 struct node* next;
 }*p,*q,*r,*t;

 int create(struct node *p);
 int addf(struct node *q);
 int addl(struct node *q);
 int delf(struct node *q);
 int dell(struct node *q);
 int addn(struct node *q);
 int deln(struct node *q);
 int display(struct node *r);
  int revdisplay(struct node*p);

 main(){
int no,i;
cout<<"\nSpecify the length of the list\n";
cin>>no;
p=new(struct node);
p->pre=NULL;
cin>>p->no;
p->next=NULL;
r=p;
t=p;
for(i=1;i<=no-1;i++)
{
q=new(struct node);
cin>>q->no;
q->pre=r;
r->next=q;
r=r->next;
}
q->next=NULL;


cout<<"\n\n" <<"Enter 0 to display"<<endl
             << "Enter 1 to add element at first"<<endl
             <<"Enter 2 to add element at last"<<endl
             <<"Enter 3 to deleat element at first"<<endl
             <<"Enter 4 to deleat element at last"<<endl
             <<"Enter 5 to add element at nth place"<<endl
             <<"Enter 6 to deleat element at nth place"<<endl
             <<"Enter 8 to display reverse list"<<endl;
int swt;
cin>>swt;
switch(swt)
{
case 0:
    display(p);
    break;

case 1:
    addf(p);
    break;

case 2:
    addl(p);
    break;

case 3:
    delf(p);
    break;

case 4:
    dell(p);
    break;

case 5:
    addn(p);
    break;

case 6:
    deln(p);
    break;

case 8:
    revdisplay(p);
    break;

default:
    cout<<"Invalid Input";
}

}
//ADDFIRST
addf(struct node *p)
{
    struct node *temp;

    q=new(struct node);
    cin>>q->no;
    q->next=p;
    display(q);

}
//ADDLAST
addl(struct node *p)
{
     r=p;
     q=new(struct node);
     cin>>q->no;
     q->next=NULL;
     while(p->next!=NULL)
     {
        p=p->next;
     }
     p->next=q;
     while(r!=NULL)
{
    cout<<r->no<<" ";
    r=r->next;
}

}

//DELFIRST
delf(struct node *p)
{
    q=p->next;
    display(q);
}

//DELLAST
dell(struct node *p)
{
   q=p;
   while(p->next->next!=NULL)
   {
       p=p->next;
   }

   p->next=NULL;
   while(q!=NULL)
   {
       cout<<q->no<<" ";
       q=q->next;
   }

}
//ADDMID
addn(struct node *p)
{
    int i,a,aa;
    cout<<"\nSpecify were to insert:";
    cin>>a;
    cout<<"\nEnter ID:";
    cin>>aa;
    struct node*temp;

    for(i=1;i<a-1;i++)
    {  cout<<p->no<<" ";
        p=p->next;
    }
    temp=new(struct node);
    temp->no=aa;
    temp->next=p->next;
    p->next=temp;
     while(p!=NULL)
     {
         cout<<p->no<<" ";
         p=p->next;
     }
}

//Deleatmid
deln(struct node *p)
{ int num,i;
    struct node *temp;
    temp=p;
    cout<<"Specify the element to be removed\n";
    cin>>num;

    for(i=1;i<num-1;i++)
    { cout<<p->no;
        p=p->next;
    }

    p->next=p->next->next;

    display(t);



}


 display(struct node *p)
 {q=p;
while(q!=NULL)
{
cout<<q->no<<" ";
q=q->next;
}

cout<<"\n\n";}


revdisplay(struct node *p)
{
    do
{
cout<<q->no<<" ";
q=q->pre;
}
while(q!=r);
}

