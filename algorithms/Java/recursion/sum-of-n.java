package com.dsa;
//sum of N numbers
public class SumN {
    public static void main(String[] args) {
        int num=5;
        int ans = sumtill_N(num);
        System.out.println("Sum till N numbers is: "+ ans);
    }

   static int sumtill_N(int num) {
        if(num ==1){
            return 1;
        }
        int ans = sumtill_N(num-1);
        return ans+ num;
    }
}
