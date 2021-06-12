/* Program to implement stack using array */
#include<iostream>
using namespace std;
class Stack
{
    int cur ,capacity ,*arr;
public:
    // constructor which takes capacity as argument
    Stack(int capacity)
    {
        this->capacity = capacity;
        cur = -1;
        // dynamically allocating memory
        arr=new int[capacity];
        // if arr contain null
        if(arr == NULL)
        {
            cout << "Memory not located";
            exit(0);
        }
    }
    ~Stack()
    {
        delete []arr;
    }
    void push(int);
    void pop();
    int top();
    int empty();
};
// function to push data into stack
void Stack::push(int data)
{
    if(cur == capacity-1)
        cout << "Stack is full";
    else
    {
    cur++;
    arr[cur] = data;
    }
}
// function to pop data from stack
void Stack::pop()
{
    cur--;
}
// function to get the top most element of the stack
int Stack::top()
{
    return arr[cur];

}
// function to check whether the stack is empty of not
int Stack::empty()
{
    if(cur == -1)
        return 1;
    else
        return 0;
}
// function to clear screen
void clear_screen()
{
    #ifdef _WIN32
        system("cls");
    #elif __unix__
        system("clear");
    #else
        cout << "clear screen not supports";
    #endif
}
//driver code
int main()
{
    int cap;
    int choice ,data;
    cout << "Enter the size: ";
    cin >> cap;
    Stack s(cap);
    while(1)
    {
        cout << "1: Push\n2: Pop\n3: Top\n4:Exit\n\nEnter your choice ";
        cin >> choice;
        switch(choice)
        {
            // push data into stack
        case 1:
            cout << "Enter element: ";
            cin >> data;
            s.push(data);
            break;
        case 2:
            // pop data from stack
            if(s.empty())
                cout << "Stack is empty";
            else
            {
            data = s.top();
            s.pop();
            cout << "Popped element: " << data;
            }
            break;
            // get top element from stack
        case 3:
            if(!s.empty())
            {
            data = s.top();
            cout << "Top element: "<< data;
            }
            else
                cout << "Stack is empty";
            break;
        case 4:
            // exit
            exit(0);
        default:
            // run default case when none one the above case runs
            cout << "Invalid choice";
        }
        // clear the screen
        clear_screen();
    }
}
/*
Input: Enter the size: 5
Push -1
Push 2
Push 3
Output:
Pop 3
Top 2
Pop 2
Pop -1
Pop Stack is empty

Time complexity: O(1) for all push,pop,top,empty
*/
