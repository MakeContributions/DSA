// Program to divide a number without using the operator '/'

#include <stdio.h>
#include <stdlib.h>

int division(int A, int B);

int main() {
	// your code goes here
	int a, b;
	printf("Enter the two integers");
	scanf("%d %d", &a, &b);
	printf("The division is %d",division(a,b)); // Returns the floored output.
}

int division(int divisor, int dividend)
{
    int a = abs(divisor);
    int b = abs(dividend);
    int result = 0;
    while(a-b>=0)
    {   
        int x=0; // b<<0
        
        while(a -(b<<x<<1)>=0)
        {
            x++;
        }
        
        result += 1<<x;
        a -= b<<x;
    }
    
    return (divisor>0) == (dividend>0) ? result : -result ;
    
    
}