
#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

struct Node{
    string name;
    Node *next;
};

Node *front;
Node *rear;
Node *tracker;
Node *previous;

void push(string name){
    Node *temp = new Node();
    temp->name = name;
    if(front==NULL && rear == NULL){
        front = temp;
        rear = temp;
        rear->next = front;
        tracker = front;
        previous = front;
        
    }
    else{

        rear->next = temp;
        rear = temp;
        rear->next = front;
        
    }
}

void pop(int k){
    if(previous==tracker){
        for(int i = 0;i<k;i++){
            tracker = tracker->next;
        }
        for(int i = 1;i<k;i++){
           previous =previous->next;
        }
        cout<<tracker->name<<" has been executed"<<endl;
        tracker = tracker->next;
        previous->next = tracker;
    }
    else{
        for(int i = 0;i<k;i++){
            tracker = tracker->next;
            previous =previous->next;
        }
        cout<<tracker->name<<" has been executed"<<endl;
        tracker = tracker->next;
        previous->next = tracker;
    }
}

int main(){
    int n,k;
    cout<<"Enter the number of people:\n";
    cin>>n;
    string tempName;
    for(int i = 1;i<=n;i++){
        cout<<"Enter name of person "<<i<<": "<<endl;
        cin>>tempName;
        push(tempName);
    }
    cout<<"Jump number: ";
    cin>>k;
    pop(k);
    while(tracker!=previous){
        pop(k);
    }
    cout<<tracker->name<<" survives"<<endl;
    return 0;
}
