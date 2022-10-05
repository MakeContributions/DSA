// Problem statement

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


// Solution

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

