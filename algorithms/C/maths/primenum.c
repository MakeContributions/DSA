/*
- It is the program that checks whether the given number is Prime number or not
- Prime number-A number that is only divisible by itself and 1
- Program process:
- - At first this program takes the number from user say n
- - It is sent to the function which takes an integer parameter and returns integer that is assigned to int variable
- - In that function a for loop is initialised from 2 and iters till n/2
- - It checks if that given number divisible by any of numbers between that range (2,n/2)
- - If noting divisibles it returns 0 that means it is prime number otherwise it is not which returns 1
- Input | Output
- 12    | It is not a Prime number
- 31    | It is a Prime number
*/
#include<stdio.h>
int is_prime(int n){
	int i;
	for(i=2;i<=(n/2);i++){
		if(n%i==0){
			return 1;
		}
	}
	return 0;
}
void main(){
	int n;
	printf("Give a number to check if it is a prime number");
	scanf("%d",&n);
	int p=is_prime(n);
	if(p==0){
		printf("It is Prime number");
	}
	else{
		printf("It is not a Prime number");
	}
}

