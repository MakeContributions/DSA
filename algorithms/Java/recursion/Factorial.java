package com.dsa;
/*Description: To find factorial of a number using recursion

Time Complexity: O(n) where n is the number given
*/

public class Factorial {

    //function starts
    static int fact(int n) {
        //base case
        if (n == 1) {
            return 1;
        }
        //recursive function call
        int ans = fact(n - 1);
        //multiply answer with n
        return ans * n;
    }

    //main starts
    public static void main(String[] args) {
        int ans = fact(5);
        System.out.println("Factorial is: " + ans);
    }

    /*
    Sample Input:
    n=5

    Output:
    Factorial is: 120
    */
}
