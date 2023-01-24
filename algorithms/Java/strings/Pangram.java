/**
 * The Pangram class is used to check if a given string is a pangram or not. A
 * pangram is a sentence that contains all the letters of the alphabet.
 * The class provides a method, isPangram(String str), that takes a string as
 * input and returns a boolean value indicating whether the string is a pangram
 * or not.
 * 
 * @author Nikhil S
 */

public class Pangram {

    private static boolean isPangram(String str) {
        str = str.toLowerCase(); // Convert the input string to lowercase for consistency
        boolean[] isLetterPresent = new boolean[26]; // A boolean array to indcate if a letter is present or not

        for (int i = 0; i < str.length(); i++) {
            if (Character.isLetter(str.charAt(i))) { // Check if the character is a english alphabet
                /*
                 * The below line performs the logic of updating the isLetterPresent Array based
                 * on the character
                 * Each letter in the English alphabets map to unique index of the
                 * isLetterPresent Array
                 * isLetterPresent[0] -> 'a';
                 * isLetterPresent[1] -> 'b';
                 * .
                 * .
                 * .
                 * .
                 * isLetterPresent[25] -> 'z';
                 * 
                 * Example : 1. Consider the current character as 'a' whose ASCII value is 97.
                 * Hence 'a' - 'a' => 97 - 97 = 0 => isLetterPresent[0] = true => 'a' is present
                 * 
                 * 2. Consider the current character as 'z' whose ASCII value is 122.
                 * Hence 'z' - 'a' => 122 - 97 = 25 => isLetterPresent[25] = true => 'z' is
                 * present
                 */
                isLetterPresent[str.charAt(i) - 'a'] = true;

            }
        }

        for (int i = 0; i < 26; i++) { // Check for presence of all the letters i.e., the Array must have all true
                                       // value
            if (!isLetterPresent[i]) {
                return false; // If there is a false value it means the string is not a Pangram hence return
                              // false
            }
        }
        return true; // If the for loop successfully completes for all values of isLetterPresent[]
                     // then, the string is Pangram hence return true
    }

    public static void main(String[] args) {

        System.out.println(isPangram("The quick brown fox jumps over the lazy dog")); // Pangram String; output:true
        System.out.println(isPangram("The quick brown wolf jumps over the lazy dog"));// Normal String; output:false
    }

}
