package com.dsa;
/*
Description: To print from 1 to N and N to 1 using recursion

Time Complexity: O(n)
*/

public class PrintN {
    //main starts
    public static void main(String[] args) {
        System.out.println("Printing 1 to N:");
        print2(5);
        System.out.println();
        System.out.println("Printing N to 1");
        print1(5);
    }

    //for Printing 1 to N
    static void print2(int n) {
        //base case
        if (n == 0) {
            return;
        }
        //recursive function call
        print2(n - 1);

        //print the value of n at each recursive function call
        System.out.print(n + " ");
    }

    //for Printing N to 1
    static void print1(int n) {
        //base case
        if (n == 0) {
            return;
        }
        //print the value of n first
        System.out.print(n + " ");

        //then make the recursive function call
        print1(n - 1);
    }

    /*
    Output:

    Printing 1 to N:
    1 2 3 4 5
    Printing N to 1
    5 4 3 2 1
    */
}
