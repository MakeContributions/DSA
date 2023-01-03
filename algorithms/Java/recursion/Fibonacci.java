package com.dsa;

/* Description: To find the Nth Fibonacci Number

  Time Complexity: O(n) where n is the number inputted
 */

public class Fibonacci {
    public static int Fibo(int n){
        if(n < 2){                // base condition
            return n;
        }
        return Fibo(n-1) + Fibo(n-2);       //linear recurrence relation
    }
    public static void main(String[] args) {
        System.out.println(Fibo(5));
    }

    /* Sample Input
       n = 5

       Output:
       5
     */
}
