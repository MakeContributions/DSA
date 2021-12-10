package com.dsa;

//first and last occurrence of an element in an array
public class FirstLastOccurence {
    public static void main(String[] args) {
        int arr[] = {7, 2, 2, 2, 9, 6};
        int ele = 2;
        int first = firstOccurence(arr, ele, 0);
        int last = lastOccurence(arr, ele, arr.length - 1);
        System.out.println("First Occurrence: " + first);
        System.out.println("Last Occurrence: " + last);
    }

    static int lastOccurence(int[] arr, int ele, int ind) {
        if (ind < 0) {
            return -1;
        }
        if (arr[ind] == ele) {
            return ind;
        }
        return lastOccurence(arr, ele, ind - 1);
    }

    static int firstOccurence(int[] arr, int ele, int ind) {
        if (ind == arr.length) {
            return -1;
        }
        if (arr[ind] == ele) {
            return ind;
        }
        return firstOccurence(arr, ele, ind + 1);
    }

    /*
    First Occurrence: 1
    Last Occurrence: 3
    */
}
