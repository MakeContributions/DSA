// # Reverse Integer

// This program defines a Java function `reverse` that takes an integer as input and returns its reverse. 
// It also includes a `main` method for testing the `reverse` function with an example input.

// ## Prerequisites
// - Java Development Kit (JDK)

// ## Instructions

// To run the program, follow these steps:
// 1. Ensure you have Java Development Kit (JDK) installed on your system.
// 2. Copy the code provided and save it to a file named `ReverseInteger.java`.

// 3. Run the code:
//    ```bash
//    java reverse-integer.java

//Time Complexity: O(log10n) where n is the given input number.


public class ReverseInteger {

    public static void main(String[] args) {
        // Test the reverse function with the input 56078 and print the result
        System.out.println(reverse(56078));
    }

    public static int reverse(int x) {
        int reversed = 0; // Initialize the variable to store the reversed integer

        while (x != 0) {
            int digit = x % 10; // Extract the last digit of the input integer

            // Check for integer overflow when reversing
            if (reversed > Integer.MAX_VALUE / 10 || 
                (reversed == Integer.MAX_VALUE / 10 && digit > 7)
            ) {
                return 0; // Return 0 if an overflow would occur
            }
            if (reversed < Integer.MIN_VALUE / 10 || 
                (reversed == Integer.MIN_VALUE / 10 && digit < -8)
            ) {
                return 0; // Return 0 if an overflow would occur for negative integers
            }

            // Add the extracted digit to the reversed integer
            reversed = reversed * 10 + digit;
            x /= 10; // Remove the last digit from the input integer
        }

        return reversed; // Return the reversed integer
    }
}

// Test Case 1:

// Input: 56078
// Output: 87065
// Explanation: The reverse of 56078 is 87065.
// Test Case 2:

// Input: -123
// Output: -321
// Explanation: The reverse of -123 is -321.
// Test Case 3:

// Input: 120
// Output: 21
// Explanation: The reverse of 120 is 21.
// Test Case 4 (Overflow):

// Input: 1534236469
// Output: 0
// Explanation: The reverse of 1534236469 would cause integer overflow, so the result is 0.