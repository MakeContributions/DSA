/* Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, 
the consecutive numbers can be in any order. */

/* Time Complexity: O(n) 
   Space Complexity: O(n) */

import java.math.*;
import java.util.*;
import java.io.*;

class Driverclass {
    static class FastReader{ 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader(){ 
            br = new BufferedReader(new InputStreamReader(System.in)); 
        } 
  
        String next(){ 
            while (st == null || !st.hasMoreElements()){ 
                try{ st = new StringTokenizer(br.readLine()); } catch (IOException  e){ e.printStackTrace(); } 
            } 
            return st.nextToken(); 
        } 
  
        String nextLine(){ 
            String str = ""; 
            try{ str = br.readLine(); } catch (IOException e) { e.printStackTrace(); } 
            return str; 
        } 

        Integer nextInt(){
            return Integer.parseInt(next());
        }
    }
    
	public static void main(String args[]) {
		FastReader sc = new FastReader();
		PrintWriter out = new PrintWriter(System.out);
		int t = sc.nextInt();
		
		while(t>0) {
			int n = sc.nextInt();
			int a[] = new int[n];
			
			for(int i=0; i<n; i++)
				a[i] = sc.nextInt();
		    out.println(new Solution().findLongestConseqSubseq(a, n));
		    t--;
		}
		out.flush();
	}
}

class Solution {   
    // arr[] : the input array
    // N : size of the array arr[]
	static int findLongestConseqSubseq(int arr[], int n){
	   Set<Integer> set = new HashSet<>();
	   int ans=0;
	   for(int num: arr)
	       set.add(num);
	   for(int i=0; i<n; i++){
	       if(!set.contains(arr[i]-1)){
	           int j = arr[i];
	           while(set.contains(j))
	               j++;
	           ans = Math.max(ans, j-arr[i]);
	       }
	   }
	   return ans;
	}
}

/* 
Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.
 */