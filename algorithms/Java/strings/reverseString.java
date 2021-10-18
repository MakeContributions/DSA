/*
Write a function that reverses a string. The input string is given as an array of characters s.
sample input:
Hello

sample output:
olleH

Time Complexity: O(n)
*/

package stringProblems;

import java.util.*;

public class ReverseString {
	// function to reverse the string
	public static String revString(String str) {
		// initializing an empty string
	    String reversedString = "";
        
		// traversing the string and reversing it
	    for (int i = 0; i < str.length(); i++) {
	    	reversedString = str.charAt(i) + reversedString;
	    }
	    return reversedString;
}
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		// taking a user input of the string
		String str = s.nextLine();
		
		// calling the function
		String x = revString(str);
		System.out.print(x);
		
	}

}
