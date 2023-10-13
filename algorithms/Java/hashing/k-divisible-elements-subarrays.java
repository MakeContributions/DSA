package com.dsa;

import java.util.HashSet;

public class KDivisibleElementsSubarrays {
    /*
    Description: An example of hashing, Given an integer array nums and two integers k and p,
        return the number of distinct subarrays which have at most k elements divisible by p.
    Two arrays nums1 and nums2 are said to be distinct if:
        1. They are of different lengths, or
        2. There exists at least one index i where nums1[i] != nums2[i].
    A subarray is defined as a non-empty contiguous sequence of elements in an array.

    Input: nums = [2,3,3,2,2], k = 2, p = 2
    Output: 11
    */
    public static void main(String[] args) {
        int[] nums = {2,3,3,2,2};
        int k = 2, p = 2;
        int ans = countDistinct(nums, k, p);
        System.out.println("Output : " + ans);


    }

    public static int countDistinct(int[] nums, int k, int p) {
        int n=nums.length;
        HashSet<String> set = new HashSet<>();
        int ans=0;
        for(int i=0; i<n; i++){
            StringBuilder str = new StringBuilder();
            int count=0;
            for(int j=i; j<n; j++){
                str.append(nums[j]+" ");
                if((nums[j]%p)==0){
                    count++;
                }

                if(count<=k){
                    if(!set.contains(str.toString())) ans++;
                    set.add(str.toString());
                }else break;
            }
        }

        return ans;
    }
}
