#include<stdio.h>
int main()
{
int n,reversed=0,remainder,original;
printf("Enter an integer: ");
scanf("%d",&n);
original = n;
//Reversed integer is stored in reverse variable
while(n!=0)
{
  remainder = n%10;
  reversed = reversed * 10 + remainder;
  n/=10;
}
//palindrome if original and reversed are equal
if(original == reversed)
printf("%d is a Palindrome");
else
printf("%d is not a palindrome");
return 0; 
}