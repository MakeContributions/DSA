package com.dsa;

public class printPi {
    //main starts
    public static void main(String[] args) {
        String s = "piabcpidefpi";
        changetoPi(s, 0);
    }

    //function starts
    private static void changetoPi(String s, int i) {
        //base case
        if (i == s.length()) {
            return;
        }
        //if we found  "pi" in the string, print 3.14 instead of it
        //increment i by 2  in recursive function call
        if (s.charAt(i) == 'p' && s.charAt(i + 1) == 'i') {
            System.out.print("3.14");
            changetoPi(s, i + 2);
        }
        //else print the character itself and increment i by 1 in recursive function call
        else
        {
            System.out.print(s.charAt(i));
            changetoPi(s, i + 1);
        }
    }
    /*
    Sample Input:
    s = piabcpidefpi

    Output:
    3.14abc3.14def3.14
    */
}
