package com.dsa;

/*
Description: Binary Search Program in Java using Recursion

Time Complexity: O(log N)
*/

public class BinarySearch {
    //main starts
    public static void main(String[] args) {
        int arr[] = {12, 19, 23, 45, 50, 67, 89};
        int target = 89;
        int ans = binarySearchR(arr, target, 0, arr.length - 1);
        System.out.println("Element found at index: "+ ans);
    }

    //function
    static int binarySearchR(int[] arr, int target, int start, int end) {
        //finding the mid
        int mid = start + (end - start) / 2;
        //base case, if element not found, return -1
        if (start > end) {
            return -1;
        }
        //return the index if the mid is found
        if (arr[mid] == target) {
            return mid;
        }
        //recursisve function call
        if (arr[mid] > target) {
            return binarySearchR(arr, target, start, mid - 1);
        } else {
            return binarySearchR(arr, target, mid + 1, end);
        }
    }
}
