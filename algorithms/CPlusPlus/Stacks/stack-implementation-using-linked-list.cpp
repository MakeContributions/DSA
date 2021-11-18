//Implementing stack using Linked List
#include <iostream>
using namespace std;
 
class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
class stack
{
private:
    Node *head;
    int count;
 
public:
    stack()
    {
        head = NULL;
        count = 0;
    }
    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
        count++;
    }
    void pop()
    {
        if (head == NULL)
        {
            cout << "Stack is Empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        count--;
    }
    int peek()
    {
        if (head == NULL)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return head->data;
    }
    bool isEmpty()
    {
        return head == NULL;
    }
    int size()
    {
        return count;
    }
    void display()
    {
        if (head == NULL)
        {
            cout << "stack is empty" << endl;
            return;
        }
        Node *curr = head;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};
 
int main()
{
    stack s;
    s.push(10);
    s.display();
    s.push(20);
    s.display();
    s.push(30);
    s.display();
    s.push(40);
    s.display();
    s.pop();
    s.display();
    s.pop();
    s.display();
    cout << s.size() << endl;
    cout << s.peek() << endl;
    cout << s.isEmpty() << endl;
 
    return 0;
}
