package com.dsa;

/*Description: To find the first uppercase letter in the string using recursion

TIme Complexity: O(n) where n is the number of characters present in the string
*/
public class firstUppercaseLetter {
    //main starts
    public static void main(String[] args) {
        String s = "hEllo eveRyoNe";
        char c = printfirstUP(s, 0);
        System.out.println("First uppercase letter in the string: " + c);
    }

    //function starts
    static char printfirstUP(String s, int i) {
        //base case
        //if i is equal to the string length, return '\0'
        //means no uppercase letter found
        if (i == s.length()) {
            return '\0';
        }
        //if the character at the given index is a capital letter
        //return it
        if (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z') {
            return s.charAt(i);
        }
        //recursive function call
        return printfirstUP(s, i + 1);
    }

    /*
    Sample Input:
    s= hEllo eveRyoNe

    Output:
    E
    */
}
