#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node *next;
    Node(int val)		// Parameterised Constructor
    {
        data = val;
        next = NULL;
    }
};
class Stack
{
    Node *top;
public:
Stack()			 // Default Constructor
    {
	top = NULL; 
     }	
    void push(int);
    void printStack();
    void pop();
};
void Stack::push(int data)
{
    // Create the new Node.
    Node *newNode = new Node(data);
    newNode->data = data;
    newNode->next = top;
    top = newNode;

}

void Stack::printStack()
{
    Node* ptr;
    if(top==NULL)
    cout<<"stack is empty";
    else {
      ptr = top;
      cout<<"Stack elements are: ";
      while (ptr != NULL) {
         cout<< ptr->data <<" ";
         ptr = ptr->next;
      }
   }
   cout<<endl;
}
void Stack::pop() {
   if(top==NULL)
   cout<<"Stack Underflow"<<endl;
   else {
      cout<<"The popped element is “
       cout<< top->data <<endl;
      top = top->next;
   }
}

int main()
{
    Stack s;
    int ch, val;
   cout<<"1) Push in stack"<<endl;
   cout<<"2) Pop from stack"<<endl;
   cout<<"3) Display stack"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            s.push(val);
            break;
         }
         case 2: {
            s.pop();
            break;
         }
         case 3: {
            s.printStack();
            break;
         }
 
	case 4: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }while(ch!=4);
   return 0;
}
