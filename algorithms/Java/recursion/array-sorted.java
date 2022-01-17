package com.dsa;

/*
Description: To find whether array is sorted or not using recursion

Time Complexity: O(n) where n is the number of elements present in the array
*/

public class ArraySorted {

    //    function body
    static boolean isSorted(int[] arr, int n) {
        //base case
        //if the length of the array is 1, it means it is sorted
        //so return true
        if (n == 1) {
            return true;
        }
        //since n means length of the array, check if the element at n-1 index(last) is greater than the element at n-2 index (second last)
        //if it is greater, then make a recursive function call for checking the remaining elements
        if (arr[n - 1] > arr[n - 2]) {
            return isSorted(arr, n - 1);
        }
        //if not, return false
        //this means array is not sorted
        return false;
    }
    //main starts
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5};
        boolean ans = isSorted(arr, arr.length);
        System.out.println("Array sorted : " + ans);
    }
    /*
    Sample Input:
    arr = [1, 2, 3, 4, 5]

    Output: Array sorted : true
    */
}
