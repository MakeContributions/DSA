//  RedundantParenthesis
// Given a string of balanced expression, find if it contains a redundant parenthesis or not. A set of parenthesis are redundant if the same sub-expression is surrounded by unnecessary or multiple brackets. Print True if redundant, else False.

// Algorithm
// 1. We iterate through the given expression and for each character in the expression, if the character is an open parenthesis ‘(‘ or any operators, we push it to the stack.
// 2. If the character is close parenthesis ‘)’, then pop characters from the stack till matching open parenthesis ‘(‘ is found. 
// For any sub-expression of expression, if we are able to pick any sub-expression of expression surrounded by (), then we again left with () as part of string, we have redundant braces. 
// We iterate through the given expression and for each character in the expression, if the character is an open parenthesis ‘(‘ or any of the operators or operands, we push it to the stack. If the character is close parenthesis ‘)’, then pop characters from the stack till matching open parenthesis ‘(‘ is found. 
// Now for redundancy two condition will arise while popping- 
// 1. If immediate pop hits an open parenthesis ‘(‘, then we have found a duplicate parenthesis. For example, (((a+b))+c) has duplicate brackets around a+b. When we reach the second “)” after a+b, we have “((” in the stack. Since the top of stack is an opening bracket, we conclude that there are duplicate brackets. 
// 2. If immediate pop doesn’t hit any operand(‘*’, ‘+’, ‘/’, ‘-‘) then it indicates the presence of unwanted brackets surrounded by expression. For instance, (a)+b contain unwanted () around a thus it is redundant. 



// solution
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter the string:" << endl;
    string s;
    cin >> s;
    // create a stack of characters
    stack<char> st;
    bool ans = false;

    // Iterate through the given expression
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/')
        {
            st.push(s[i]);
        }
        else if (s[i] == '(')
        {
            // if current character is close parenthesis '('
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            // if current character is close parenthesis ')'
            if (st.top() == '(')
            {
                ans = true;
            }
            while (st.top() == '+' or st.top() == '-' or st.top() == '*' or st.top() == '/')
            {
                st.pop();
            }
            st.pop();
        }
    }

    if (ans)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
}


// Input :
// For example:
// 1. ((a+b))
// 2. (a+b*(c-d))

// Output:
// 1. True, ((a+b)) can reduced to (a+b), this is Redundant
// 2. False, (a+b*(c-d)) doesn't have any redundant or multiple
// brackets
