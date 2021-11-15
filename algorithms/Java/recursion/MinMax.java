package com.dsa;
/*
Description: Java Program to find minimum and maximum value from the array using recursion

Time Complexity: O(n) where n is the number of elements inside the array

*/

public class Main {


    //function to find maximum element in the array
    static int findMax(int[] arr, int n) {
        //base case
        //if there is only 1 element in array, it will be the maximum element
        if (n == 1) {
            return arr[0];
        }
        //recursive function call
        int mx = findMax(arr, n - 1);
        //return maximum element from every recursive call to the function
        return Math.max(arr[n - 1], mx);

    }

    //function to find minimum element in the array
    static int findMin(int[] arr, int n) {
        //base case
        //if there is only 1 element in array, it will be the minimum element
        if (n == 1) {
            return arr[0];
        }
        //recursive function call
        int mn = findMin(arr, n - 1);
        //return minimum element from every recursive call to the function
        return Math.min(arr[n - 1], mn);
    }

    public static void main(String[] args) {
        int[] arr = {-1, -2, 3, 4, 5, 6};
        int min = findMin(arr, arr.length);
        System.out.println("Minimum element in array: " + min);
        int max = findMax(arr, arr.length);
        System.out.println("Maximum element in array: " + max);
    }

    /*
    Sample Input:
    arr=[-1,-2,3,4,5,6]
    Output:
    Minimum element in array: -2
    Maximum element in array: 6
    */
}
