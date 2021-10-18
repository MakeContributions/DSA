// Program to merge two sorted arrays without any extra space in Java
/*
Author : Suraj Kumar Modi
Github : https://github.com/skmodi649
 */


/** Algorithm :
 * 1) Initialize i,j as n-1,0 where n is size of arr1
 * 2) Iterate through every element of arr1 and arr2 using two pointers i and j respectively
 *   while(i>=0 && j<m)
 *     if arr1[i] is more than arr2[j]
 *         swap arr1[i] and arr2[j]
 *     else
 *         decrement i
 *         increment j
 *
 * 3) Sort both arr1 and arr2
 */

import java.util.*;

class MergingWithoutExtraSpace {
    // Driver code
    public static void main(String[] args) {

            Scanner sc = new Scanner(System.in);
            System.out.println("Enter the sizes of arr1 and arr2  respectively : ");
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[] arr1 = new int[n];
            int[] arr2 = new int[m];
            System.out.println("Enter elements in the arr1 : ");
            for (int i = 0; i < n; i++) {
                arr1[i] = sc.nextInt();
            }
            System.out.println("Enter elements in the arr2 : ");
            for (int i = 0; i < m; i++) {
                arr2[i] = sc.nextInt();
            }

            System.out.println("Merged array : ");
        MergingWithoutExtraSpace ob = new MergingWithoutExtraSpace();
            ob.merge(arr1 , arr2 , n , m);

            StringBuffer str = new StringBuffer();
            for (int i = 0; i < n; i++) {
                str.append(arr1[i]).append(" ");
            }
            for (int i = 0; i < m; i++) {
                str.append(arr2[i]).append(" ");
            }
            System.out.println(str);
        }

    public void merge(int[] arr1, int[] arr2, int n, int m) {
        int i = n-1 , j = 0;
        while(i>=0 && j<m)
        {
            if(arr1[i] > arr2[j])
            {
                int temp = arr1[i];
                arr1[i] = arr2[j];
                arr2[j] = temp;
            }
            i--;
            j++;
        }
        Arrays.sort(arr1);
        Arrays.sort(arr2);
    }
}


/** TEST CASES :
 *
 * Test Case 1 :
 * Input : n = 3 , m = 4
 * arr1[] = {1,27,36}    arr2[] = {12,14,16,22}
 * Output :
 * 1 12 14 16 22 27 36
 *
 * Test Case 2 :
 * Input : n = 4 , m = 5
 * arr1[] = {0,12,21,27}    arr2[] = {4,6,8,10,12}
 * Output :
 * 0 4 6 8 10 12 12 21 27
 */

/**
 * Time Complexity : O((n+m)log(n+m))
 * Auxiliary Space Complexity : O(1)
 */


