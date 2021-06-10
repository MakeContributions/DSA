// function to add, sub without using the operators 

#include <stdio.h>

// Prototypes
int add(int, int);
int sub(int, int);


int main() {

	int a, b;

	printf("Enter two integers\n");

	scanf("%d %d", &a, &b);

	int s,d;

	d = add(a,b);

	s = sub(a,b);

	printf("%d %d",s,d);  // output 2 and 10

	return 0;
}

// function to add 
int add(int a, int b)
{
    int c = 0; //carry	
	while(b !=0)
	{
	    c = a&b;
	    a = a^b;
	    b = c<<1;
	} 
	
	return a;
}

// function to sub
int sub(int a, int b) 
{
    int s,d;
    d = add((~b),1);
    s = add(a,d);
    return s;
} // subtraction is addition in disguise (just flip the subtracting term and that's what this function does.) 
