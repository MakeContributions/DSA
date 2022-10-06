import java.util.Stack;

public class Redundant_Parenthesis {
    // Function to check redundant brackets in a balanced expression
    public static boolean checkRedundancy(String s) {
		// create a stack of characters
		Stack<Character> st = new Stack<>();
		char[] str = s.toCharArray();
		// Iterate through the given expression
		for (char ch : str) {
			// if current character is close parenthesis ')'
			if (ch == ')') {
				char top = st.peek();
				st.pop();
				// If immediate pop have open parenthesis '('
				// duplicate brackets found
				boolean flag = true;
				while (top != '(') {
					// Check for operators in expression
					if (top == '+' || top == '-'
							|| top == '*' || top == '/') {
						flag = false;
					}
					// Fetch top element of stack
					top = st.peek();
					st.pop();
				}

				// If operators not found
				if (flag == true) {
					return true;
				}
			} else {
				st.push(ch); // push open parenthesis '(',
			}			 // operators and operands to stack
		}
		return false;
	}
    public static void main(String[] args) {
        String str = "((a+b)*(b+c))";
        if(checkRedundancy(str)){
            System.out.println("The given expression contains redundant parenthesis.");
        }else{
            System.out.println("The given expression does not contains redundant parenthesis.");
        }
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