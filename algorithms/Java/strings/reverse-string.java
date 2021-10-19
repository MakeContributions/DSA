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
	public static String revString(String str) {
	    String reversedString = "";
        
	    for (int i = 0; i < str.length(); i++) {
	    	reversedString = str.charAt(i) + reversedString;
	    }
	    return reversedString;
}
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		String str = s.nextLine();
		
		String x = revString(str);
		System.out.print(x);
		
	}

}
