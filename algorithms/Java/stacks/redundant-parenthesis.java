// PROBLEM STATEMENT

/*
Given a string of balanced expression, find if it contains a redundant parenthesis or not. 
A set of parenthesis are redundant if the same sub-expression is surrounded by unnecessary or multiple brackets. 
Print True if redundant, else False.
Note: Expression may contain ‘+‘, ‘*‘, ‘–‘ and ‘/‘ operators. Given expression is valid and there are no white spaces present.

For example:

((a+b)) can reduced to (a+b), this is Redundant
(a+b*(c-d)) doesn't have any redundant or multiple
brackets
*/


// APPROACH

/*
We will use stack as a data structure to solve this problem.

1. We iterate through the given expression and for each character in the expression, if the character is an open parenthesis ‘(‘ or any operators, we push it to the stack.
2. If the character is close parenthesis ‘)’, then pop characters from the stack till matching open parenthesis ‘(‘ is found.
   For any sub-expression of expression, if we are able to pick any sub-expression of expression surrounded by (), then we again left with () as part of string, we have redundant braces.
   We iterate through the given expression and for each character in the expression, if the character is an open parenthesis ‘(‘ or any of the operators or operands, we push it to the stack. If the character is close parenthesis ‘)’, then pop characters from the stack till matching open parenthesis ‘(‘ is found.
   Now for redundancy two condition will arise while popping-
3. If immediate pop hits an open parenthesis ‘(‘, then we have found a duplicate parenthesis. For example, (((a+b))+c) has duplicate brackets around a+b. When we reach the second “)” after a+b, we have “((” in the stack. Since the top of stack is an opening bracket, we conclude that there are duplicate brackets.
4. If immediate pop doesn’t hit any operand(‘*’, ‘+’, ‘/’, ‘-‘) then it indicates the presence of unwanted brackets surrounded by expression. For instance, (a)+b contain unwanted () around a thus it is redundant.

*/

// Time Complexity - O(N)
// Space Complexity - O(N)


// SOLUTION

import java.util.Stack;

class Main {

    public static void main(String[] args){
        Redundant_Parenthesis obj = new Redundant_Parenthesis();
        boolean ans1 = obj.problem("((a+b))");
        if(ans1) {
            System.out.println("True");
        } else {
            System.out.println("False");
        }

        boolean ans2 = obj.problem("(a+b*(c-d))");
        if(ans2) {
            System.out.println("True");
        } else {
            System.out.println("False");
        }
    }
}

class Redundant_Parenthesis {

    public boolean problem(String input_string){

        Stack<Character> st = new Stack<>();
        for(int i = 0; i < input_string.length(); i++) {
            char current_char = input_string.charAt(i);
            if(current_char == ')') {
                char top_char = st.pop();
                boolean flag = true;
                while(top_char != '('){
                    if(top_char == '+' || top_char == '-' || top_char == '/' || top_char == '*'){
                        flag = false;
                    }
                    top_char = st.pop();
                }
                if(flag){
                    return true;
                }
            } else {
                st.push(current_char);
            }
        }
        
        return false;

    }
}

