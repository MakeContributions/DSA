// Shift and add algo for multiplication without using multiplication operator 

#include <stdio.h>
#include <stdlib.h>

int main() {


	// your code goes here
	int mA, mB;
	printf("Enter the two inputs\n");
	scanf("%d %d", &mA, &mB);
	int a = 0, m0 = 0,  m1 = 0;
	m0 = mA > 0 ? mA : abs(mA);  // negative input.
	m1 = mB > 0 ? mB : abs(mB);
	
    while(m1)
    {
        if((m1 & 0x01))   
            a += m0;
        
        m0 <<= 1;
        m1 >>= 1;
    }
	if(mA < 0 || mB < 0)   
	    a = -a;
	    
	printf("The product is %d", a); 
	return 0;
}
