package com.dsa;

/*
Description: To find the length of the string using recursion

Time Complexity: O(n) where n is the number of characters present in the string
*/

public class StringLength {

    //function body
    static int findLength(String s) {
        //if we are at the end of the string return 0
        //this is the base case
        if (s.equals("")) {
            return 0;
        }
        //recursive function call
        //at every recursive function call, we are removing the last character of the string using substring() method
        //since we are removing one character at every recursive function call we are adding one to it, to count the character
        return findLength(s.substring(1)) + 1;
    }
    public static void main(String[] args) {
        String s = "Hello";
        //calling the function to return the string length
        int len = findLength(s);
        System.out.println(len);
    }
}
