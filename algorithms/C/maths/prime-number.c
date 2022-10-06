/***
 * This program checks if a number is prime or not.
 * 
 * A number is called prime if has only two factors 1 and itself. 1 is not a prime number.
 * 2, 3, 5, 7, 11 etc. are prime numbers since these numbers has only two factors.
 * 
 * Time Complexity : O(sqrt(n))
 *    __________________________________
 *   | INPUT | OUTPUT                   |
 *   |   1   | 1 is not a Prime number. |
 *   |   2   | 2 is a Prime number.     |
 *   |   3   | 2 is a Prime number.     |
 *    __________________________________
*/

#include<stdio.h>
#include<math.h>

int is_prime(int n)
{
    if(n <= 1) return 0;    // not a prime number.
    if(n == 2) return 1;    //  is a prime number.

    if(n % 2 == 0) return 0; // not a prime number.

    int sqrtN = sqrt(n);
    int i;

    for(i = 3; i <= sqrtN; i+=2){
        if(n % i == 0) return 0;    // not a prime number.
    }

    return 1;   // is a prime number.
}
int main()
{
    int n;
    printf("Enter the number : ");
    scanf("%d", &n);

    if(is_prime(n)){
        printf("%d is a Prime number.\n", n);
    }
    else{
        printf("%d is not a Prime number.\n", n);
    }

    return 0;
}
