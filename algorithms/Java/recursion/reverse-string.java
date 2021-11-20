package com.dsa;

import java.util.Arrays;
import java.util.Collections;

public class ReverseString {
    public static void main(String[] args) {
        StringBuilder s = new StringBuilder("latte");
        String ans = reverse(s, 0, s.length() - 1);
        System.out.println(ans);
        //another way
        String s1 = "hiii";
        char arr[] = s1.toCharArray();
        char ans2[] = reverse2(arr, 0, arr.length - 1);
        String a = String.valueOf(ans2);
        System.out.println(a);
    }

    static char[] reverse2(char[] arr, int start, int end) {
        if (start > end) {
            return arr;
        }
        char temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        return reverse2(arr, start + 1, end - 1);

    }

    static String reverse(StringBuilder s, int start, int end) {
        if (start > end) {
            return s.toString();
        }
        char temp = s.charAt(end);
        s.setCharAt(end, s.charAt(start));
        s.setCharAt(start, temp);
        return reverse(s, start + 1, end - 1);
    }
}
