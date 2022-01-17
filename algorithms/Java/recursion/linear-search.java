package com.dsa;
/*
Description: Linear search in java using recursion

Time Complexity: O (N)
 */

public class LinearSearch {
    //main starts
    public static void main(String[] args) {
        int arr[]={7,2,1,98,43,12,55};
        int target = 2;
        int ans = linearSearch(arr, target, 0);
        System.out.println("Element found at index: "+ ans);
    }

    //function
    static int linearSearch(int[] arr, int target, int i) {
        //base case
        if(i==arr.length){
            return -1;
        }
        //if the target element is found, return its index
        if(arr[i]==target){
            return i;
        }
        //make a recursive function call by incrementing variable i by 1
        return linearSearch(arr, target, i+1);
    }
}
