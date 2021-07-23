#include<bits/stdc++.h>

using namespace std;

//node class to store nodes
class Node{

    public:

    int data;
    Node* next;
};


//creating linked list from given vector
void Create(vector<int>v,Node*& head){
    Node* prev;
    for(int i=0;i<v.size();i++){

        Node* temp=new Node();
        temp->next=nullptr;
        temp->data=v[i];
        
        if(i==0){
            head=temp;

        }else{
            prev->next=temp;
        }
        prev=temp;
    }


}

//display linked list 
void Display(Node*& head){                                  

    if(head==nullptr) cout<<"\nEmpty";
    Node* temp=head;

    while(temp){
        cout<<temp->data;
        temp=temp->next;
    }
    cout<<"\n";

}

//delete Node of specific values
void RemNode(Node*& head,int val){

    Node* temp=head;                                
    
    while(head && head->data==val){
                                                                       //while head is equal to value move pointer
        head=head->next;
        
    }

    while(temp){

        if(temp->next&&temp->next->data==val){                          //same for rest of the nodes if val of next is equal to val then  move ahead
            
            temp->next=temp->next->next;
            
        
            
        }else{
            temp=temp->next;                                            //else just iterate
        }
    }

    

}

int main(){

    Node* head=NULL;
    int n,val;
    cout<<"\nEnter no. of elements in linked list ";                      //Input vector size and elements
    cin>>n;
    vector<int>v(n);
    cout<<"\nEnter elements of linked list ";
    for(int i=0;i<n;i++){

        cin>>v[i];

    }
    cout<<"\nLinked list is:- ";
    Create(v,head);                    
    Display(head);
    cout<<"\nElement to remove ";
    cin>>val;
    
    RemNode(head,val);
    cout<<"\nLinked list after removing:- ";
    Display(head);
    return 0;
}

/*

Time Complexity-O(n)

Enter no. of elements in linked list 6

Enter elements of linked list 3 2 4 3 6 3

Linked list is:- 324363

Element to delete 3

Linked list after deletion:- 246


*/