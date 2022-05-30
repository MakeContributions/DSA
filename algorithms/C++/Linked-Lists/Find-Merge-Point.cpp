#include <bits/stdc++.h>
using namespace std;

//Defining a Class for creating nodes.
class SinglyLinkedListNode
{
    public:
        int data;
        SinglyLinkedListNode* next;
};


//Function to find the merge point of two linked list


int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) 
{
    int k,n=0,m=0;
    SinglyLinkedListNode* temp=head1,*temp1=head1,*temp2=head2;
    
    for(int i=0;temp!=NULL;i++)//finding the length of first linked list
    {
        n++;
        temp=temp->next;
    }
    
    temp=head2;
    for(int i=0;temp!=NULL;i++)//finding the length of second linked list
    {
        m++;
        temp=temp->next;
    }
    
    k=abs(n-m);
    
    if(n==m)
    {
        for(int i=0;i<n;i++)
        {
            if(temp1==temp2)
                return temp1->data;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return 0;
    }
    else if(n>m)
    {
        for(int i=0;i<k;i++)
        {
            temp1=temp1->next;
            //temp2=temp2->next;
        }
        for(int i=0;temp1!=NULL && temp2!=NULL;i++)
        {
            if(temp1==temp2)
                return temp1->data;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return 0;
    }
    else
    {
        for(int i=0;i<k;i++)
        {
            temp2=temp2->next;
            //temp2=temp2->next;
        }
        for(int i=0;temp1!=NULL && temp2!=NULL;i++)
        {
            if(temp1==temp2)
                return temp1->data;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return 0;
    }
}





int main()
{
    /*
        Create two linked lists
     
        1st 3->6->9->15->30
        2nd 10->15->30
     
        15 is the intersection point
    */
 
    SinglyLinkedListNode* newNode;
 
    // Addition of new nodes
    SinglyLinkedListNode* head1 = new SinglyLinkedListNode();
    head1->data = 10;
 
    SinglyLinkedListNode* head2 = new SinglyLinkedListNode();
    head2->data = 3;
 
    newNode = new SinglyLinkedListNode();
    newNode->data = 6;
    head2->next = newNode;
 
    newNode = new SinglyLinkedListNode();
    newNode->data = 9;
    head2->next->next = newNode;
 
    newNode = new SinglyLinkedListNode();
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next = newNode;
 
    newNode = new SinglyLinkedListNode();
    newNode->data = 30;
    head1->next->next = newNode;
 
    head1->next->next->next = NULL;
 
    cout << "The node of intersection is : " << findMergeNode(head1, head2);
}