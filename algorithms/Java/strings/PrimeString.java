//PROBLEM STATEMENT:
//To check whether a string is prime string or not.

//A string is known as prime string if the absolute difference of summation of ascii values of 
//odd indexed letters and even indexed letters is divisible by odd prime integers less than 9, otherwise it
//is a Casual string.

//INPUT: a string
//OUTPUT: Entered string is Prime String or Casual String

//ALGORITHM:
//STEP 1: Start
//STEP 2:Initialize the variables with integer data type
//STEP 3:Declare variables with integral data type as 0
//STEP 4:Accept a string as an input from the user.
//STEP 5:Convert the string to its lower case in case the entered string is in upper case.
//STEP 6:Use of for loop where the loop iterates takes place till the value of i is less than the length of the string.
//STEP 7:Inside for loop, calculate the sum of ascii values of the characters at odd (int O) 
//       and even indexed position(int E) of the string separately.
//STEP 8:After the completion of for loop calculate the absolute difference of O and E.
//STEP 9:Use of if else control structure, to check whether the absolute difference is divisible by odd prime numbers 
//       less than 9, or not divisible.
//STEP 10:If the condition is true then statements inside if structure is executed that is: 
//        Output: Prime String
//        else
//        Output: Casual String
//STEP 11:END
//******************************************************************************************************************************************************
package Hacktoberfest_MakeContributions_Solutions;

import java.io.*;
import java.util.*;

public class PrimeString {
//start of class
	public static void main(String[] args) {
//start of main function
		Scanner sc = new Scanner(System.in);// Use of Scanner Class

		int ch, ch1, diff, abs_diff;// Declaration of variables
		// Initialize vairiables O and E with 0
		int O = 0;
		int E = 0;

		System.out.println("Enter a string:");
		String S = sc.next();
		// Convert the string to its lower case
		S = S.toLowerCase();
		// Calculate length of the entered string
		int len = S.length();

		// Use of for loop
		for (int i = 0; i < len; i++) {
			// Use of if else control structure to check for the even positions in the
			// string
			if ((i + 1) % 2 == 0) {
				// Store the ascii value of the charachter at even position in the string in ch
				ch = S.charAt(i);
				// Summation of the ascii values of even positioned characters of the string and
				// store in E
				E = E + ch;

			} else {
				// Store the ascii value of the charachter at odd position in the string in ch
				ch1 = S.charAt(i);
				// Summation of the ascii values of odd positioned characters of the string and
				// store in O
				O = O + ch1;
			}
		}

		// Calculate the absolute diffrenece of O and E
		abs_diff = Math.abs(O - E);

		// Use of if else control structure to check whether the absolute difference of
		// O and E is divisible by odd prime numbers less than 9
		if ((abs_diff % 3 == 0) || (abs_diff % 5 == 0) || (abs_diff % 7 == 0)) {
			// If the condition is true than get the following output
			System.out.println("Prime String");
		} else {
			// If the condition is false then get the following output
			System.out.println("Casual String");
		}

	}// end of main function
}// end of class

//************************************************************************************************************
//OUTPUT:
//Sample Test 1:
//Enter a string:
//abbde
//Prime String

//Sample Test 2:
//Enter a string:
//abcd
//Casual String

//*************************************************************************************************************
