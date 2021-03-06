// Content: Queue using linked list (FIFO)
// Author: Tawfik Yasser
// Date: Fri, 5 Mar 2021

#include <iostream>
using namespace std;
// Class `Node` to represent every item in the queue
class Node
{
public:
    int data;    // Item data
    Node *next;  // Pointer to next item
    Node() {}    // Empty constructor
};
// Claas to represent the queue using linked list
class QueueLL
{
private:
    Node *front; // Pointer to the head of the queue
    Node *rear;  // Pointer to the end of the queue
    int _length;
public:
    QueueLL() //Empty constructor to initialize front and rear to NULL because in the start the queue will be empty
    {
        front = rear = NULL;
        _length = 0 ;
    }

    // Function `Enqueue` to add new item to the queue from the rear side (End)
    void enqueue(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        if(front == NULL && rear == NULL) // Empty queue
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        _length++;
    }
 
    // Function `Dequeue` to remove an item from the queue from the front side (Start)
    void dequeue()
    {
        Node *temp = front;
        front = front->next;
        delete temp; //Free the memory
        _length--;
    }

    // Function `Peek` to return the first item in the queue
    void peek()
    {
        cout<<front->data<<endl;
    }

    // Function `Print` to display the items of the queue
    void print()
    {
        if(front == NULL && rear == NULL) //Empty queue
        {
            cout<<"Empty Queue"<<endl;
        }
        else
        {
            Node *temp = front;
            while(temp != NULL) // Till the end of the queue
            {
                cout<<"[ "<<temp->data<<" ] ";
                temp = temp->next;
            }
        }
    }
    int _size()
    {
        return _length;
    }
};
int main()
{
    //Test the functions
    QueueLL qll;
    qll.enqueue(5);
    qll.enqueue(3);
    qll.enqueue(-2);
    qll.print();
    cout<<endl;
    qll.peek();
    cout<<"Queue size = "<<qll._size()<<endl;
    qll.dequeue();
    qll.print();
    cout<<endl;
    qll.peek();
    cout<<"Queue size = "<<qll._size()<<endl;
    return 0;
}
