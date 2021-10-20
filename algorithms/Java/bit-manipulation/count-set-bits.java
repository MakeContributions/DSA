/** Problem Description :
 * You are given a number N. Find the total count of set bits for all numbers from 1 to N
 * including 1 and N
 */


/**
 * Author : Suraj Kumar
 * Github : https://github.com/skmodi649
 */


/** ALGORITHM :
 * So, we will iterate till the number of bits in the number.
 * And we don’t have to iterate every single number in the range from 1 to n.
 * We will perform the following operations to get the desired result.
 * The quotient when n+1 is divided by 2 will return the number of times the 0,1 pattern has appeared at LSB.
 * However, the quotient when n+1 is divided by 4 will return the number of times the 0,0,1,1 pattern has
 * appeared at 2nd least significant bit and so on.
 */


/** TEST CASES :
 * Test Case 1 :
 * Input: N = 4
 * Output: 5
 *
 * Test Case 2 :
 * Input: N = 17
 * Output: 35
 */

import java.util.*;
import java.lang.*;


class Solution {

    //Function to return sum of count of set bits in the integers from 1 to n.
    public static int countSetBits(int n) {
        int count = 0 , i = 1 , val = 0;
        while ((n + 1) / (int) Math.pow(2, i) != 0) {
            int k = (n + 1) % (int) Math.pow(2, i);
            val = (n + 1) / (int) Math.pow(2, i);
            int c = (int) Math.pow(2, i - 1);
            count = count + c * val;
            if (k > ((int) Math.pow(2, i) / 2)) {
                count = count + (k - ((int) Math.pow(2, i) / 2));
            }
            i++;
        }
        int temp = (int) Math.pow(2, i);
        count += (n + 1 - temp / 2);
        return count;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number :");
            int n = sc.nextInt();//input n

            Solution obj = new Solution();
            System.out.println("Total set bits : "+obj.countSetBits(n)); // calling countSetBits method
            System.out.println();        // changing the line
        }
    }



/** Explanation for N = 4
 * For numbers from 1 to 4.
 * For 1: 0 0 1 = 1 set bits
 * For 2: 0 1 0 = 1 set bits
 * For 3: 0 1 1 = 2 set bits
 * For 4: 1 0 0 = 1 set bits
 * Therefore, the total set bits is 5.
  */


/** Time Complexity : O(log N)
* Auxiliary Space Complexity : O(1)
* Constraints : 1 ≤ N ≤ 10^8
*/
