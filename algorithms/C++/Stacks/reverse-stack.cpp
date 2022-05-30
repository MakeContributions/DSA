/* the idea is to hold all items in a call stack until the stack becomes empty.
Then insert each item in the call stack at the bottom of the stack. */

#include <iostream>
#include <stack>
using namespace std;

// Recursive function to insert an item to bottom of a given stack
void insertInBottom(stack<int> &s, int item)
{
    // base case: if the stack is empty, insert given item at bottom
    if (s.empty()) {
        s.push(item);
        return;
    }

    // Pop all items from the stack and hold them in call stack
    int top = s.top();
    s.pop();
    insertInBottom(s, item);

    /*After the recursion completes , push each item in the call stack
     to top of the stack*/
    s.push(top);
}

// Recursive function to reverse a given stack
void reverseStack(stack<int> &s)
{
    // base case: stack is empty
    if (s.empty()) {
        return;
    }

    // Pop all items from the stack and hold them in call stack
    int item = s.top();
    s.pop();
    reverseStack(s);

    // After the recursion unfolds, insert each item from the call stack to bottom of the stack
    insertInBottom(s, item);
}

int main()
{
    stack<int> s;
    int n;
    cout<<"Enter the size of stack"<<"\n";
    cin>>n;
    for (int i = 1; i <= n; i++) {
        int temp;
        cout<<"enter element"<<"\n";
        cin>>temp;
        s.push(temp);
    }

    reverseStack(s);

    cout << "Reversed stack is: ";
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    
    /*what program does (reverses the stack by using recursion)
    -> original stack: 1,2,3,4,5
    -> reversed stack: 5,4,3,2,1*/
    
    // time complexity : O(n^2)


    return 0;
}
