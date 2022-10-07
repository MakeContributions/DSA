/*
Factorial of the number: Factorial of a non-negative integer is the multiplication of all positive integers smaller than or equal to n.
For example factorial of 6 is 6*5*4*3*2*1 which is 720.
  Input    |    Output
  5        |    120
  6        |    720
  3        |    6
Time Complexity - O(log(n))
Space Complexity- O(1)

*/
#include<stdio.h>
int fact(int n){
	if(n==1){
		return 1;
	}
	else{
		return n*fact(n-1);
	}
}
void main(){
	int an;
	printf("Enter a number");
	scanf("%d",&an);
	int f=fact(an);
	printf("factorial of %d is %d",an,f);
}
