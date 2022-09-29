#include <stdio.h>

#define MAX 1000001
int sieve[MAX];

/*

    Why do we use such a big number? Because we don't know how big the interval is, 
    we give as much freedom as possible; note that this number may not work for your 
    computer, and you will need to make it smaller, or if it works, you can make it bigger.

*/


/*

[PROBLEM TO SOLVE]: Given a number "n", find all prime numbers till "n" inclusive.

    A prime number is a number which has only 2 divisors: 1 and itself.

[EXAMPLE]: n = 22

    -> The numbers are: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22

    -> The prime numbers are: 2 3 5 7 11 13 17 19

[APPROACH]: Sieve Of Eratosthenes algorithm

[IDEA]:

    -> We have to analyze numbers from 2 to n. So, firstly, we write them down:

    2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 ... n

    -> Next, we will do something which is called marking. To illustrate this, I will put "*" below the numbers.

    -> We begin from 2 till n, and for every number, we mark all its multiples till n inclusive.

    -> We are at 2, so we mark 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26 and all numbers 2 * k, with k > 1 and stop when 2 * k > n.

    2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 ... n
        *   *   *   *     *     *     *     *     *     *     *     *

    -> We move at 3 so we mark 6, 9, 12, 15, 18, 21, 24 and all numbers 3 * k, with k > 1 and stop when 3 * k > n.

    2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 ... n
        *   *   * * *     *     *  *  *     *     *  *  *     *     *

    -> We continue this process by taking every number till n and marking all its multiples till n inclusive.

    -> By the end of this algorithm, the numbers that remained unmarked are only prime numbers.

[TIME COMPLEXITY]:

    For every i till sqrt(n), we perform n / i operations, where i is prime.

    The ecuation is:
    sqrt(n) * (n/3 + n/4 + n/5 + n/6 + n/7 + ...)
    = sqrt(n) * n * (1/3 + 1/4 + 1/5 + 1/6 + 1/7 + ...)
    The third factor, according to Euler, grows the same as ln(ln(n))

    So the time complexity is: O(sqrt(n) * n * ln(ln(n))).

[SPACE COMPLEXITY]: O(n)

*/


void sieve_of_eratosthenes(unsigned long long n)
{
    sieve[0] = sieve[1] = 1; // we know that 0 and 1 are already pries so we mark them

    for (unsigned long long i = 4; i <= n; i += 2) sieve[i] = 1; // We know that every even number greater than 2 is not prime.
                                                                // We can mark in advance these numbers by beginning from 4 and 
                                                               // iterating from 2 to 2.

    for (unsigned long long i = 3; i * i <= n; i += 2) // it is enough to iterate till sqrt(n)
    {
        // marking numbers
        for (unsigned long long j = i * i; j <= n; j += 2 * i) sieve[j] = 1; // We can begin from i * i because all numbers till i * i have been already marked
                                                                            // We iterate with j += 2 * i to avoid even numbers marked before 
    }

    /*
        In Sieve of Eratosthenes, we use a global array, and global variables are
        automatically initialized with 0. So we use that to our advantage instead of 
        manually setting all memory spaces with 0.


        We are doing marking like this:
            0 - prime
            1 - not prime


        Why? I know that using 1 for primes and 0 for not primes would have been more
        intuitive, but declaring an array in global scope, it got initialized with 0, so
        it is just a waste to overwrite all memory spaces with 1.

    */
}


// Utility function to print prime numbers
void print_prime_numbers(unsigned long long n)
{
    for (unsigned long long i = 2; i <= n; ++i)
    {
        if (sieve[i] == 0) printf("%llu ", i); // if number is not marked (it is a prime number) we print it
    }
}


// Driver program
int main()
{
    unsigned long long n; printf("Enter number: ");  scanf("%llu", &n);
    sieve_of_eratosthenes(n);

    printf("\n\nPrime numbers are:\n");
    print_prime_numbers(n);
    printf("\n");
}


/*

    [SAMPLE INPUT 1]: 
    22
    Output: 2 3 5 7 11 13 17 19

    [SAMPLE INPUT 2]:
    46
    Output: 2 3 5 7 11 13 17 19 23 29 31 37 41 43

    [SAMPLE INPUT 3]:
    100
    Output: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97

*/


/*

[OBSERVATIONS]:

    -> Note that I used unsigned long long for variables, and operations like raising to power can
       easily exceed unsigned long long, so be careful with input numbers.

    -> You can play around with #define MAX 1000000001 and #define MAX_PRIMES 100000001. Try to find
       which is the maximum limit accepted by your computer.

    -> To make this algorithm space-efficient, you can change to C++ and use a vector container from the STL library like
       this [vector <bool> vector_name]. Before that, include vector library like #include <vector>. That
       container is not a regular one. It is a memory-optimization of template classes like vector <T>,
       which uses only n/8 bytes of memory. Many modern processors work faster with bytes because they
       can be accessed directly. Template class vector <T> works directly with bits. But these things 
       require knowledge about template classes, which are very powerful in C++.

    -> This algorithm can be optimized using bits operations to achieve linear time.
       But ln(ln(n)) can be approximated to O(1).
*/