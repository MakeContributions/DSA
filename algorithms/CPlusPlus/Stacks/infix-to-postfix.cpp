/*
    Program to convert a infix expression to postfix expression a.k.a Inverted Polish Notation.
    INFIX NOTATION :  An infix expression is an expression in which operators (+, -, *, /) are written between the two operands.
    POSTFIX NOTATION : The postfix operator also contains operator and operands. In the postfix expression, the operator is written after the operand.
*/

/* 
    LOGIC
    1. Initialize the Stack.
    2. Scan the operator from left to right in the infix expression.
    3. If the leftmost character is an operand, set it as the current output to the Postfix string.
    4. And if the scanned character is the operator and the Stack is empty or contains the '(', ')' symbol, push the operator into the Stack.
    5. If the scanned operator has higher precedence than the existing precedence operator in the Stack or if the Stack is empty, put it on the Stack.
    6. If the scanned operator has lower precedence than the existing operator in the Stack, pop all the Stack operators. After that, push the scanned operator into the Stack.
    7. If the scanned character is a left bracket '(', push it into the Stack.
    8. If we encountered right bracket ')', pop the Stack and print all output string character until '(' is encountered and discard both the bracket.
    9. Repeat all steps from 2 to 8 until the infix expression is scanned.
    10. Print the Stack output.
    11. Pop and output all characters, including the operator, from the Stack until it is not empty.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stack>
using namespace std;

vector<char> op = {'+', '-', '*', '/', '^', '(', ')'}; // oprators a.c.t. precedencies

int pre(char ch, string opt)
{
    vector<int> in_pre = {2, 2, 4, 4, 5, 0, 0};  // precedency if operator is in stack
    vector<int> out_pre = {1, 1, 3, 3, 6, 7, 0}; // precedency if operator is out of stack
    int idx = find(op.begin(), op.end(), ch) - op.begin();
    if (opt == "out")
    {
        return out_pre[idx];
    } // if the operator is out of stack -> return its precedency
    else
    {
        return in_pre[idx];
    }
}

string to_postfix(string infix)
{
    stack<char> st;
    string str;
    for (int i = 0; i < infix.size(); i++)
    {
        if (find(op.begin(), op.end(), infix[i]) != op.end() and !op.empty())
        {
            if (st.empty() or (pre(infix[i], "out") > pre(st.top(), "in")))
                st.push(infix[i]); // if st is empty or the element has higher precedency than stacks top element, push the operator into the stack.
            else if (infix[i] == '(')
                st.push('(');
            else if (infix[i] == ')')
            {
                while (st.top() != '(')
                {
                    str += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.empty() && pre(infix[i], "out") < pre(st.top(), "in"))
                {
                    str += st.top();
                    st.pop();
                }
                st.push(infix[i]);
            }
        }
        else
            str += infix[i];
    }
    while (!st.empty())
    {
        str += st.top();
        st.pop();
    }
    return str;
}

int main()
{
    int n;
    string infix;
    cout << "Enter the number of test cases ";
    cin >> n;
    // run loop till t is not equal to 0
    while (n--)
    {
        cout << "Enter the Infix expression ";
        cin >> infix;
        cout << "Postfix Expression of " << infix << " is " << to_postfix(infix) << endl;
    }
}
/*
to_postfix("2+7*5") // Should return "275*+"
to_postfix("3*3/(7+1)") // Should return "33*71+/"
to_postfix("5+(6-2)*9+3^(7-1)") // Should return "562-9*+371-^+"
to_postfix("1^2^3") // Should return "123^^"

time complexity : T(n)
space complexity : O(n)
*/
