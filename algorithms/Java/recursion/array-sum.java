package com.dsa;

/*
Description: To find the sum of all the elements in the array using recursion

Time Complexity: O(n)
*/

public class ArraySum {

    //function starts
    static int findSum(int[] arr, int n) {
        //base case
        //if there is only one element in the array
        //that element will be the sum
        if (n == 1) {
            return arr[0];
        }
        //recursive function call
        int ans = findSum(arr, n - 1);
        //add all the array elements in the answer
        return ans + arr[n - 1];
    }

    //main starts
    public static void main(String[] args) {
        int arr[] = {3, 4, 6};
        int ans = findSum(arr, arr.length);
        System.out.println("Sum is: " + ans);
    }
/*
Sample Input:
arr=[3,4,6]

Output:
Sum is: 13
*/
}
