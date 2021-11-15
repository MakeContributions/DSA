package com.dsa;

import static java.util.Arrays.binarySearch;

public class BinarySearch {
    public static void main(String[] args) {
        int arr[] = {12, 19, 23, 45, 50, 67, 89};
        int target = 89;
        int ans = binarySearchR(arr, target, 0, arr.length - 1);
        System.out.println("Element found at index: "+ ans);
    }

    static int binarySearchR(int[] arr, int target, int start, int end) {
        int mid = start + (end - start) / 2;
        if (start > end) {
            return -1;
        }
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] > target) {
            return binarySearchR(arr, target, start, mid - 1);
        } else {
            return binarySearchR(arr, target, mid + 1, end);
        }
    }
}
