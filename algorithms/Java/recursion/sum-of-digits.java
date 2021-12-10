package com.dsa;
//sum of digits in a number
public class SumofDigits {
    public static void main(String[] args) {
        int num = 1234;
        int ans = sumDigits(num);
        System.out.println("Sum of all the digits is: "+ ans);
    }



  static   int sumDigits(int num) {
         if(num == 0 || num==1){
             return num;
         }
         int sum = sumDigits(num/10);
         return sum + num%10;
    }
}
