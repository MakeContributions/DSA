/*
 Code Binary Search

You have been given a sorted(in ascending order) integer array/list(ARR) of size N and an element X. Write a function to search this element in the given input array/list using 'Binary Search'. Return the index of the element in the input array/list. In case the element is not present in the array/list, then return -1.
Input format :
The first line contains an Integer 'N' which denotes the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Third line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow..

All the 't' lines henceforth, will take the value of X to be searched for in the array/list.
Output Format :
For each test case, print the index at which X is present, -1 otherwise.

Output for every test case will be printed in a separate line.

input:
5
1 2 4 6 9 
3
2
9
1

output:
1
4
0
*/
package searchingandsorting;

import java.util.Scanner;

public class BinarySearch {
	public static int BinSearch(int arr[], int x) {
		int s = 0;
		int e = arr.length-1;
		int m = (s+e)/2;
		
		while(s <= e) {
			
			if (arr[m] > x) {
				e = m - 1;
			}
			else if (arr[m] < x) {
				s = m + 1;
			}
			else if (arr[m] == x) {
				return m;
			}
			m = (s+e)/2;
		}
		return -1;
	}
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in); 
		
		System.out.println("Enter size of array: ");
		int n = s.nextInt();
		int arr[] = new int[n];
		
		for (int j = 0; j < arr.length; j++) {
			arr[j] = s.nextInt();
		}
		
		System.out.println("Enter total number of test cases: ");
		int t = s.nextInt();
		
		for(int i = 0; i < t; i++) {
		System.out.println("Enter the number to be searched: ");
		int x = s.nextInt();
		
		int index = BinSearch(arr, x);
		System.out.println();
		System.out.println("Index is "+ index);
		}
  }
}
