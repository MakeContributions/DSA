package com.dsa;
//reverse number using recursion
public class ReverseNumber {
    public static void main(String[] args) {
        int num=123;
        int ans = reverseNum(num, 0);
        System.out.println(ans);
    }

     static int reverseNum(int num, int rev) {
        if(num==0){
            return rev;
        }
        int r = num%10;
         rev = (rev * 10) + r;
        return reverseNum(num/10, rev);

    }
}
