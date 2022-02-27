package com.dsa;
/*
Description: To find fibonacci of a number using recursion

Time Complexity: O(2^n) where n is the number given
*/

public class fibonacci {
    public static void main(String []args){
        int n=10;
        int ans=findFibonacci(n);
        System.out.println("Fibonacci of "+n+" is : "+ans);
    }
    public static int findFibonacci(int n){
        if(n<2)return n;
        return findFibonacci(n-1)+findFibonacci(n-2);
    }
}