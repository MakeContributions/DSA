// Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers.
// By convention, 1 is included. Write a program to find Nth Ugly Number

// Algorithm :
// Initialize three-pointers two, three, and five pointing to zero.
// Take 3 variables nm2, nm3, and nm5 to keep track of next multiple of 2,3 and 5.
// Make an array of size n to store the ugly numbers with 1 at 0th index.
// Initialize a variable next which stores the value of the last element in the array.
// Run a loop n-1 times and perform steps 6,7 and 8.
// Update the values of nm2, nm3, nm5 as ugly[two]*2, ugly[three]*3, ugly[5]*5 respectively.
// Select the minimum value from nm2, nm3, and nm5 and increment the pointer related to it.
// Store the minimum value in variable next and array.
// Return next.


import java.util.*;
class ugly_number {
    /* Function to get the nth ugly number*/
    public long getNthUglyNo(int n) {
        long[] ugly = new long[n];
        int two=0, three=0, five=0;
        long nm2=2, nm3=3, nm5=5;
        long next = 1;

        ugly[0] = 1;

        for(int i=1; i<n; i++){
            next = Math.min(nm2, Math.min(nm3, nm5));

            ugly[i] = next;
            if(next == nm2){
                two = two+1;
                nm2 = ugly[two]*2;
            }
            if(next == nm3){
                three = three+1;
                nm3 = ugly[three]*3;
            }
            if(next == nm5){
                five = five+1;
                nm5 = ugly[five]*5;
            }
        }
        return next;
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the value of n : ");
        int n = sc.nextInt();
        ugly_number ob = new ugly_number();
        long ugly = ob.getNthUglyNo(n);
        System.out.println("nth Ugly number is : "+ugly);
    }
}



/**
 * Time Complexity : O(n)
 * Auxiliary Space Complexity : O(n)
 *
 * Test Case 1 :
 * Input : 5
 * Output : 5
 *
 * Test Case 2 :
 * Input : 11
 * Output : 15
 *
 * Test Case 3 :
 * Input : 6
 * Output : 6
 */

/** Working for input : n = 5
 * initialize
 *    ugly[0] =  | 1 |
 *    two =  three = five = 0;
 *    nm2 = 2 , nm3 = 3 , nm5 = 5;
 *
 * First iteration
 *    ugly[1] = Min(ugly[two]*nm2, ugly[three]*nm3, ugly[five]*nm5)
 *             = Min(2, 3, 5)
 *             = 2
 *    ugly[] =  | 1 | 2 |
 *    two = 1,  three = five = 0  (two got incremented )
 *
 * Second iteration
 *     ugly[2] = Min(ugly[two]*nm2, ugly[three]*nm3, ugly[five]*nm5)
 *              = Min(4, 3, 5)
 *              = 3
 *     ugly[] =  | 1 | 2 | 3 |
 *     two = 1,  three =  1, five = 0  (three got incremented )
 *
 * Third iteration
 *     ugly[3] = Min(ugly[two]*nm2, ugly[three]*nm3, ugly[five]*nm5)
 *              = Min(4, 6, 5)
 *              = 4
 *     ugly[] =  | 1 | 2 | 3 |  4 |
 *     two = 2,  three =  1, five = 0  (two got incremented )
 *
 * Fourth iteration
 *     ugly[4] = Min(ugly[two]*nm2, ugly[three]*nm3, ugly[five]*nm5)
 *               = Min(6, 6, 5)
 *               = 5
 *     ugly[] =  | 1 | 2 | 3 |  4 | 5 |
 *     two = 2,  three =  1, five = 1  (five got incremented )
 *
 * Since five got incremented hence value of next becomes 5 and then it is returned
 */

