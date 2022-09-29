// Target sum subsets is a program to print all subsets of an array (given by user) such that sum of all elements in subset equal to a target sum given by user

// Algorithm Type: Backtracking
// Time Complexity: O(2^N)

import java.io.*;
import java.util.*;

public class targetSumSubsets {

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);

        // input size of array
        int n = scn.nextInt();

        // input elements of array
        int[] arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = scn.nextInt();
        }

        // input target sum
        int tar = scn.nextInt();

        // calling our function - printTargetSumSubsets
        printTargetSumSubsets(arr, 0, "", 0, tar);
        scn.close();
    }

    // set is the subset, sum is the sum so far for that subset
    public static void printTargetSumSubsets(int[] arr, int idx, String set, int sum, int tar){   
        if (idx == arr.length){
            if (sum == tar){
                System.out.println(set + " ");
            }
            return;
        }

        // pick
        printTargetSumSubsets(arr, idx + 1, set + arr[idx] + " ", sum + arr[idx], tar);
       
        //not pick
        printTargetSumSubsets(arr, idx + 1, set, sum, tar);    
    }

    

}