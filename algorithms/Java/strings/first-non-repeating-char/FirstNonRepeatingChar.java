/*
Output the first character which occurred once in the string.
The input string can consist of any characters, like %,? or ü.
There are no constraints. For examples, see the main function.
Time Complexity: O(n)
Explanation of the algorithm:
             Iterating through the string twice:
             First time, the program counts occurrences into a HashMap.
             Second time, the program looks for the first character
             in the string with the HashMap value of 1. */

import java.util.*;

public class FirstNonRepeatingChar {

    // Contains examples of usage of the algorithm
    public static void main(String[] args) {
        String example1 = "abcbadabfaa334";
        System.out.println(firstNonRepeatingChar(example1));
        // Output: c

        String example2 = "aab!b?cc!dü";
        System.out.println(firstNonRepeatingChar(example2));
        // Output: ?

        String example3 = "aa!b?cc!ddb?";
        System.out.println(firstNonRepeatingChar(example3));
        // Output: null

        String example4 = "üaa55vv22??1.";
        System.out.println(firstNonRepeatingChar(example4));
        // Output: ü

    }

    /*
    Return the first character in string a that only occurs in string a once.
    If every character in the string occurs more than once, return null.
     */
    public static Character firstNonRepeatingChar(String a) {
        // map characters to the number of occurrences in the string
        HashMap<Character, Integer> count = new HashMap<>();

        // To iterate through the string, turn it to an array of characters
        char[] charArray = a.toCharArray();

        // Count occurrences of each character
        for (Character i : charArray) {
            Integer value = count.putIfAbsent(i, 0);
            if (value == null) count.put(i, 1);
            else count.put(i, value + 1);
        }
        // Search for the first matching character
        for (Character k : charArray) {
            if (count.get(k) == 1) {
                return k;
            }
        }
        return null;
    }
}
