package com.dsa;
//nth fibonacci number in java using recursion
public class Fibonacci {
    public static void main(String[] args) {
        int n=6;
        int ans = fib(n);
        System.out.println("N-th fibonacci number is: "+ ans);
    }

    static int fib(int n) {
        if(n==1 || n==2){
            return 1;
        }
        return fib(n-1)+ fib(n-2);
    }
}
