import java.util.*;

/*
Problem Name - Permutation Sequence

Description
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

1.  "123"
2.  "132"
3.  "213"
4.  "231"
5.  "312"
6.  "321"
Given n and k, return the kth permutation sequence.

Sample Cases:
Example 1:
Input: n = 3, k = 3
Output: "213"

Example 2:
Input: n = 4, k = 9
Output: "2314"

Example 3:
Input: n = 3, k = 1
// Output: "123"

Constraints:

 1 <= n <= 9
 1 <= k <= n!

You can also practice this question on LeetCode(https://leetcode.com/problems/permutation-sequence/)*/


/***Brute Force is to form an array of n size and then compute all the permutations and store it in the list and then trace it with (k-1)**
**Caution : the permutations should be in sorted order to get the answer**
*This will give TLE as we have to calculate all the permutations*
```
class Solution {
    public String getPermutation(int n, int k) {
        int ar[] = new int[n];
        
        for(int x=1;x<=n;x++)
            ar[x-1]=x;
        List<List<Integer>> ans=new ArrayList<>();
        backtrack(ans,new ArrayList<>(),ar);
        String s="";
        for(int x:ans.get(k-1))
            s+=x;
        
        return s;
     }
    public void backtrack(List<List<Integer>> list, List<Integer> tempList, int [] nums){
   if(tempList.size() == nums.length){
      list.add(new ArrayList<>(tempList));
   } else{
      for(int i = 0; i < nums.length; i++){ 
         if(tempList.contains(nums[i])) continue; // element already exists, skip
         tempList.add(nums[i]);
         backtrack(list, tempList, nums);
         tempList.remove(tempList.size() - 1);
      }
   }
} 
    
    
}
```

**Best Approach**
I'm sure somewhere can be simplified so it'd be nice if anyone can let me know. The pattern was that:

say n = 4, you have {1, 2, 3, 4}

If you were to list out all the permutations you have

1 + (permutations of 2, 3, 4)

2 + (permutations of 1, 3, 4)

3 + (permutations of 1, 2, 4)

4 + (permutations of 1, 2, 3)


We know how to calculate the number of permutations of n numbers... n! So each of those with permutations of 3 numbers means there are 6 possible permutations. Meaning there would be a total of 24 permutations in this particular one. So if you were to look for the (k = 14) 14th permutation, it would be in the

3 + (permutations of 1, 2, 4) subset.

To programmatically get that, you take k = 13 (subtract 1 because of things always starting at 0) and divide that by the 6 we got from the factorial, which would give you the index of the number you want. In the array {1, 2, 3, 4}, k/(n-1)! = 13/(4-1)! = 13/3! = 13/6 = 2. The array {1, 2, 3, 4} has a value of 3 at index 2. So the first number is a 3.

Then the problem repeats with less numbers.

The permutations of {1, 2, 4} would be:

1 + (permutations of 2, 4)

2 + (permutations of 1, 4)

4 + (permutations of 1, 2)

But our k is no longer the 14th, because in the previous step, we've already eliminated the 12 4-number permutations starting with 1 and 2. So you subtract 12 from k.. which gives you 1. Programmatically that would be...

k = k - (index from previous) * (n-1)! = k - 2*(n-1)! = 13 - 2*(3)! = 1

In this second step, permutations of 2 numbers has only 2 possibilities, meaning each of the three permutations listed above a has two possibilities, giving a total of 6. We're looking for the first one, so that would be in the 1 + (permutations of 2, 4) subset.

Meaning: index to get number from is k / (n - 2)! = 1 / (4-2)! = 1 / 2! = 0.. from {1, 2, 4}, index 0 is 1


so the numbers we have so far is 3, 1... and then repeating without explanations.


{2, 4}

k = k - (index from previous) * (n-2)! = k - 0 * (n - 2)! = 1 - 0 = 1;

third number's index = k / (n - 3)! = 1 / (4-3)! = 1/ 1! = 1... from {2, 4}, index 1 has 4

Third number is 4


{2}

k = k - (index from previous) * (n - 3)! = k - 1 * (4 - 3)! = 1 - 1 = 0;

third number's index = k / (n - 4)! = 0 / (4-4)! = 0/ 1 = 0... from {2}, index 0 has 2

Fourth number is 2


Giving us 3142. If you manually list out the permutations using DFS method, it would be 3142. Done! It really was all about pattern finding.
 */

public class permutation_sequence {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();

        System.out.println(getPermutation(n, k));
    }

    public static String getPermutation(int n, int k) {
        List<Integer> numbers = new ArrayList<>();
        StringBuilder s = new StringBuilder();
        // create an array of factorial lookup
    
        int fact[] = new int[n+1];
        fact[0] = 1;
        for(int x=1;x<=n;x++)
            fact[x]=fact[x-1]*x;
        // factorial[] = {1, 1, 2, 6, 24, ... n!}
        
        // create a list of numbers to get indices
        for(int x = 1 ;x <= n ;x++)
            numbers.add(x);
        
        k--;
        // numbers = {1, 2, 3, 4}
        
        for(int x = 1 ;x <= n ;x++ ){
            int i=k/fact[n-x];
            s.append(String.valueOf(numbers.get(i)));
            numbers.remove(i);
            k-=i*fact[n-x];
        }
        
        return s.toString();
    }
}


