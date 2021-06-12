//Given an array A of N elements. Find the majority element in the array.
//A majority element in an array A of size N is an element that appears more than N/2 times in the array

// Moore’s Voting Algorithm => Time Complexity: O(n), Space Complexity: O(1)

import java.util.*;
import java.io.*;
import java.lang.*;

class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0) {
            int n =sc.nextInt();
            int arr[] = new int[n];
            
            for(int i = 0; i < n; i++)
             arr[i] = sc.nextInt();
             
           System.out.println(new Solution().majorityElement(arr, n)); 
        }
    }
}

class Solution
{
    static int majorityElement(int a[], int size){
        int cand = findCand(a, size);
        if(isMajority(a, size, cand))
            return cand;
        return -1;
    }
    
    static int findCand(int arr[], int n){
        int max_index=0; int count=1;
        for(int i=1; i<n; i++){
            if(arr[max_index]==arr[i])
                count++;
            else count--;
            if(count==0){
                max_index=i;
                count=1;
            }
        }
        return arr[max_index];
    }
    
    static boolean isMajority(int arr[], int n, int cand){
        int count=0;
        for(int i=0; i<n; i++){
            if(cand==arr[i])
                count++;
        }
        if(count > n/2) return true;
        return false;
    }
}

/* Test Case: 
Input:
N = 5  A[] = {3,1,3,3,2} 

Output: 3

Explanation:
Since, 3 is present more
than N/2 times, so it is 
the majority element. */