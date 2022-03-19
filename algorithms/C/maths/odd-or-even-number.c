/**
     *This program checks if a number is odd or even.
     * 
     * Odd numbers are whole numbers that cannot be divided exactly by 2. If the number is not divisible by 2 entirely, 
     * it'll leave a remainder 1.
     * Even numbers are whole numbers that can be divided exactly by 2. If we divide the number by 2, it'll leave a remander 0.
     * 
     * Complexity -> O(1)
     *    _______________________________
     *   | INPUT | OUTPUT                |
     *   |   2   | It's an even number!  |
     *   |   1   | It's an odd number!   |
     *   |   3   | It's an odd number!   |
     *    _______________________________
* */

#include <stdio.h>

int main()
{
    int n;
    printf("Enter a number:\n");
    scanf("%d", &n);
    
    if(n % 2 == 0 ){
        printf("It's an even number!");
    }else{
        printf("It's an odd number!");
    }

    return 0;
}