// Content: Circular Queue using linked list
// Author: Tawfik Yasser
// Date: Mon, 8 Mar 2021
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node() {}
};
class QueueLL
{
private:
    Node *front;
    Node *rear;
    int length;
public:
    QueueLL()
    {
        front = rear = NULL; length = 0;
    }
    //Function to add new element in the queue
    void enqueue(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        if(rear == NULL)
        {
            front = rear = newNode;
            rear->next = front;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
      length++;
    }
    //Function to remove element from the queue
    void dequeue()
    {
        Node *temp = front;
        if(front == NULL && rear == NULL){
            cout<<"Empty Queue"<<endl;
        }else if(front == rear){
            front = rear = NULL;
            delete temp;
        }else{
            front = temp->next;
            rear->next = front;
            delete temp;
        }
      length--;
        if(length < 0 )
            length = 0;
    }
  //Function returns the first element in the queue
    void peek()
    {
        if(front == NULL && rear == NULL){
            cout<<"Empty Queue"<<endl;
        }else{
            cout<<front->data<<endl;
        }
    }
  //Function to display all the elements in the queue
    void print()
    {
        if(front == NULL && rear == NULL)
        {
            cout<<"Empty Queue"<<endl;
        }
        else
        {
            Node *temp = front;
            while(temp->next != front)
            {
                cout<<"[ "<<temp->data<<" ] ";
                temp = temp->next;
            }
            cout<<"[ "<<temp->data<<" ] ";
        }
    }
    int _size()
    {
        return length;
    }
};
int main()
{
    QueueLL qll;
    qll.enqueue(5);
    qll.enqueue(3);
    qll.enqueue(-2);
    qll.print();
    cout<<endl;
    cout<<"Queue size = "<<qll._size()<<endl;
    qll.peek();
    qll.dequeue();
    qll.print();
    cout<<endl;
    cout<<"Queue size = "<<qll._size()<<endl;
    qll.peek();
    return 0;
}
