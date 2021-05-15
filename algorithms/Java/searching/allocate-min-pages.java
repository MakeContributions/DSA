/* QUESTION:
You are given N number of books. Every ith book has pages[i] number of pages. 
You have to allocate books to M number of students. There can be many ways or permutations to do so. 
In each permutation, one of the M students will be allocated the maximum number of pages.
Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is minimum of those in all the other permutations and print this minimum value.
Each book will be allocated to exactly one student. Each student has to be allocated at least one book. */

import java.io.*;
import java.util.*;
class GFG {
	public static void main (String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();  //number of test cases
		while(t-->0){
		    int N=sc.nextInt();
		    int pages[]=new int[N];
		    
		    for(int i=0;i<N;i++){
		        pages[i]=sc.nextInt();
		    }
		    int M=sc.nextInt();
		    System.out.println(findPages(pages,N, M));
		}
	}

    public static int findPages(int[]arr,int n,int m)
    {
        if(n<m) return -1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        int start=0, end=sum;
        int res = Integer.MAX_VALUE;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isPossible(arr, n, m, mid)){
                res = Math.min(res, mid);
                end = mid-1;
            }
            else start=mid+1;
        }
        return res;
    }
    public static boolean isPossible(int arr[], int n, int m, int curr_min){
        int student=1;
        int curr_sum=0;
        for(int i=0;i<n;i++){
            if(arr[i]>curr_min) return false;
            if(curr_sum+arr[i]>curr_min){
                student++;
                curr_sum = arr[i];
                if(student>m) return false;
            }
            else curr_sum+=arr[i];
        }
        return true;
    }
}

/* 
Input:
N = 4
A[] = {12,34,67,90}
M = 2

Output:
113

Explanation: 
Allocation can be done in following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90}  Maximum Pages =113
Therefore, the minimum of these cases is 
113, which is selected as the output.
 */
