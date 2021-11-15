package com.dsa;

public class LinearSearch {
    public static void main(String[] args) {
        int arr[]={7,2,1,98,43,12,55};
        int target = 2;
        int ans = linearSearch(arr, target, 0);
        System.out.println("Element found at index: "+ ans);
    }

    static int linearSearch(int[] arr, int target, int i) {
        if(i==arr.length){
            return -1;
        }
        if(arr[i]==target){
            return i;
        }
        return linearSearch(arr, target, i+1);
    }
}
