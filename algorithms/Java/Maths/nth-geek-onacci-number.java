/** Author : Suraj Kumar
 * Github : https://github.com/skmodi649
 */



/** PROBLEM DESCRIPTION :
 * Geek created a random series and given a name geek-onacci series
 * Given four integers a, b, b, n
 * a, b, c represents the first three numbers of geek-onacci series
 * Find the Nth number of the series.
 * The nth number of geek-onacci series is a sum of the last three numbers (summation of N-1th, N-2th, and N-3th geek-onacci numbers)
 */


/** ALGORITHM :
 * Simply use the concept of Recursion
 * Define the base cases of the Recursion for n equal to 1 , 2 and 3
 * Then simply use recurrence in the same way as we used it in Fibonacci series
 */



import java.util.*;
import java.lang.*;

class GFG {
    public static int rec(int a,int b,int c,int n)
    {
        if(n==1)
            return a;
        else if(n==2)
            return b;
        else if(n==3)
            return c;
        else
            return rec(a,b,c,n-1)+rec(a,b,c,n-2)+rec(a,b,c,n-3);
    }
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
            int a,b,c,n;
            System.out.print("Enter the first number of Geek-onacci series : ");
            a = sc.nextInt();
        System.out.print("Enter the second number of Geek-onacci series : ");
            b = sc.nextInt();
        System.out.print("Enter the third number of Geek-onacci series : ");
            c = sc.nextInt();
            System.out.print("Enter the values of n : ");
            n = sc.nextInt();
            int val = rec(a,b,c,n);
            System.out.println("Nth Geek-onacci number : "+val);
        }
    }



/** TEST CASES :
 * Test Case 1 :
 * Input : a = 1 , b = 3 , c = 2 , n = 4
 * Output : 6
 *
 * Test Case 2 :
 * Input : a = 1 , b = 3 , c = 2 , n = 5
 * Output : 11
 *
 * Test Case 3 :
 * Input : a = 1 , b = 3 , c = 2 , n = 6
 * Output : 19
  */


/** Explanation for a = 1 , b = 3 , c = 2 , n = 5
 * n = 5 then val = rec(1,3,2,4)+rec(1,3,2,3)+rec(1,3,2,2)
 * rec(1,3,2,2) gives 3 and rec(1,3,2,3) gives 2 hence both totally give 3 + 2 = 5
 * rec(1,3,2,4) is actually equal to rec(1,3,2,3)+rec(1,3,2,2)+rec(1,3,2,1) hence gives 2 + 3 + 1 = 6
 * Now val = 6 + 5 = 11
 * 11 will be returned as output
 */


/** Time Complexity : O(n)
 * Auxiliary Space Complexity : O(1)
 * Constraints : 1 <= A, B, C <= 100
 *               N >= 4
 */




