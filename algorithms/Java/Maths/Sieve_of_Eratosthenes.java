/**

     Working of the Algorithm

    In the following algorithm, the number 0 represents a composite number.

    1. To find out all primes under n, generate a list of all integers from 2 to n. (Note: 1 is not prime)
    2. Start with a smallest prime number, ie p = 2p=2.
    3. Mark all the multiples of pp which are less than nn as composite. To do this, mark the value of the numbers (multiples of pp) in the generated list as 0. Do not mark pp itself as composite.
    4. Assign the value of p to the next prime. The next prime is the next non-zero number in the list which is greater than p.
    5. Repeat the process until p is less than or equal to square root of n.


 */
import java.util.*;
public class Sieve_of_Eratosthenes {

    static boolean[] sieveOfEratosthenes(int n) {
        boolean[] isPrime = new boolean[n + 1];

        Arrays.fill(isPrime, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            for (int j = 2 * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
        return isPrime;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the maximum number upto which prime numbers are required: ");
        int n = sc.nextInt();
        boolean[] isPrime = sieveOfEratosthenes(n);
        System.out.print("Following are the prime numbers: ");
        for (int i = 0; i <= n; i++) {
            if (isPrime[i]) {
                System.out.print(i + " ");
            }
        }
    }
}


/* Time Complexity: O(n*log(log(n)))
   Auxiliary Space: O(n)
   Constraint: n = 10,000,000
 */